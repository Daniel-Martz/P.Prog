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
#include "game_management.h"
#include "game_rules.h"
#include "types.h"

#define CMD_LENGHT 30 /*!< It denotes the length needed for the string that stores the introduced command */

/**
 * @brief It initialices the game and the graphic engine controlling the errors (printing the reason of the failure)
 * @author Jaime Romero
 *
 * @param game a pointer to game
 * @param gengine a double pointer to the graphic engine
 * @param file_name a string with the name of the file
 *
 * @return 1 if everything was good and 0 if not
 */
int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name);

/**
 * @brief It initiates the graphic engine and do the action of the last command selected. It will keep on going (nothing will change) until it recives the next command.
 * It won´t stop until the command introduced says so or the game finishes
 * @author Jaime Romero
 *
 * @param game A pointer to Game
 * @param gengine A pointer to the grafic engine
 * @param output_name a string with the name of the log output file
 */
void game_loop_run(Game *game, Graphic_engine *gengine, char *output_name);

/**
 * @brief It destroys the game and the graphic engine
 * @author Jaime Romero
 *
 * @param game A pointer to Game
 * @param gengine A pointer to the grafic engine
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
  char *output_file = NULL;

  srand(time(NULL));

  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  if (game_loop_init(&game, &gengine, argv[1]) == 0)
  {

    if (argc == 3)
    {
      if (!strcmp(argv[2], "-d"))
      {
        game_set_determinist_status(game, TRUE);
      }
      else
      {
        fprintf(stderr, "To use determinist option use: %s %s -d \n", argv[0], argv[1]);
        return 1;
      }
    }

    if (argc > 3)
    {
      if ((!strcmp(argv[2], "-l")) || (!strcmp(argv[3], "-l")))
      {
        if ((!strcmp(argv[2], "-d")) || (!strcmp(argv[3], "-d")))
        {
          if ((argc != 5))
          {
            fprintf(stderr, "To use the log and determinist option use: %s %s -l -d <log_file>\n", argv[0], argv[1]);
            return 1;
          }
          else
          {
            output_file = argv[4];
          }
          game_set_log_status(game, TRUE);
          game_set_determinist_status(game, TRUE);
        }
        else
        {
          if ((argc != 4))
          {
            fprintf(stderr, "To use the log option use: %s %s -l <log_file>\n", argv[0], argv[1]);
            return 1;
          }
          else
          {
            output_file = argv[3];
          }
          game_set_log_status(game, TRUE);
        }
      }
      else
      {
        fprintf(stderr, "To use the log option use: %s %s -l <log_file>\n", argv[0], argv[1]);
        return 1;
      }
    }
  }

  game_loop_run(game, gengine, output_file);
  game_loop_cleanup(game, gengine);
  return 0;
}

int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name)
{
  if (!(*game = game_create_from_file(file_name)))
  {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL)
  {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(*game);
    return 1;
  }

  return 0;
}

void game_loop_run(Game *game, Graphic_engine *gengine, char *output_name)
{
  Command *last_cmd;
  FILE *log_output = NULL;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  Status st;
  int i;

  if (!gengine || !game)
  {
    return;
  }

  if (game_get_log_status(game) == TRUE)
  {
    if (!(log_output = fopen(output_name, "w")))
    {
      fprintf(stderr, "Error while creating the log output");
      return;
    }
  }
  last_cmd = game_get_last_command(game);

  while ((command_get_code(last_cmd) != EXIT) && (game_get_finished(game) == FALSE))
  {
    graphic_engine_paint_game(gengine, game);
    command_get_user_input(last_cmd);

    game_actions_update(game, last_cmd);
    st = command_get_last_cmd_status(game_get_last_command(game));
    if (game_get_log_status(game) == TRUE)
    {
      for (i = 0; i < N_CMD - 1; i++)
      {
        if (command_get_code(last_cmd) == i)
        {
          fprintf(log_output, "%s ", cmd_to_str[i + 1][CMDL]);
          break;
        }
      }
      if (st == OK)
      {
        fprintf(log_output, "OK ");
      }
      if (st == ERROR)
      {
        fprintf(log_output, "ERROR ");
      }
      fprintf(log_output, "(P%i)\n", ((int)player_get_id(game_get_player(game))));
    }
    graphic_engine_clear_face(gengine);
    graphic_engine_paint_game(gengine, game);
    if (command_get_code(last_cmd) == EXIT)
    {
      game_set_finished(game, TRUE);
      break;
    }
    game_rules_run_all(game);
    game_set_last_command(game, NULL);
    sleep(0.5);
  }


  if ((game_get_finished(game) == TRUE) || (player_get_health(game_get_player(game)) == 0))
  {
    printf("GAME OVER\n");

    if (game_get_log_status(game) == TRUE)
    {
      fprintf(log_output, "GAME OVER\n");
      fclose(log_output);
    }
  }
  else
  {
    if (game_get_log_status(game) == TRUE)
    {
      fprintf(log_output, "GAME OVER\n");
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
