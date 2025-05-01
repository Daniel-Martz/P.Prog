/**
 * @brief It implements the game structure
 *
 * @file game.c
 * @author Jaime Romero, Daniel Martínez
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game.h"
#include "game_management.h"
#include "character.h"
#include "link.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_ID 1/*!< Constant that refers to the starting id of a player and object */

/**
* @brief This struct stores all the information of the game
*
* @author Jaime Romero
*/
struct _Game {
  Player *players[MAX_PLAYERS]; /*!< An array of players */
  Object *objects[MAX_OBJECTS]; /*!< Information of the objects*/
  Space *spaces[MAX_SPACES]; /*!< *an array of all the sapces of the game*/
  int n_spaces; /*!< Number of spaces that the game has */
  int n_objects; /*!< Number of objects that the game has */
  int n_characters; /*!< Number of characters that the game has */
  int n_links; /*!< Number of links that the game has */
  int n_players; /*!< Number of players that the game has */
  int turn; /*!< Integrer defining the player's turn */
  Command *last_cmd; /*!< It stores the last command called */
  Bool finished; /*!< It defines if the game finished or not */
  Character *characters[MAX_CHARACTERS]; /*!< It contains all the characters of the game*/
  char message[MAX_MESSAGE]; /*!< It contains the message of the chat*/
  char *missions[MAX_MESSAGE]; /*!< It contains the message for the missions*/
  Link *links[MAX_LINKS]; /*!< It contains all the links of the game*/
  Bool log_status; /*!< It defines if the log is active or not */
  Bool determinst_status; /*!< It defines if the game is deterministic or not */
};

Game *game_create(void){
  int i;
  Game *game = NULL;

  if(!(game = (Game*)calloc(1,sizeof(Game)))){
    return NULL;
  }

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }
  
  for (i = 0; i < MAX_OBJECTS; i++) {
    game->objects[i] = NULL;
  }
  
  for (i = 0; i < MAX_CHARACTERS; i++) {
    game->characters[i] = NULL;
  }

  for (i = 0; i < MAX_LINKS; i++) {
    game->links[i] = NULL;
  }

  for (i = 0; i < MAX_PLAYERS; i++) {
    game->players[i] = NULL;
  }
  
  game->message[0] = '\0';

  game->n_spaces = 0;
  game->n_objects = 0;
  game->n_characters = 0;
  game->n_links = 0;
  game->n_players = 0;
  game->turn = 0;
  game->last_cmd = command_create();
  game->finished = FALSE;
  game->log_status = FALSE;
  game->determinst_status = FALSE;



  if (!game->last_cmd) {
    return NULL;
  }

  return game;
}

Status game_add_space(Game *game, Space *space) {
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES)) {
    return ERROR;
  }

  game->spaces[game->n_spaces] = space;
  game->n_spaces++;

  return OK;
}

Status game_add_object(Game *game, Object *object) {
  if ((object == NULL) || (game->n_objects >= MAX_OBJECTS)) {
    return ERROR;
  }

  game->objects[game->n_objects] = object;
  game->n_objects++;

  return OK;
}

Status game_add_character(Game *game, Character *character) {
  if ((character == NULL) || (game->n_characters >= MAX_CHARACTERS)) {
    return ERROR;
  }

  game->characters[game->n_characters] = character;
  game->n_characters++;

  return OK;
}

Status game_add_link(Game *game, Link* link) {
  if ((game==NULL) || (link == NULL) || (game->n_links >= MAX_LINKS)) {
    return ERROR;
  }

  game->links[game->n_links] = link;
  game->n_links++;

  return OK;
} 

Status game_add_player(Game *game, Player* player){
  if (!game || !player || game->n_players >= MAX_PLAYERS) return ERROR;

  game->players[game->n_players] = player;
  game->n_players++;

  return OK;
}

Game *game_create_from_file(char *filename) {
  Game *game = NULL;

  if (!(game = game_create())) {
    return NULL;
  }
  game = game_management_load(filename);

  return game;
}


