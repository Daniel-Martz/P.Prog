/**
 * @brief It implements the game update through user actions
 *
 * @file game_actions.c
 * @author Daniel Martinez
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game_actions.h"
#include "inventory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
   Private functions
*/

/**
 * @brief It is used for unknown commands and it does nothing
 * 
 * @author Jaime Romero
 * @param game a pointer to game
 * @return Status indicating the result of the action
 */
Status game_actions_unknown(Game *game);

/**
 * @brief It exits the game
 * 
 * @author Jaime Romero
 * @param game a pointer to game
 * @return Status indicating the result of the action
 */
Status game_actions_exit(Game *game);

/**
 * @brief It checks that the player is in a valid location and then changes the location to the space in the command direction if valid
 * @author Jorge Martín
 * 
 * @param game a pointer to Game
 * @return Status indicating the result of the action
 */
Status game_actions_move(Game *game);

/**
 * @brief It allows the player to inspect an object in the inventory or in the space
 * @author Daniel Martínez
 * 
 * @param game a pointer to Game
 * @return Status indicating the result of the action
 */
Status game_actions_inspect(Game *game);

/**
 * @brief It takes an object from a certain location
 * @author Daniel Martínez
 * 
 * @param game a pointer to Game
 * @return Status indicating the result of the action
 */
Status game_actions_take(Game *game);

/**
 * @brief It drops the object previously taken
 * @author Daniel Martínez
 * 
 * @param game a pointer to Game
 * @return Status indicating the result of the action
 */
Status game_actions_drop(Game *game);

/**
 * @brief It attacks an enemy
 * @author Daniel Martínez
 * 
 * @param game a pointer to Game
 * @return Status indicating the result of the action
 */
Status game_actions_attack(Game *game);

/**
 * @brief It allows the player to chat with a friendly character
 * @author Daniel Martínez
 * 
 * @param game a pointer to Game
 * @return Status indicating the result of the action
 */
Status game_actions_chat(Game *game);



/**
 * @brief Game actions implementation
 */


/**
   Game actions implementation
*/

Status game_actions_update(Game *game, Command *command) {
  CommandCode cmd;

  game_set_last_command(game, command);

  cmd = command_get_code(command);

  switch (cmd) {
    case UNKNOWN:
      game_set_last_cmd_status(game, game_actions_unknown(game));
      break;

    case EXIT:
    game_set_last_cmd_status(game, game_actions_exit(game));
      break;

    case MOVE:
    game_set_last_cmd_status(game, game_actions_move(game));
      break;
    
    case INSPECT:
    game_set_last_cmd_status(game, game_actions_inspect(game));
      break;
      
    case TAKE:
    game_set_last_cmd_status(game, game_actions_take(game));
      break;
    
    case DROP:
    game_set_last_cmd_status(game, game_actions_drop(game));
      break;

    case ATTACK:
    game_set_last_cmd_status(game, game_actions_attack(game));
      break;

    case CHAT:
    game_set_last_cmd_status(game, game_actions_chat(game));
      break;

    default:
      break;
  }

  return OK;
}

/**
   Calls implementation for each action
*/

Status game_actions_unknown(Game *game) {
  return OK;
}

Status game_actions_exit(Game *game) {
  return OK;
}

Status game_actions_move(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Direction direction;

  if(!game) return ERROR;

  command_set_objname(game_get_last_command(game), "");
  game_set_message(game, "");

  if ((direction = command_get_direction(game_get_last_command(game))) == U) {
    return ERROR;
  }

  space_id = game_get_player_location(game);

  if (game_connection_is_open(game, space_id, direction)==TRUE) {
    current_id = game_get_connection(game, space_id, direction);
    if (current_id != NO_ID) {
      game_set_player_location(game, current_id);
    }
    else {
      return ERROR;
    }
  }
  else {
    return ERROR;
  }
  return OK;
}

Status game_actions_inspect(Game *game){

  Id player_location = NO_ID, *ids_aux = NULL;
  char *objname = NULL;
  int i;
  
  if(!game){
    return ERROR;
  }
  command_set_direction(game_get_last_command(game), U);
  game_set_message(game, "");

  if(!(objname = command_get_objname(game_get_last_command(game)))){
    return ERROR;
  }

  if((player_location = game_get_player_location(game)) == NO_ID){
    return ERROR;
  }

  if(!(ids_aux = space_get_objects_ids(game_get_space(game, player_location)))){
    return ERROR;
  }

  for(i = 0; i < space_get_nobjects(game_get_space(game, player_location)); i++){
    if(!(strcmp(object_get_name(game_get_object(game, ids_aux[i])), objname))){
      return game_set_message(game, object_get_description(game_get_object(game, ids_aux[i])));      
    }
  }

  if(!(ids_aux = inventory_get_obj_ids(player_get_backpack(game_get_player(game))))){
    return ERROR;
  }

  for(i = 0; i < inventory_get_n_objs(player_get_backpack(game_get_player(game))); i++){
    if(!(strcasecmp(object_get_name(game_get_object(game, ids_aux[i])), objname))){
      return game_set_message(game, object_get_description(game_get_object(game, ids_aux[i])));
    }
  }

  return ERROR;
}

