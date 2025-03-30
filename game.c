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
 #include "game_reader.h"
 #include "character.h"
 #include "link.h"
 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #define INIT_ID 1 /*Constant that refers to the starting id of a player and object */
 
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
   int turn; /*!< Integrer defining the player's turn (0 or 1)*/
   Command *last_cmd; /*!< It stores the last command called */
   Bool finished; /*!< It defines if the game finished or not */
   Character *characters[MAX_CHARACTERS]; /*!< It contains all the characters of the game*/
   char message[MAX_MESSAGE]; /*!< It contains the message of the chat*/
   Status last_cmd_status; /*!< It contains the status of the last command*/
   Link *links[MAX_LINKS]; /*!< It contains all the links of the game*/
 };
 
 
 /**
  * @brief Determines the space where the player is
  * @author Jaime Romero
  * 
  * @param game A pointer to Game
  * @param position A number with the position
  * 
  * @return Return NO_ID if the position is negative or higher than the number of spaces available
  * if it's correct, it returns the id of the space in that position
 */
 Id game_get_space_id_at(Game *game, int position);
 /*Private function*/
 
 
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
   game ->last_cmd_status = ERROR;
  
 
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
 
   if (game_reader_load_spaces(game, filename) == ERROR) {
     return NULL;
   }
 
   if (game_reader_load_objects(game, filename) == ERROR) {
     return NULL;
   }
 
   if (game_reader_load_characters(game, filename) == ERROR) {
     return NULL;
   }
 
   if (game_reader_load_links(game, filename) == ERROR) {
     return NULL;
   }
 
   if (game_reader_load_players(game, filename) == ERROR) {
     return NULL;
   }
 
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
 
 Status game_get_last_cmd_status(Game *game){
   if(!game) return ERROR;
   return game->last_cmd_status;
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
 
 Status game_set_last_cmd_status(Game *game, Status cmd_status){
   if(!game) return ERROR;
 
   game->last_cmd_status = cmd_status;
 
   return OK;
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
 
   for(i=0; i<game->n_spaces; i++){
     if(space_get_character(game->spaces[i]) == id){
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
 
   space_set_character(game_get_space(game,space_id),character_id);
   
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
 Id game_get_space_id_at(Game *game, int position) {
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

  Status game_next_turn(Game *game){
    int next_turn = -1;
    if(!game) return ERROR;

    if(game->turn < game->n_players){
      next_turn++;
    } else if (game->turn == game->n_players - 1)
    {
      next_turn = 0;
    }

    game->turn = next_turn;
    return OK;
  }