Status game_destroy(Game *game) {
  int i = 0;

  if (!game) return ERROR;

  for (i = 0; i < game->n_spaces; i++) {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; i < game->n_objects; i++) {
    object_destroy(game->objects[i]);
  }

  for (i = 0; i < game->n_characters; i++) {
    character_destroy(game->characters[i]);
  }

  for (i = 0; i < game->n_links; i++) {
    link_destroy(game->links[i]);
  }

  for (i = 0; i < game->n_players; i++) {
    player_destroy(game->players[i]);
  }

  command_destroy(game->last_cmd);

  free(game);
  

  return OK;
}

Space *game_get_space(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_spaces; i++) {
    if (id == space_get_id(game->spaces[i])) {
      return game->spaces[i];
    }
  }

  return NULL;
}


Object *game_get_object(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_objects; i++) {
    if (id == object_get_id(game->objects[i])) {
      return game->objects[i];
    }
  }

  return NULL;
}

Character *game_get_character(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_characters; i++) {
    if (id == character_get_id(game->characters[i])) {
      return game->characters[i];
    }
  }

  return NULL;
}

Character *game_get_character_from_name(Game *game, char *name) {
  int i = 0;

  if (name == NULL) {
    return NULL;
  }

  for (i = 0; i < game->n_characters; i++) {
    if (!strcmp(name, character_get_name(game->characters[i]))) {
      return game->characters[i];
    }
  }

  return NULL;
}

Player *game_get_player(Game *game){
  if(!game){
    return NULL;
  }
  
  return game->players[game_get_turn(game)];
}

Id game_get_player_location(Game *game) { return player_get_location (game->players[game_get_turn(game)]); }

char *game_get_message(Game *game){
  if(!game) return NULL;

  return game->message;
}

Status game_set_message(Game *game, const char *message){
  if(!game || !message){
    return ERROR;
  }

  if(!strcpy(game->message, message)){
    return ERROR;
  }
  return OK;
}

Status game_set_player_initial_location(Game *game, Id player_id, Id location) {
  int i;
  Space *space = NULL;

  if (!game || location == NO_ID || player_id == NO_ID) {
    return ERROR;
  }

  for (i = 0; i < game->n_players; i++) {
    if (player_id == player_get_id(game->players[i])) {
      player_set_location(game->players[i], location); 
      space = game_get_space(game, location);
      
      if (space_get_discovered(space) == FALSE) {
      space_set_discovered(space, TRUE);
      }
      return OK;
    }
  }

  return ERROR;
}

Status game_set_player_location(Game *game, Id location) {
  Space *space = NULL;
  if (!game || location == NO_ID) {
    return ERROR;
  }

  player_set_location(game->players[game_get_turn(game)], location); 
  space = game_get_space(game, location);
  
  if (space_get_discovered(space) == FALSE) {
  space_set_discovered(space, TRUE);
  }

  return OK;
}

Id game_get_object_location(Game *game, Id id){
  int i;
  
  if(id == NO_ID){
    return NO_ID;
  }

  for(i=0; i<game->n_spaces; i++){
    if(space_object_is_there(game->spaces[i],id) == OK){
      return space_get_id(game->spaces[i]);
    }
  }
  return NO_ID;
}

Object **game_get_objects_discovered(Game *game) {
int i, j, n = 0; 
Id space_id;
Object **objects_discovered;
  
if (!(game)) {
  return NULL;
}

objects_discovered = (Object **) malloc (game_get_n_objects_discovered(game) * sizeof(Object *));

if(objects_discovered == NULL) {
  return NULL;
}

for(i=0; i<game->n_objects;i++) {
  space_id = game_get_object_location(game, object_get_id(game->objects[i]));
  for(j=0; j<game->n_spaces; j++) {
    if(space_get_id(game->spaces[j]) == space_id) {
      if(space_get_discovered(game->spaces[j]) == TRUE) {
        objects_discovered[n] = game->objects[i];
        n++;
      }
      break;
    }
  }
}
return objects_discovered;
}