Status game_actions_take(Game *game){
  Id player_location = NO_ID;
  Id object;
  Player *player = NULL;
  char *objname = NULL;

  if(!game) return ERROR;
  command_set_direction(game_get_last_command(game), U);
  game_set_message(game, "");

  if(!(objname = command_get_objname(game_get_last_command(game)))){
    return ERROR;
  }
  /* Take the player*/
  if(!(player = game_get_player(game))) return ERROR;
  /* Make sure that the player has no objects*/

  player_location = game_get_player_location(game);/* Initializate player_location*/
  if(player_location == NO_ID){
    return ERROR;
  }

  /* We get the object id from the name*/
  if((object = game_get_object_from_name(game, objname)) == NO_ID){
    return ERROR;
  }
  /* object location and player location must be the same*/
  if(game_get_object_location(game, object) != player_location){
    return ERROR;
  }

  if(inventory_add_obj_id(player_get_backpack(player), object) == ERROR){
    return ERROR;
  }

  return space_object_del(game_get_space(game, player_location), object); /*Delete the object from the sapce*/
}

Status game_actions_drop(Game *game){
  Id player_location = NO_ID;
  Id object_id = NO_ID, *objsinvent = NULL;
  Space *current_space = NULL;
  Player *player = NULL;
  int i;
  char *objname = NULL;
  
  if(!game) return ERROR;
  if(!(player = game_get_player(game))) return ERROR;

  command_set_direction(game_get_last_command(game), U);
  game_set_message(game, "");

  if(!(objsinvent = player_get_objects_ids(player))){
    return ERROR;
  }

  if(!(objname = command_get_objname(game_get_last_command(game)))){
    return ERROR;
  }

  for(i=0; i<inventory_get_n_objs(player_get_backpack(game_get_player(game))); i++){
    if(!(strcasecmp(objname, object_get_name(game_get_object(game,objsinvent[i]))))){
      object_id = objsinvent[i];
      break;
    }
  }

  if(object_id == NO_ID) return ERROR;

  player_location = game_get_player_location(game);
  if(player_location == NO_ID){
    return ERROR;
  }

  if(!(current_space = game_get_space(game, player_location))){
    return ERROR;
  }

  space_set_new_object(current_space, object_id);
  inventory_delete_obj_id(player_get_backpack(game_get_player(game)), object_id);
  return OK;   
}

Status game_actions_attack(Game *game) {
  int turn = -1;
  Id character = NO_ID;
  Id player_location = NO_ID;

  if(!game) return ERROR;
  command_set_direction(game_get_last_command(game), U);
  command_set_objname(game_get_last_command(game), "");
  game_set_message(game, "");

  if((player_location = game_get_player_location(game)) == NO_ID) return ERROR;

  character = space_get_character(game_get_space(game, player_location));

  if(character == NO_ID || character_get_friendly(game_get_character(game, character)) == TRUE) return ERROR;

  /* If one of them has no health*/
  if(!((player_get_health(game_get_player(game))>0) && (character_get_health(game_get_character(game, character))>0))) return ERROR; 

  srand(time(NULL));

  turn = rand()%10;
  if((turn<0)||turn>9) return ERROR;
  if(turn<5){
    player_set_health(game_get_player(game), player_get_health(game_get_player(game))-1);
  }
  else
    character_set_health(game_get_character(game, character),character_get_health(game_get_character(game, character))-1);
  
  if(player_get_health(game_get_player(game))<=0){
    game_set_finished(game, TRUE);
    return OK;
  }
  return OK;
}

Status game_actions_chat(Game *game) {
  Id character = NO_ID;
  Id player_location = NO_ID;
  if(!game) return ERROR;
  command_set_direction(game_get_last_command(game), U);
  command_set_objname(game_get_last_command(game), "");

  if((player_location = game_get_player_location(game)) == NO_ID) return ERROR;

  character = space_get_character(game_get_space(game, player_location));

  if((character == NO_ID) || (character_get_friendly(game_get_character(game,character)) == FALSE)) return ERROR; 
  
  game_set_message(game,character_get_message(game_get_character(game, character)));

  return OK;
}

