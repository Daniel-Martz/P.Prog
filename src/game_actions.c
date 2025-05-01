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
#include <strings.h>

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
 * @brief It allows the player to recruit a friendly character
 * @author Jorge Martín
 * 
 * @param game a pointer to Game
 * @return Status indicating the result of the action
 */
Status game_actions_recruit(Game *game);

/**
 * @brief It allows the player to abandon a friendly character
 * @author Jorge Martín
 * 
 * @param game a pointer to Game
 * @return Status indicating the result of the action
 */
Status game_actions_abandon(Game *game);

/**
 * @brief It allows the player to open a link with an object
 * @author Jorge Martín
 * 
 * @param game a pointer to Game
 * @return Status indicating the result of the action
 */
Status game_actions_open(Game *game);

/**
 * @brief It allows the player to use an object
 * @author Daniel Martínez
 * 
 * @param game a pointer to Game
 * @return Status indicating the result of the action
 */
Status game_actions_use(Game *game);



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
      command_set_last_cmd_status(game_get_last_command(game), game_actions_unknown(game));
      break;

    case EXIT:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_exit(game));
      break;

    case MOVE:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_move(game));
      break;
    
    case INSPECT:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_inspect(game));
      break;
      
    case TAKE:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_take(game));
      break;
    
    case DROP:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_drop(game));
      break;

    case ATTACK:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_attack(game));
      break;

    case CHAT:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_chat(game));
      break;

    case RECRUIT:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_recruit(game));
      break;

    case ABANDON:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_abandon(game));
      break;

    case OPEN:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_open(game));
      break;

    case USE:
    command_set_last_cmd_status(game_get_last_command(game), game_actions_use(game));
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
  Character **characters = NULL;
  int i=0;

  if(!game) return ERROR;

  command_set_strin(game_get_last_command(game), "");
  game_set_message(game, "");

  if ((direction = command_get_direction(game_get_last_command(game))) == U) {
    return ERROR;
  }

  space_id = game_get_player_location(game);

  if (game_connection_is_open(game, space_id, direction)==TRUE) {
    current_id = game_get_connection(game, space_id, direction);
    if (current_id != NO_ID) {
      /*Mover al jugador*/
      game_set_player_location(game, current_id);

      /*Mover a los personajes que le están siguiendo*/
      characters = game_get_characters(game);
      for(i=0; i<game_get_ncharacters(game); i++){
        if(character_get_following(characters[i]) == player_get_id(game_get_player(game))){
           game_set_character_location(game, current_id, character_get_id(characters[i]));
        }
      }
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

  if(!(objname = command_get_strin(game_get_last_command(game)))){
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

  if(!(objname = command_get_strin(game_get_last_command(game)))){
    return ERROR;
  }
  /* Take the player*/
  if(!(player = game_get_player(game))) return ERROR;

  player_location = game_get_player_location(game);/* Initializate player_location*/
  if(player_location == NO_ID){
    return ERROR;
  }

  /* We get the object id from the name*/
  if((object = game_get_object_from_name(game, objname)) == NO_ID)
  {
    return ERROR;
  }

  /*check if the object is in the inventory*/
  if (inventory_object_is_there(player_get_backpack(player), object) == OK)
  {
    return ERROR;
  }

  /*check if the object is movable*/
  if (object_is_movable(game_get_object(game, object)) == FALSE)
  {
    return ERROR;
  }

  /*Check if the object depends on other object*/
  if ((inventory_object_is_there(player_get_backpack(player), object_get_dependency(game_get_object(game, object)))) == ERROR)
  {
    return ERROR;
  }
  
  
  /* object location and player location must be the same*/
  if(game_get_object_location(game, object) != player_location){
    return ERROR;
  }

  if(inventory_add_obj_id(player_get_backpack(player), object) == ERROR){
    return ERROR;
  }

  if (!(player_set_health(player, player_get_health(player) + object_get_health(game_get_object(game, object)))))
  {
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

  if(!(objname = command_get_strin(game_get_last_command(game)))){
    return ERROR;
  }

  if (inventory_get_n_objs(player_get_backpack(game_get_player(game))) <= 0){
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
  int turn = -1, turn2 = -1, following = 0, i=0;
  Id player_location = NO_ID;
  Character *character = NULL, **characters = NULL;

  if(!game) return ERROR;
  command_set_direction(game_get_last_command(game), U);
  game_set_message(game, "");

  if((player_location = game_get_player_location(game)) == NO_ID) return ERROR;

  character = game_get_character_from_name(game, command_get_strin(game_get_last_command(game)));
  if(character == NULL) return ERROR;
  if(character_get_friendly(character) == TRUE) return ERROR;
  if(character_get_health(character) <= 0) return ERROR;
  if(game_get_character_location(game, character_get_id(character)) != player_location) return ERROR;

  turn = rand()%10;
  if((turn<0)||turn>9) return ERROR;
  if(turn<5){
    /* If the attacking player loses a new random variable determines who loses a hitpoint (it goes from 0 up to the number of following characters)*/
    following = game_get_nfollowingcharacters(game, player_get_id(game_get_player(game)));
    if (following < 0) {
      return ERROR;
    }
    turn2 = rand()%following;
    /* If the random number is 0 (will always be if the player has no following characters) the player loses a hitpoint */
    if (turn2 == 0) {
      player_set_health(game_get_player(game), player_get_health(game_get_player(game))-1);
    }
    /* If the random number is not 0 (lets say is X) the X character that follows the player (in the order of the game X=1 first, X=2 second, etc) will lose a hitpoint */
    else {
      characters = game_get_followingcharacters(game, player_get_id(game_get_player(game)));
      if (characters == NULL) {
        return ERROR;
      }
      character_set_health(characters[turn2 - 1], (character_get_health(characters[turn2 - 1])-1));
      for (i=0; i<game_get_ncharacters(game); i++){
        if (character_get_health(characters[i]) <= 0) {
          character_set_following(characters[i], NO_ID);
        }
      }
      free(characters);
    }
  }
  else {
    /* If the attacking player wins the attacked charcater loses a hitpoint*/
    if ((character_get_health(character)-(game_get_nfollowingcharacters(game, player_get_id(game_get_player(game)))+1)) <= 0) {
      character_set_health(character, 0);
    }
    else {
    character_set_health(character, character_get_health(character)-(game_get_nfollowingcharacters(game, player_get_id(game_get_player(game)))+1));
    }
  }
  if(player_get_health(game_get_player(game))<=0){
    game_set_finished(game, TRUE);
    return OK;
  }
  return OK;
}

Status game_actions_chat(Game *game) {
  Id *characters = NULL, character = NO_ID;
  int i;
  Id player_location = NO_ID;
  if(!game) return ERROR;
  command_set_direction(game_get_last_command(game), U);

  if((player_location = game_get_player_location(game)) == NO_ID) return ERROR;

  if(!(characters = space_get_characters_ids(game_get_space(game, player_location)))) return ERROR;

  for(i = 0; i < space_get_ncharacters(game_get_space(game, player_location)); i ++){
    if(!strcmp(character_get_name(game_get_character(game, characters[i])), command_get_strin(game_get_last_command(game)))){
      character = characters[i];
      break;
    }
  }

  if((character == NO_ID) || (character_get_friendly(game_get_character(game,character)) == FALSE)) return ERROR; 
  
  game_set_message(game,character_get_message(game_get_character(game, character)));

  return OK;
}

Status game_actions_recruit(Game *game) {
  Character *character = NULL;
  char *character_name = NULL;


  if (!game) return ERROR;
  command_set_direction(game_get_last_command(game), U);
  game_set_message(game, "");

  if (!(character_name = command_get_strin(game_get_last_command(game)))) {
    return ERROR;
  }

  if (!(character = game_get_character_from_name(game, character_name))) {
    return ERROR;
  }

  /*Checks if the character is friendly*/
  if (character_get_friendly(character) == FALSE) {
    return ERROR;
  }

  /*Checks if the character is dead*/
  if (character_get_health(character) <= 0) {
    return ERROR;
  }

  /*Checks if the character is in the same location as the player*/
  if (game_get_character_location(game, character_get_id(character)) != game_get_player_location(game)) {
    return ERROR;
  }

  /*Checks if the character is already following another player*/
  if (character_get_following(character) != NO_ID) {
    return ERROR;
  }

  if (character_set_following(character, player_get_id(game_get_player(game))) == ERROR) {
    return ERROR;
  }

  return OK;
}

Status game_actions_abandon(Game *game) {
  Character *character = NULL;
  char *character_name = NULL;


  if (!game) return ERROR;
  command_set_direction(game_get_last_command(game), U);
  game_set_message(game, "");

  if (!(character_name = command_get_strin(game_get_last_command(game)))) {
    return ERROR;
  }

  if (!(character = game_get_character_from_name(game, character_name))) {
    return ERROR;
  }

    /*Checks if the character is friendly*/
    if (character_get_friendly(character) == FALSE) {
      return ERROR;
    }
  
    /*Checks if the character is following the player*/
    if (character_get_following(character) != player_get_id(game_get_player(game))) {
      return ERROR;
    }
    else {
      if (character_set_following(character, NO_ID) == ERROR) {
        return ERROR;
      }
      return OK;
    }
}

Status game_actions_open(Game *game) {
  Object *object = NULL;
  Link **links = NULL, *link = NULL;
  int i = 0;

  if(!game) return ERROR;
  command_set_direction(game_get_last_command(game), U);
  game_set_message(game, "");

  object = game_get_object(game, game_get_object_from_name(game, command_get_strin(game_get_last_command(game))));
  if(object == NULL) return ERROR;

  if(object_get_open(object) == NO_ID) return ERROR;

  links = game_get_links(game);

  for (i = 0; i < game_get_nlinks(game); i++) {
    if (link_get_id(links[i]) == object_get_open(object)) {
      link = links[i];
      break;
    }
  }

  if (link == NULL) return ERROR;
  
  if (link_get_open(link) == TRUE) {
    return ERROR;
  }

  if (link_get_origin(link) == game_get_player_location(game) ||
  link_get_destination(link) == game_get_player_location(game)) {
  link_set_open(link, TRUE);
}
  else {
    return ERROR;
  }

  return OK;
}

Status game_actions_use(Game *game) {

  Object *object = NULL;


  if(!game) return ERROR;
  command_set_direction(game_get_last_command(game), U);
  game_set_message(game, "");

  object = game_get_object(game, game_get_object_from_name(game, command_get_strin(game_get_last_command(game))));
  if(object == NULL) return ERROR;

  if(object_get_health(object) == 0) {
    return ERROR;
  }
  else {
    if (player_get_health(game_get_player(game)) + object_get_health(object) <= 0) {
      player_set_health(game_get_player(game), 0);
    }
    else {
      player_set_health(game_get_player(game), player_get_health(game_get_player(game)) + object_get_health(object));
    }
  }

  return OK;
}
