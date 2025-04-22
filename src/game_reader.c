/**
 * @brief It creates and adds the spaces 
 * @file game_reader.c
 * @author Jaime Romero, Daniel Martínez
 * 
 * @version 0.1
 * @date 2025-02-08
 * 
 * @copyright Copyright (c) 2025
 */
#include "game_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Status game_reader_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id space_id = NO_ID;
  Space *space = NULL;
  Status status = OK;
  char gdesc[N_ROWS][N_COLUMNS];
  int row=0;

  if (!filename || !game) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      space_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);

      for (row = 0; row < N_ROWS; row++)
      {
        if (toks != NULL)
        {
          toks = strtok(NULL, "|");
          if (toks != NULL) {
            strncpy(gdesc[row], toks, N_COLUMNS - 1);
            gdesc[row][N_COLUMNS - 1] = '\0'; 
          } else 
          {
            memset(gdesc[row], ' ', N_COLUMNS - 1); 
            gdesc[row][N_COLUMNS - 1] = '\0';
          }
        }  
      }

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(space_id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_gdesc(space, (const char(*)[N_COLUMNS])gdesc); /*Hacemos casting al llamar a la fucnión set_gdesc para que concuerde con el tipo de dato que requiere la fucnión*/
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

Status game_reader_load_objects(Game *game, char *filename){

  FILE *file=NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char description[MAX_DESCRIP] = "";
  char *toks = NULL;
  int health;
  Id object_id = NO_ID, space_id = NO_ID, dependency = NO_ID;
  Object *object = NULL;
  Status status = OK;
  Bool movable, open;

  if (!filename || !game) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)){
    if (strncmp("#o:", line, 3) == 0){
      /*Read all the data and then store it in variables*/
      toks = strtok(line + 3, "|");
      object_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      space_id = atol(toks);
      toks = strtok(NULL, "|");
      health = atol(toks);
      toks = strtok(NULL, "|");
      movable = atol(toks);
      toks = strtok(NULL, "|");
      dependency = atol(toks);
      toks = strtok(NULL, "|");
      open = atol(toks);
      toks = strtok(NULL, "\n");
      strncpy(description, toks, MAX_DESCRIP-1);
      
      /*Create the object*/
      object = object_create(object_id);
      if (!object) return ERROR;
      object_set_name(object, name);
      game_add_object(game, object);
      space_set_new_object(game_get_space(game, space_id), object_id);
      object_set_description(object, description);
      object_set_health(object, health);
      object_set_movable(object, movable);
      object_set_dependency(object, dependency);
      object_set_open(object, open);
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;

}

Status game_reader_load_characters(Game *game, char *filename){

  FILE *file=NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char gdesc[WORD_SIZE] = "";
  char message[WORD_SIZE] = "";
  char *toks = NULL;
  Id character_id = NO_ID, space_id = NO_ID;
  Character *character = NULL;
  Status status = OK;
  long health = 0;
  Bool friendly =FALSE;

  if (!filename || !game) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)){
    if (strncmp("#c:", line, 3) == 0){
      /*Read all the data and then store it in variables*/
      toks = strtok(line + 3, "|");
      character_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      health = atol(toks);
      toks = strtok(NULL, "|");
      friendly = (Bool)atol(toks);
      toks = strtok(NULL, "|");
      space_id = atol(toks);
      toks = strtok(NULL, "|");
      strncpy(gdesc, toks,G_DESC-1);
      toks = strtok(NULL, "\n");
      strncpy(message, toks, MAX_MESSAGE-1);
      
      /*Create the object*/
      character = character_create(character_id);
      if (!character) return ERROR;
      character_set_name(character, name);
      character_set_friendly(character, friendly);
      character_set_health(character, health);
      character_set_message(character, message);
      character_set_gdesc(character, gdesc);
      game_add_character(game, character);
      game_set_character_location(game, space_id, character_id);
      space_set_newCharacter(game_get_space(game, space_id), character_id);
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;

}

Status game_reader_load_players(Game *game, char *filename){
  
  FILE *file=NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char gdesc[WORD_SIZE] = "";
  long health = 0;
  int max_objects;
  char *toks = NULL;
  Id player_id = NO_ID, space_id = NO_ID;
  Player *player = NULL;
  Status status = OK;

  if (!filename || !game) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)){
    if (strncmp("#p:", line, 3) == 0){
      /*Read all the data and then store it in variables*/
      toks = strtok(line + 3, "|");
      player_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc, toks);
      toks = strtok(NULL, "|");
      space_id = atol(toks);
      toks = strtok(NULL, "|");
      health = atol(toks);
      toks = strtok(NULL, "|");
      max_objects = atol(toks);

      /*Create the Player (with its inventory)*/
      player = player_create(player_id);
      if (!player) return ERROR;
      player_set_name(player, name);
      player_set_health(player, health);
      player_set_gdesc(player, gdesc);
      game_add_player(game, player);
      game_set_player_initial_location(game, player_id, space_id);
      inventory_set_max_objs(player_get_backpack(player), max_objects);
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
  
}

