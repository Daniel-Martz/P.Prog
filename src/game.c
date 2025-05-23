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
#include <strings.h>

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
  int n_teams; /*!< Number of teams that the game has */
  int turn; /*!< Integrer defining the player's turn */
  Command *last_cmd; /*!< It stores the last command called */
  Bool finished; /*!< It defines if the game finished or not */
  Character *characters[MAX_CHARACTERS]; /*!< It contains all the characters of the game*/
  char message[MAX_MESSAGE]; /*!< It contains the message of the chat*/
  char *missions[MAX_MESSAGE]; /*!< It contains the message for the missions*/
  Link *links[MAX_LINKS]; /*!< It contains all the links of the game*/
  Bool log_status; /*!< It defines if the log is active or not */
  Bool determinst_status; /*!< It defines if the game is deterministic or not */
  char assasin_name[MAX_NAME]; /*!< It defines the assasins name*/
  char weapon_name[MAX_NAME]; /*!< It defines the weapon name*/
  char place_name[MAX_NAME]; /*!< It defines the place name*/
  char *clues[MAX_CLUES]; /*!< It stores the clues*/
  int nclues; /*!< It stores the number of clues*/
};

Game *game_create(void){
  int i,j;
  Game *game = NULL;

  if(!(game = (Game*)calloc(1,sizeof(Game)))){
    return NULL;
  }

  for(i = 0; i< MAX_CLUES; i++){
    if(!(game->clues[i] =(char*)calloc(MAX_MESSAGE, sizeof(char)))){
      for (j = 0; j < i; j++) free(game->clues[j]);
      return NULL;
    }
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
  game->n_teams = 0;
  game->turn = 0;
  game->last_cmd = command_create();
  game->finished = FALSE;
  game->log_status = FALSE;
  game->determinst_status = FALSE;
  game->nclues = 0;


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
  return game_management_load(filename);
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

  for (i = 0; i < game->n_teams; i++) {
    free(game->missions[i]);
  }

  for( i=0; i<MAX_CLUES; i++){
    free(game->clues[i]);
  }

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
int i, j, k = 0, n = 0; 
Id space_id;
Object **objects_discovered;
  
if (!(game)) {
  return NULL;
}

if((k = game_get_n_objects_discovered(game)) == 0){
  return NULL;
}

objects_discovered = (Object **) malloc (k * sizeof(Object *));

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
int i, j, n, k = 0; 
Id space_id;
Character **characters_discovered;
  
if (!(game)) {
  return NULL;
}

if((n = game_get_n_characters_discovered(game)) == 0){
  return NULL;
}

characters_discovered = (Character **) malloc (n * sizeof(Character *));

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
  if (!game || space_id == NO_ID || character_id == NO_ID) {
    return ERROR;
  }

  space_character_del(game_get_space(game, space_id), character_id);
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
    if(!strcasecmp(object_get_name(game->objects[i]),objname)){
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

Player *game_get_player_by_id(Game* game, Id player_id) {
  int i=0;
  Player **players = NULL;

  if (!game || player_id == NO_ID) {
    return NULL;
  }
  
  players = game_get_players(game);
  for (i = 0; i < game->n_players; i++) {
    if (player_id == player_get_id(players[i])) {
      return players[i];
    }
  }
  
  return NULL;
}

Link *game_get_link_by_id(Game* game, Id id) {
  int i = 0;

  if (!game || id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_links; i++) {
    if (id == link_get_id(game->links[i])) {
      return game->links[i];
    }
  }

  return NULL;
}

Link *game_get_link_by_name(Game *game, char *name) {
  int i = 0;

  if (!game || !name) {
    return NULL;
  }

  for (i = 0; i < game->n_links; i++) {
    if (!(strcmp(name, link_get_name(game->links[i])))) {
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

int game_get_player_total_damage(Game *game, Id player_id) {
  int damage = 0, i;
  Character **characters = NULL;
  Player **players = NULL;

  if((!game) || (player_id == NO_ID)) return POINT_ERROR;

  characters = game_get_followingcharacters(game, player_id);
  players = game_get_players_in_same_team(game, game_get_player_by_id(game, player_id));

  damage += player_get_damage(game_get_player_by_id(game, player_id));
  if ((characters == NULL) && (players == NULL)) {
    return damage;
  }

  if (characters != NULL) {
    for (i = 0; i< game_get_nfollowingcharacters(game, player_id); i++) {
      damage += character_get_damage(characters[i]) + 1;
    }
  }
  if (players != NULL) {
    for (i = 0; i< game_get_n_players_in_same_team(game, game_get_player_by_id(game, player_id)); i++) {
      damage += player_get_damage(players[i]);
    }
  }

  return damage;
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

char *game_get_assasin_name(Game *game) {
  if(!game) return NULL;

  return game->assasin_name;
}

char *game_get_weapon_name(Game *game) {
  if(!game) return NULL;

  return game->weapon_name;
}

char *game_get_place_name(Game *game) {
  if(!game) return NULL;

  return game->place_name;
}

Status game_set_assasin_name(Game *game, char *assasin_name) {
  if(!game || !assasin_name) return ERROR;

  if(!strcpy(game->assasin_name, assasin_name)){
    return ERROR;
  }
  return OK;
}

Status game_set_weapon_name(Game *game, char *weapon_name) {
  if(!game || !weapon_name) return ERROR;

  if(!strcpy(game->weapon_name, weapon_name)){
    return ERROR;
  }
  return OK;
}

Status game_set_place_name(Game *game, char *place_name) {
  if(!game || !place_name) return ERROR;

  if(!strcpy(game->place_name, place_name)){
    return ERROR;
  }
  return OK;
}

Status game_set_n_teams(Game *game, int n_teams) {
  if(!game || (n_teams < 0) || (n_teams > MAX_TEAMS)) {
    return ERROR;
  }

  game->n_teams = n_teams;
  return OK;
}

int game_get_n_teams(Game *game) {
  if(!game) return POINT_ERROR;
  return game->n_teams;
}

Player *game_get_player_by_name(Game *game, char *name) {
  int i = 0;

  if (!game || !name) {
    return NULL;
  }

  for (i = 0; i < game->n_players; i++) {
    if (!(strcmp(name, player_get_name(game->players[i])))) {
      return game->players[i];
    }
  }

  return NULL;
}

int game_get_n_players_in_same_team(Game *game, Player *player) {
  int i = 0, n = 0;
  Player **players = NULL;

  if (!game || !player) {
    return POINT_ERROR;
  }

  if (player_get_team(player) == NO_ID) {
    return POINT_ERROR;
  }

  players = game_get_players(game);
  for (i = 0; i < game->n_players; i++) {
    if (player_get_team(players[i]) == player_get_team(player)) {
      n++;
    }
  }

  return n;
}

Player **game_get_players_in_same_team(Game *game, Player *player) {
  int i = 0, n = 0, teamplayers = 0;
  Player **players = NULL, **same_team_players = NULL;

  if (!game || !player) {
    return NULL;
  }

  if (player_get_team(player) == NO_ID) {
    return NULL;
  }

  if((teamplayers = game_get_n_players_in_same_team(game, player))<=0){
    return NULL;
  }
  players = game_get_players(game);
  same_team_players = (Player **) malloc (teamplayers * sizeof(Player *));

  if(same_team_players == NULL) {
    return NULL;
  }

  for (i = 0; i < game->n_players; i++) {
    if (player_get_team(players[i]) == player_get_team(player)) {
      same_team_players[n] = players[i];
      n++;
    }
  }

  return same_team_players;
}

int game_get_space_n_nonteamplayers(Game *game, Id space_id, Player *player){
  int i = 0, n = 0;
  Player **players = NULL;

  if (!game || !player) {
    return POINT_ERROR;
  }

  
  players = game_get_players(game);
  if(!players) return POINT_ERROR;

  if (player_get_team(player) == NO_ID) {
    for (i = 0; i < game->n_players; i++) {
      if ((player_get_location(players[i]) == space_id) && (player_get_id(players[i]) != player_get_id(player)) ){
        n++;
      }
    }
  }
  else{
    for (i = 0; i < game->n_players; i++) {
      if ((player_get_location(players[i]) == space_id) && (player_get_team(players[i]) != player_get_team(player)) && (player_get_id(players[i]) != player_get_id(player))){
        n++;
      }
    }
  }
  return n;
}
Player **game_get_space_nonteamplayers(Game *game, Id space_id, Player *player){
  int i, n = 0, nonteam = 0;
  Player **players = NULL, **nonteamplayers = NULL;

  if ( !game || !player || space_id == NO_ID) {
    return NULL;
  }

  if(!(players = game_get_players(game))){
    return NULL;
  }

  nonteam = game_get_space_n_nonteamplayers(game, space_id, player);
  if (nonteam <= 0) {
    return NULL;
  }

  nonteamplayers = (Player **) malloc (nonteam * sizeof(Player *));

  if(nonteamplayers == NULL) {
    return NULL;
  }

  if(player_get_team(player) != NO_ID){
    for (i = 0; i < game_get_nplayers(game); i++) {
      if ((player_get_team(players[i]) != player_get_team(player)) && (player_get_location(players[i]) == space_id) && (player_get_id(players[i]) != player_get_id(player))) {
        nonteamplayers[n] = players[i];
        n++;
      }
    }
  }
  else{
    for (i = 0; i < game_get_nplayers(game); i++) {
      if ((player_get_location(players[i]) == space_id) && (player_get_id(players[i]) != player_get_id(player))) {
        nonteamplayers[n] = players[i];
        n++;
      }
    }
  }

  return nonteamplayers;
}

int game_get_nclues(Game *game){
  if(!game) return POINT_ERROR;
  return game->nclues;
}

Status game_add_clue(Game *game, char *clue){
  if(!game || !clue) return ERROR;
  
  if(game->nclues >= MAX_CLUES) return ERROR;

  strcpy(game->clues[game->nclues], clue);
  game->nclues ++;
  return OK;
}
Bool game_clue_is_stored (Game *game, char *clue){
  int i;
  if(!game || !clue){
    return TRUE;
  }
  for(i=0; i<game->nclues; i++){
    if(!strcmp(clue, game->clues[i])){
      return TRUE;
    }
  }
  return FALSE;
}

char *game_get_clue(Game *game, int number){
  if(!game || number<0 || number>= MAX_CLUES) return NULL;
  return game->clues[number];
}



