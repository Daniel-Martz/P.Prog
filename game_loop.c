/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Jaime Romero
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "command.h"
#include "game.h"
#include "game_actions.h"
#include "graphic_engine.h"
#include "game_reader.h"
#include "types.h"

#define CMD_LENGHT 30 /* It denotes the length needed for the string that stores the introduced command */

/**
 * @brief It initialices the game and the graphic engine controlling the errors (printing the reason of the failure)
 * @author Jaime Romero
 *
 * @param game a pointer to game
 * @param gengine a double pointer to the graphic engine
 * @param file_name a string with the name of the file
 * @param log_status a boolean that indicates if the log is active or not
 *
 * @return 1 if everything was good and 0 if not
 */
int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name, Bool log_status);

/**
 * @brief It initiates the graphic engine and do the action of the last command selected. It will keep on going (nothing will change) until it recives the next command.
 * It won´t stop until the command introduced says so or the game finishes
 * @author Jaime Romero
 *
 * @param game A pointer to Game
 * @param engine A pointer to the grafic engine
 * @param log_status a boolean that indicates if the log is active or not
 * @param log_name a string with the name of the log input file
 * @param output_name a string with the name of the log output file
 *
 * @return void (nothing)
 */
void game_loop_run(Game *game, Graphic_engine *gengine, Bool log_status, char *log_name, char *output_name);

/**
 * @brief It destroys the game and the graphic engine
 * @author Jaime Romero
 *
 * @param game A pointer to Game
 * @param gengine A pointer to the grafic engine
 * @return void (nothing)
 */
void game_loop_cleanup(Game *game, Graphic_engine *gengine);

/**
 * @brief Checks if the user has provided a game data file and initializes it
 * @author Daniel Martínez
 *
 * @param argc It refers to the number of arguments passed to the program
 * @param argv An array of strings with the aruments
 * @return 1 if everything was correct and 0 if not
 */
int main(int argc, char *argv[])
{
  Game *game = NULL;
  Graphic_engine *gengine;
  Bool log_status = FALSE;

  srand(time(NULL));

  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  if (argc > 2)
  {
    if (!strcmp(argv[2], "-l"))
    {
      if ((argc < 2) || (argc > 6))
      {
        fprintf(stderr, "Use: %s %s %s que se desea insert<output_file> - <log_file>\n", argv[0], argv[1], argv[2]);
        return 1;
      }
      log_status = TRUE;
    }
    else
    {
      fprintf(stderr, "To use the log option use: %s %s -l <output_file> - <log_file>\n", argv[0], argv[1]);
      return 1;
    }
  }

  if (game_loop_init(&game, &gengine, argv[1], log_status) == 0)
  {
    if (log_status == TRUE)
    {
      game_loop_run(game, gengine, log_status, argv[5], argv[3]);
    }
    else
    {
      game_loop_run(game, gengine, log_status, NULL, NULL);
    }
    game_loop_cleanup(game, gengine);
  }

  return 0;
}

int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name, Bool log_status)
{
  if (!(*game = game_create_from_file(file_name)))
  {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if (log_status == FALSE)
  {
    if ((*gengine = graphic_engine_create()) == NULL)
    {
      fprintf(stderr, "Error while initializing graphic engine.\n");
      game_destroy(*game);
      return 1;
    }
  }
  else
  {
    *gengine = NULL;
  }

  return 0;
}

void game_loop_run(Game *game, Graphic_engine *gengine, Bool log_status, char *log_name, char *output_name)
{
  Command *last_cmd;
  FILE *log_file = NULL;
  FILE *log_output = NULL;
  char command[CMD_LENGHT];
  extern char *cmd_to_str[N_CMD][N_CMDT];
  Status st;
  int i;

  if (log_status == FALSE)
  {
    if (!gengine || !game)
    {
      return;
    }
  }

  if (log_status == TRUE)
  {
    if (!game)
    {
      return;
    }
  }
  if (log_status == TRUE)
  {
    if (!(log_file = fopen(log_name, "r")))
    {
      fprintf(stderr, "Error while opening the log file");
      return;
    }
    if (!(log_output = fopen(output_name, "w")))
    {
      fprintf(stderr, "Error while creating the log output");
      return;
    }
  }
  last_cmd = game_get_last_command(game);

  while ((command_get_code(last_cmd) != EXIT) && (game_get_finished(game) == FALSE))
  {
    if (log_status == FALSE)
    {
      graphic_engine_paint_game(gengine, game);
      command_get_user_input(last_cmd);
    }
    if (log_status == TRUE)
    {
      fgets(command, CMD_LENGHT, log_file);
      command_get_input_from_string(last_cmd, command);
    }
    game_actions_update(game, last_cmd);
    st = command_get_last_cmd_status(game_get_last_command(game));
    if (log_status == TRUE)
    {
      for (i = 0; i < N_CMD - 1; i++)
      {
        if (command_get_code(last_cmd) == i)
        {
          fprintf(log_output, "%s ", cmd_to_str[i + 1][CMDL]);
        }
      }
      if (st == OK)
      {
        fprintf(log_output, "OK\n");
      }
      if (st == ERROR)
      {
        fprintf(log_output, "ERROR\n");
      }
    }

    if (game_get_nplayers(game) > 1)
    {
      if (log_status == FALSE)
      {
        graphic_engine_paint_game(gengine, game);
        if (command_get_code(last_cmd) == EXIT) {
          game_set_finished(game, TRUE);
          break;
        }
        game_next_turn(game);
        game_set_last_command(game, NULL);
        sleep(2);
      }
      if (log_status == TRUE)
      {
        if (command_get_code(last_cmd) == EXIT) {
          game_set_finished(game, TRUE);
          break;
        }
        game_next_turn(game);
      }
    }
  }

  if ((game_get_finished(game) == TRUE) || (player_get_health(game_get_player(game)) == 0))
  {
    if (log_status == FALSE)
    {
      graphic_engine_paint_game(gengine, game);
      printf("GAME OVER\n");
    }
    if (log_status == TRUE)
    {
      fprintf(log_output, "GAME OVER\n");
      fclose(log_file);
      fclose(log_output);
    }
  }
  else
  {
    if (log_status == TRUE)
    {
      fprintf(log_output, "GAME OVER2\n");
      fclose(log_file);
      fclose(log_output);
    }
  }
}

void game_loop_cleanup(Game *game, Graphic_engine *gengine)
{
  game_destroy(game);
  graphic_engine_destroy(gengine);
}

/*  valgrind --leak-check=full --show-leak-kinds=all ./proyecto anthill.dat   */
/*  valgrind --leak-check=full --show-leak-kinds=all ./proyecto anthill.dat -l output.txt - log_input.txt   */