Status game_reader_load_links(Game *game, char *filename){
  
  FILE *file=NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id link_id = NO_ID, orig_space_id = NO_ID, dest_space_id = NO_ID;
  Direction direction;
  Bool open = FALSE;
  Link *link;
  Status status = OK;

  if (!filename || !game) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)){
    if (strncmp("#l:", line, 3) == 0){
      /*Read all the data and then store it in variables*/
      toks = strtok(line + 3, "|");
      link_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      orig_space_id = atol(toks);
      toks = strtok(NULL, "|");
      dest_space_id = atol(toks);
      toks = strtok(NULL, "|");
      direction = atol(toks);
      toks = strtok(NULL, "|");
      open = atol(toks);

      /*Create the link*/
      link = link_create(link_id);
      if (!link) return ERROR;
      link_set_name(link, name);
      link_set_origin(link, orig_space_id);
      link_set_destination(link, dest_space_id);
      link_set_direction(link, direction);
      link_set_open(link, open);
      game_add_link(game, link);
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;

}

Status game_management_save(Game *game, char *filename) {
  FILE *file = NULL;
  Status status = OK;
  Space *space = NULL;
  Object *object = NULL;
  Character *character = NULL;
  Player *player = NULL;
  Link *link = NULL;
  Id id = NO_ID;
  int i = 0;
  int row = 0; 
  const char* row_data = NULL;
  
  if (!filename || !game) {
    return ERROR;
  }

  file = fopen(filename, "w");
  if (file == NULL) {
    return ERROR;
  }

  /*Guardar espacios*/
  for (i = 0; i < MAX_SPACES && game_get_space_id_at(game, i) != NO_ID; i++) {
    id = game_get_space_id_at(game, i);
    space = game_get_space(game, id);
    
    fprintf(file, "#s:%ld|%s", id, space_get_name(space));
    
    /*Guardar gdesc*/
    for (row = 0; row < N_ROWS; row++) {
      row_data = space_get_gdesc(space, row);
      fprintf(file, "|%s", row_data ? row_data : "     "); /*Si row_data no existe se imprimen cinco espacios*/
    }
    fprintf(file, "\n");
  }

  /*Guardar objetos*/
  for (i = 0; i < MAX_OBJECTS && game_get_object_id_at(game, i) != NO_ID; i++) {
    id = game_get_object_id_at(game, i);
    object = game_get_object(game, id);
    
    fprintf(file, "#o:%ld|%s|%d|%d|%d|%ld|%ld|%s\n", id, object_get_name(object), game_get_object_location(game, id), object_get_health(object), object_is_movable(object), object_get_dependency(object), object_get_open(object), object_get_description(object));
  }

  /*Guardar personajes*/
  for (i = 0; i < MAX_CHARACTERS && game_get_character_id_at(game, i) != NO_ID; i++) {
    id = game_get_character_id_at(game, i);
    character = game_get_character(game, id);
    
    fprintf(file, "#c:%ld|%s|%d|%d|%d|%s|%s\n", id, character_get_name(character), character_get_health(character), character_get_friendly(character), game_get_character_location(game, id), character_get_gdesc(character), character_get_message(character));
  }

  /*Guardar jugadores*/
  for (i = 0; i < MAX_PLAYERS && game_get_player_id_at(game, i) != NO_ID; i++) {
    id = game_get_player_id_at(game, i);
    player = game_get_player_by_id(game, id);
    
    fprintf(file, "#p:%ld|%s|%s|%ld|%d|%d\n", id, player_get_name(player), player_get_gdesc(player), player_get_location(player), player_get_health(player), inventory_get_max_objs(player_get_backpack(player)));
  }

  /*Guardar enlaces*/
  for (i = 0; i < MAX_LINKS && game_get_link_id_at(game, i) != NO_ID; i++) {
    id = game_get_link_id_at(game, i);
    link = game_get_link_by_id(game, id);
    
    fprintf(file, "#l:%ld|%s|%ld|%ld|%d|%d\n", id, link_get_name(link), link_get_origin(link), link_get_destination(link), link_get_direction(link), link_get_open(link));
  }
  
  fclose(file);
  return status;
}

Game *game_management_load(char *filename) {
  Game *game = NULL;
  game = game_create();
  if (!game) {
    return NULL;
  }

  if (game_reader_load_spaces(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }
  if (game_reader_load_objects(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }
  if (game_reader_load_characters(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }
  if (game_reader_load_players(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }
  if (game_reader_load_links(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }

  return game;
}