int game_get_n_objects_discovered(Game *game) {
int i, j, n = 0; 
Id space_id;
  
if (!(game)) {
  return POINT_ERROR;
}

for(i=0; i<game->n_objects;i++) {
  space_id = game_get_object_location(game, object_get_id(game->objects[i]));
  for(j=0; j<game->n_spaces; j++) {
    if(space_get_id(game->spaces[j]) == space_id) {
      if(space_get_discovered(game->spaces[j]) == TRUE) {
        n++;
      }
      break;
    }
  }
}
return n;
}

Character **game_get_characters_discovered(Game *game) {
int i, j, k = 0; 
Id space_id;
Character **characters_discovered;
  
if (!(game)) {
  return NULL;
}

characters_discovered = (Character **) malloc (game_get_n_characters_discovered(game) * sizeof(Character *));

if(characters_discovered == NULL) {
  return NULL;
}

for(i=0; i<game->n_characters;i++) {
  space_id = game_get_character_location(game, character_get_id(game->characters[i]));
  for(j=0; j<game->n_spaces; j++) {
    if(space_get_id(game->spaces[j]) == space_id) {
      if(space_get_discovered(game->spaces[j]) == TRUE) {
        characters_discovered[k] = game->characters[i];
        k++;
      }
      break;
    }
  }
}
return characters_discovered;
}

int game_get_n_characters_discovered(Game *game) {
int i, j, n = 0; 
Id space_id;
  
if (!(game)) {
  return POINT_ERROR;
}

for(i=0; i<game->n_characters;i++) {
  space_id = game_get_character_location(game, character_get_id(game->characters[i]));
  for(j=0; j<game->n_spaces; j++) {
    if(space_get_id(game->spaces[j]) == space_id) {
      if(space_get_discovered(game->spaces[j]) == TRUE) {
        n++;
      }
      break;
    }
  }
}
return n;
}

Id game_object_in_the_space(Game *game, Id space_id){
  int i;

  if(space_id == NO_ID) return NO_ID;

  for(i=0; i<game->n_objects; i++){
    if(space_id == game_get_object_location(game,object_get_id(game->objects[i]))){
      return object_get_id(game->objects[i]);
    }
  }
  return NO_ID;
}

Id game_get_character_location(Game *game, Id id){
  int i;
  
  if(id == NO_ID){
    return NO_ID;
  }

  for(i=0; i<game->n_spaces; i++){
    if(space_character_is_there(game->spaces[i],id) == OK){
      return space_get_id(game->spaces[i]);
    }
  }
  return NO_ID;
}

Status game_set_object_location(Game *game, Id space_id, Id object_id) {
  if (space_id == NO_ID || object_id == NO_ID) {
    return ERROR;
  }

  space_set_new_object(game_get_space(game, space_id),object_id);
  
  return OK;
}

Status game_set_character_location(Game *game, Id space_id, Id character_id){
  if (space_id == NO_ID || character_id == NO_ID) {
    return ERROR;
  }

  space_set_newCharacter(game_get_space(game,space_id),character_id);
  
  return OK;
}

Command* game_get_last_command(Game *game) { return game->last_cmd; }

Status game_set_last_command(Game *game, Command *command) {
  game->last_cmd = command;

  return OK;
}

Bool game_get_finished(Game *game) { return game->finished; }

Status game_set_finished(Game *game, Bool finished) {
  game->finished = finished;

  return OK;
}

Id game_get_object_from_name(Game *game, char *objname){
  int i;
  if(!objname || !game){
    return NO_ID;
  }

  for(i=0; i<game->n_objects; i++){
    if(!strcmp(object_get_name(game->objects[i]),objname)){
      return object_get_id(game->objects[i]);
    }
  }
  return NO_ID;
}

int game_get_nobjects(Game *game){
  if(!game){
  return NO_ID;
  }

  return game->n_objects;
}

Status game_set_nobjects(Game *game, int n_objects){
  if(!game || (n_objects < 0) || (n_objects > MAX_OBJECTS)){
    return ERROR;
  }

  game->n_objects = n_objects;
  return OK;
}

int game_get_ncharacters(Game *game){
  if(!game){
  return NO_ID;
  }

  return game->n_characters;
}

