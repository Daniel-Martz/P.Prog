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

#include "command.h"
#include "game.h"
#include "game_actions.h"
#include "graphic_engine.h"
#include "game_reader.h"

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
 * @param engine A pointer to the grafic engine
 * 
 * @return void (nothing)
 */
void game_loop_run(Game *game, Graphic_engine *gengine);

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
int main(int argc, char *argv[]) {
  Game *game = NULL;
  Graphic_engine *gengine;

  if (argc < 2) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  if (game_loop_init(&game, &gengine, argv[1]) == 0) {
    game_loop_run(game, gengine);
    game_loop_cleanup(game, gengine);
  }

  return 0;
}

int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name) {
  if (!(*game = game_create_from_file(file_name))) {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL) {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(*game);
    return 1;
  }

  return 0;
}

void game_loop_run(Game *game, Graphic_engine *gengine) {
  Command *last_cmd;

  if (!gengine || !game) {
    return;
  }

  last_cmd=game_get_last_command(game);
  
  while ((command_get_code(last_cmd) != EXIT) && (game_get_finished(game) == FALSE)) {
    graphic_engine_paint_game(gengine, game);
    command_get_user_input(last_cmd);
    game_actions_update(game, last_cmd);
  }

  if ((game_get_finished(game)==TRUE) && (player_get_health(game_get_player(game)) == 0))
  {
    graphic_engine_paint_game(gengine, game);
    printf("GAME OVER");
  }
  
}

void game_loop_cleanup(Game *game, Graphic_engine *gengine) {
  game_destroy(game);
  graphic_engine_destroy(gengine);
}