Status game_set_ncharacters(Game *game, int n_characters){
  if(!game || (n_characters < 0) || (n_characters > MAX_CHARACTERS)){
    return ERROR;
  }

  game->n_characters = n_characters;
  return OK;
}

int game_get_nplayers(Game *game){
  if(!game) return POINT_ERROR;
  return game->n_players;
}

Status game_set_nplayers(Game*game, int n_players){
  if(!game || n_players < 0 || n_players > MAX_CHARACTERS) return ERROR;

  game->n_players = n_players;
  return OK;
}

void game_print(Game *game) {
  int i = 0;


  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < game->n_spaces; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Objects locations:");
  for(i=0; i<game->n_objects; i++){
    printf("%d", (int)game_get_object_location(game,object_get_id(game->objects[i])));
  }
  printf("\n");

  printf("=> Characters locations:");
  for(i=0; i<game->n_characters; i++){
    printf("%d", (int)game_get_character_location(game,character_get_id(game->characters[i])));
  }
  printf("\n");

  printf("=> Player location: %d\n", (int)game_get_player_location(game));
}
Object **game_get_objects(Game *game){
  if(!game) return NULL;
  return game->objects;
}

Character **game_get_characters(Game *game){
  if(!game) return NULL;
  return game->characters;
}

Player **game_get_players(Game *game){
  if(!game) return NULL;
  return game->players;
}

/*Declaration of the function*/
Id game_get_player_space_id_at(Game *game, int position) {
  if (position < 0 || position >= game->n_spaces) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

int game_get_nlinks(Game *game){
  if(!game){
  return NO_ID;
  }

  return game->n_links;
}

Status game_set_nlinks(Game *game, int n_links){
  if(!game || (n_links < 0) || (n_links > MAX_LINKS)){
    return ERROR;
  }

  game->n_links = n_links;
  return OK;
}

Link **game_get_links(Game *game) {
  if(!game){
    return NULL;
    }

    return game->links;
}

Id game_get_connection(Game *game, Id id_act, Direction direction) {
  int i;

  if(!game || id_act==NO_ID) {
    return NO_ID;
  }

  for (i=0; i<game->n_links; i++) {
    if (link_get_origin(game->links[i])==id_act){
      if (link_get_direction(game->links[i])==direction) {
        return link_get_destination(game->links[i]);
      }
    }
  }

  return NO_ID;
}

Bool game_connection_is_open(Game *game, Id id_act, Direction direction) {
  int i;

  if(!game || id_act==NO_ID) {
    return FALSE;
  }

  for (i=0; i<game->n_links; i++) {
    if (link_get_origin(game->links[i])==id_act){
      if (link_get_direction(game->links[i])==direction) {
        return link_get_open(game->links[i]);
      }
    }
  }

  return FALSE;
}

int game_get_turn(Game *game){
  if (!game) return POINT_ERROR;
  return game->turn;
}

Status game_set_turn(Game *game, int turn){
  if(!game || turn > game->n_players || turn < 0) return ERROR;
  game->turn = turn;
  return OK;
}

Status game_next_turn(Game *game) {
  if (!game) {
      return ERROR;
  }
  
  if (game->finished) {
      return ERROR; 
  }
  
  game->turn = (game->turn + 1) % game->n_players;
  
  return OK; 
}

int game_get_nspaces(Game *game){
  if(!game) return NO_ID;
  return game->n_spaces;
}

Id game_get_space_id_at(Game* game, int index) {
  if (!game || index < 0 || index >= MAX_SPACES) {
      return NO_ID;
  }
  
  if (!game->spaces[index]) return NO_ID;
  
  return space_get_id(game->spaces[index]);
}

Id game_get_character_id_at(Game* game, int index) {
  if (!game || index < 0 || index >= MAX_CHARACTERS) {
      return NO_ID;
  }
  
  if (!game->characters[index]) return NO_ID;
  
  return character_get_id(game->characters[index]);
}

Id game_get_object_id_at(Game* game, int index) {
  if (!game || index < 0 || index >= MAX_OBJECTS) {
    return NO_ID;
  }
  
  if (!game->objects[index]) return NO_ID;
  
  return object_get_id(game->objects[index]);
}

Id game_get_player_id_at(Game* game, int index) {
  if (!game || index < 0 || index >= MAX_PLAYERS) {
    return NO_ID;
  }
  
  if (!game->players[index]) return NO_ID;
  
  return player_get_id(game->players[index]);
}

Id game_get_link_id_at(Game* game, int index) {
  if (!game || index < 0 || index >= MAX_LINKS) {
    return NO_ID;
  }
  
  if (!game->links[index]) return NO_ID;
  
  return link_get_id(game->links[index]);
}

Player *game_get_player_by_id(Game* game, int index) {
  if (!game || index < 0 || index >= MAX_PLAYERS) {
    return NULL;
  }
  
  if (!game->players[index]) return NULL;
  
  return game->players[index];
}

Link *game_get_link_by_id(Game* game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_links; i++) {
    if (id == link_get_id(game->links[i])) {
      return game->links[i];
    }
  }

  return NULL;
}

int game_get_nfollowingcharacters(Game *game, Id player_id) {
  int i, n = 0;

  if (!game || player_id == NO_ID) {
    return POINT_ERROR;
  }

  for (i = 0; i < game->n_characters; i++) {
    if (character_get_following(game->characters[i]) == player_id) {
      n++;
    }
  }

  return n;
}

Character **game_get_followingcharacters(Game *game, Id player_id) {
  int i, n = 0, following = -1;
  Character **following_characters = NULL;

  if (!game || player_id == NO_ID) {
    return NULL;
  }

  following = game_get_nfollowingcharacters(game, player_id);
  if (following <= 0) {
    return NULL;
  }

  following_characters = (Character **) malloc (following * sizeof(Character *));

  if(following_characters == NULL) {
    return NULL;
  }

  for (i = 0; i < game->n_characters; i++) {
    if (character_get_following(game->characters[i]) == player_id) {
      following_characters[n] = game->characters[i];
      n++;
    }
  }

  return following_characters;
}

int game_get_space_n_nonfollowingcharacters(Game *game, Space *space, Id player_id) {
  int n = 0;
  if (!game || player_id == NO_ID ||!space) {
    return POINT_ERROR;
  }

  if(game_get_player_location(game) == space_get_id(space)){
    n = space_get_ncharacters(space) - game_get_nfollowingcharacters(game, player_id);
  }

  else{
    n = space_get_ncharacters(space);
  }

  return n;
}

Character **game_get_space_nonfollowingcharacters(Game *game, Space *space, Id player_id) {
  int i, n = 0, nonfollowing = -1;
  Character **nonfollowing_characters = NULL;
  Id *characters_ids = NULL;

  if (!game || player_id == NO_ID || !space) {
    return NULL;
  }

  if(!(characters_ids = space_get_characters_ids(space))){
    return NULL;
  }

  nonfollowing = game_get_space_n_nonfollowingcharacters(game, space, player_id);
  if (nonfollowing <= 0) {
    return NULL;
  }

  nonfollowing_characters = (Character **) malloc (nonfollowing * sizeof(Character *));

  if(nonfollowing_characters == NULL) {
    return NULL;
  }

  for (i = 0; i < space_get_ncharacters(space); i++) {
    if (character_get_following(game_get_character(game,characters_ids[i])) != player_id) {
      nonfollowing_characters[n] = game_get_character(game, characters_ids[i]);
      n++;
    }
  }

  return nonfollowing_characters;
}

Bool game_get_log_status(Game *game) {
  if(!game) return FALSE;

  return game->log_status;
}

Status game_set_log_status(Game *game, Bool log_status) {
  if(!game) return ERROR;

  game->log_status = log_status;

  return OK;
}

Bool game_get_determinist_status(Game *game) {
  if(!game) return FALSE;

  return game->determinst_status;
}

Status game_set_determinist_status(Game *game, Bool determinst_status) {
  if(!game) return ERROR;

  game->determinst_status = determinst_status;

  return OK;
}
