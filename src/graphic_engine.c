/**
 * @brief It implements a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Daniel Martinez
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "graphic_engine.h"

#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "types.h"

#define MAX_STR 255/*!< Constant assigned fpr the maximum length of a string*/
#define MAX_BUFFER 300/*!< Constant assigned for the lenght of an auxiliary buffer*/
#define WIDTH_MAP 79/*!< Constant asignated for the width of the map*/
#define WIDTH_DES 40/*!< Constant asignated for the width of the description*/
#define WIDTH_BAN 150/*!< Constant asignated for the width of the banner*/
#define HEIGHT_MAP 60/*!< Constant asignated for the height of the map*/
#define HEIGHT_BAN 1/*!< Constant asignated for the height of the banner*/
#define HEIGHT_DES 50/*!< Constant asignated for the height of description inter*/
#define HEIGHT_HLP 3/*!< Constant asignated for the height of help interface*/
#define HEIGHT_FDB 3/*!< Constant asignated for the height of feedback interface*/
#define WIDTH_SPACE 23/*!< Constante asignated for the maximum size of the lines inside the space*/
#define HEIGHT_SPACE 18/*!< Constante asignated for the maximum size of the columns inside the space*/
#define MAX_RESULT 10/*!< Constant fot the maximum size of the result*/
#define LINE_1 0/*!< Constant for the first line of the space*/
#define LINE_2 1/*!< Constant for the second line of the space*/
#define LINE_3 2/*!< Constant for the third line of the space*/
#define LINE_4 3/*!< Constant for the fourth line of the space*/
#define LINE_5 4/*!< Constant for the fifth line of the space*/
#define LINE_6 5/*!< Constant for the sixth line of the space*/
#define LINE_7 6/*!< Constant for the seventh line of the space*/
#define LINE_8 7/*!< Constant for the eighth line of the space*/
#define LINE_9 8/*!< Constant for the ninth line of the space*/
#define LINE_10 9/*!< Constant for the tenth line of the space*/
#define LINE_11 10/*!< Constant for the tenth line of the space*/
#define LINE_12 11/*!< Constant for the tenth line of the space*/
#define LINE_13 12/*!< Constant for the tenth line of the space*/
#define LINE_14 13/*!< Constant for the tenth line of the space*/
#define LINE_15 14/*!< Constant for the tenth line of the space*/
#define LINE_16 15/*!< Constant for the tenth line of the space*/
#define LINE_17 16/*!< Constant for the tenth line of the space*/
#define LINE_18 17/*!< Constant for the tenth line of the space*/
#define FINAL 5/*!< Constant to write the final of a space which names are too extense*/
#define LIMIT 21/*!< Constant for the limit to write in a line*/
#define MID_SPACE (HEIGHT_SPACE/2) /*!< Constant for the line of the midle in the space*/

/**
 * @brief This struct stores all the information of the graphic engine (everything showed by screen).
 *
 * @author Daniel Martinez
 */
struct _Graphic_engine {
  Area *map;/*!< It defines the area of the map interface*/
  Area *descript;/*!< It defines the area of the description interface*/
  Area *banner;/*!< It defines the area of the banner interface*/
  Area *help;/*!< It defines the area of the help interface*/
  Area *feedback;/*!< It defines the area of the feedback interface*/
  Area *face;/*!< It defines the area for the faces of the characters*/
};

/*--------------------------------------PRIVATE FUNCTIONS--------------------------------------*/

/**
 * @brief It frees all the allocated memory for paint_game
 * @author Jaime Romero
 * 
 * @param space A double poinyter to the space which is going to be freed
 */
void free_gengine_paint_game(char**space){
  int i = 0;
  if (space != NULL) {
    for (i = 0; i < HEIGHT_SPACE; i++) {
      if (space[i] != NULL) { 
        free(space[i]);
        space[i] = NULL;
      }
    }
    free(space);
    space = NULL;
  }
}

/**
 * @brief This private function prints in a matrix of characters a space
 * @author Daniel Martínez
 * @param space_id The id of the space to print
 * @param game Pointer to game structure
 * @return The column of strings of the space
 */
char **graphic_engine_print_space(Id space_id, Game *game){
  char str[MAX_STR];
  char **strspace;
  const char* gdesc[N_ROWS];
  Space *space= NULL;
  Id *objects_id = NULL;
  int line_lenght = 0, i, j;
  Character **followers = NULL;
  Character **charact_space = NULL;
  Player *player = NULL;
  
  if ((space_id == NO_ID) || !game) return NULL;

  space = game_get_space(game, space_id);

  for (i = 0; i < N_ROWS; i++) {
      gdesc[i] = space_get_gdesc(space, i);
      if (!gdesc[i]) gdesc[i] = "        ";  
  }
  /*ALLOC OF THE MATRIX OF THE SPACE*/
  strspace = (char **)malloc(HEIGHT_SPACE * sizeof(char *));
  if (!strspace) return NULL;

  for (i = 0; i < HEIGHT_SPACE; i++) {
    strspace[i] = (char *)malloc((WIDTH_SPACE + 1) * sizeof(char));
    if (!strspace[i]) {
      for (j = 0; j < i; j++) free(strspace[j]);
      free(strspace);
      return NULL;
    }
  }

  player = game_get_player(game);
  followers = game_get_followingcharacters(game, player_get_id(player));
  charact_space = game_get_space_nonfollowingcharacters(game, space, player_get_id(player));

  /*CHECK IF It'S DISCOVERED*/
  sprintf(strspace[LINE_1], "      __-/-^-\\-__      ");
  sprintf(strspace[LINE_2], "    _/__--/*\\--__\\_    ");
  sprintf(strspace[LINE_3], "  _/---^/     \\^---\\_  ");
  sprintf(strspace[LINE_4], " /---             ---\\ ");
  sprintf(strspace[LINE_5], "|%-10.10s        %3d|", space_get_name(space), (int)space_id);

    if(space_get_discovered(space) == FALSE){
      sprintf(strspace[LINE_6], "|        ######       |");
      sprintf(strspace[LINE_7], "|      #########      |");
      sprintf(strspace[LINE_8], "|     ###     ###     |");
      sprintf(strspace[LINE_9], "|             ###     |");
      sprintf(strspace[LINE_10],"|           ####      |");
      sprintf(strspace[LINE_11],"|          ###        |");
      sprintf(strspace[LINE_12],"|         ###         |");
      sprintf(strspace[LINE_13],"|                     |");
      sprintf(strspace[LINE_14],"|         ###         |");
      sprintf(strspace[LINE_15]," \\__               __/ ");
      sprintf(strspace[LINE_16],"   \\__\\--_   _--/__/   ");
      sprintf(strspace[LINE_17],"      \\-__\\*/__-/      ");
      sprintf(strspace[LINE_18],"         -\\v/-         ");

      if(followers != NULL){
        free(followers);
      }
      if(charact_space != NULL){
        free(charact_space);
      }
      return strspace;
    }
/* LINEA CON LOS FOLLOWERS */ 
else {
  if (!followers || (space_id != player_get_location(player))) {
      sprintf(strspace[LINE_6], "|                     |");
  } else {
      str[0] = '\0';
      for (i = 0; i < game_get_nfollowingcharacters(game, player_get_id(player)); i++) {
          strncat(str, " ", MAX_STR - strlen(str) - 1);
          strncat(str, character_get_gdesc(followers[i]), MAX_STR - strlen(str) - 1);
      }
      line_lenght = strlen(str);
      if (line_lenght > LIMIT) { 
          snprintf(strspace[LINE_6], WIDTH_SPACE + 2, "|%-18.18s...|", str);
      } else {
          snprintf(strspace[LINE_6], WIDTH_SPACE + 2, "|%-21.21s|", str);
      }
  }

/* LINEA CON EL PLAYER Y LOS CHARACTERS */
  str[0] = '\0';

  if (space_id == game_get_player_location(game)) {
      snprintf(strspace[LINE_7], WIDTH_SPACE , "|%-4.4s", player_get_gdesc(game_get_player(game)));
      if (charact_space != NULL) {
          int nonfollowing = game_get_space_n_nonfollowingcharacters(game, game_get_space(game, space_id), player_get_id(player));
          for (i = 0; i < nonfollowing; i++) {
              strncat(str, " ", MAX_STR - strlen(str) - 1);
              strncat(str, character_get_gdesc(charact_space[i]), MAX_STR - strlen(str) - 1);
          }
          line_lenght = strlen(str);
          if (line_lenght > LIMIT) {
              strncat(strspace[LINE_7], str, WIDTH_SPACE - FINAL);
              strncat(strspace[LINE_7], "...|", FINAL);
          } else {
            snprintf(strspace[LINE_7], WIDTH_SPACE +2 , "|%-4.4s %16.16s|", player_get_gdesc(game_get_player(game)), str);
          }
      } else {
          strcat(strspace[LINE_7], "                 |"); 
    }
  }
  else {
      snprintf(strspace[LINE_7], WIDTH_SPACE + 2, "|     ");
      if (charact_space != NULL) {
          int nonfollowing = game_get_space_n_nonfollowingcharacters(game, game_get_space(game, space_id), player_get_id(player));
          for (i = 0; i < nonfollowing; i++) {
              strncat(str, " ", MAX_STR - strlen(str) - 1);
              strncat(str, character_get_gdesc(charact_space[i]), MAX_STR - strlen(str) - 1);
          }
          line_lenght = strlen(str);
          if (line_lenght > LIMIT) {
            snprintf(strspace[LINE_7], WIDTH_SPACE +2, "|  %16.16s...|", str);
          } else {
            snprintf(strspace[LINE_7], WIDTH_SPACE +2, "|     %16.16s|", str);
          }
      } else {
        sprintf(strspace[LINE_7], "|                     |");
      }
  }
}
      
    /*DESCRIPCION DEL MAPA*/
    if(gdesc[0] != NULL){
      for (i = 0; i < N_ROWS; i++) {
        sprintf(strspace[i+LINE_8], "|%9.9s            |", gdesc[i]);
      }
    }
    else{
      for (i = 0; i < N_ROWS; i++) {
        sprintf(strspace[i+LINE_8],"|                     |");
      }
    }

    sprintf(strspace[LINE_13], "|                     |");
      /*OBJETOS*/
      objects_id = space_get_objects_ids(space);
      if (objects_id != NULL) {
          str[0] = '\0'; 
          for (i = 0; i < space_get_nobjects(space); i++) {
              if (i > 0) {
                  strncat(str, ", ", MAX_STR - strlen(str) - 1); 
              }
              strncat(str, object_get_name(game_get_object(game, objects_id[i])), MAX_STR - strlen(str) - 1);
          }
          line_lenght= strlen(str);
          if (line_lenght > LIMIT) { 
            snprintf(strspace[LINE_14], WIDTH_SPACE +1 , "|%18.18s...|", str);
          } else {
              sprintf(strspace[LINE_14], "|%21.21s|", str);
          }
      } else {
          sprintf(strspace[LINE_14], "|                      |");
        }

    sprintf(strspace[LINE_15]," \\__               __/ ");
    sprintf(strspace[LINE_16],"   \\__\\--_   _--/__/   ");
    sprintf(strspace[LINE_17],"      \\-__\\*/__-/      ");
    sprintf(strspace[LINE_18],"         -\\v/-         ");
    
    if(followers != NULL){
      free(followers);
    }
    if(charact_space != NULL){
      free(charact_space);
    }

    return strspace;
}

/*--------------------------------------PUBLIC FUNCTIONS--------------------------------------*/


Graphic_engine *graphic_engine_create(void) {
  static Graphic_engine *ge = NULL; /* Assign NULL to *ge only the first time*/

  if (ge) {/* Avoid errors if the function is called multiple times and the graphic engine has already been created. */
    return ge;
  }

  /* Initializates the screen areaa */
  screen_init(HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + HEIGHT_FDB + 5, WIDTH_MAP + WIDTH_DES + 3);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL) {
    return NULL;
  }                         

  /* Initializates the descript window area */
  ge->descript = screen_area_init(1, HEIGHT_BAN + 2, WIDTH_DES, HEIGHT_DES);

  /* Initializates the banner window  area */
  ge->banner = screen_area_init(1, 1, WIDTH_MAP + WIDTH_DES + 2, HEIGHT_BAN);

  /* Initializates the map window area */
  ge->map = screen_area_init(WIDTH_DES + 2, HEIGHT_BAN + 2, WIDTH_MAP, HEIGHT_MAP);

  /* Initializates the help window area */
  ge->help = screen_area_init(WIDTH_DES + 2, HEIGHT_MAP + HEIGHT_BAN + 3, WIDTH_MAP, HEIGHT_HLP);

  /* Initializates the feedback window area */
  ge->feedback = screen_area_init(WIDTH_DES + 2, HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + 4, WIDTH_MAP, HEIGHT_FDB);

    /* Initializates the feedback window area */
  ge->face = screen_area_init(1, HEIGHT_DES + 3 + HEIGHT_BAN, WIDTH_DES, HEIGHT_HLP + HEIGHT_FDB + HEIGHT_MAP - HEIGHT_DES + 1);

  if (!ge->map || !ge->descript || !ge->banner || !ge->help || !ge->feedback || !ge->face) {
    free(ge);
    return NULL;
  }

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge) {
  if (!ge) return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);
  screen_area_destroy(ge->face);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
  /* Declare de needed local variables of the function */
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_left = NO_ID, id_right = NO_ID, *objects_location = NULL, *characters_location = NULL, *player_objects = NULL;
  char buffer[MAX_BUFFER];
  char str[MAX_STR], character_name[MAX_STR];
  char **space_empty = NULL;
  char **space_left = NULL ,**space_right = NULL, **space_back = NULL, **space_next = NULL, **space_actual = NULL, **space1 = NULL, **space2 = NULL, **space3 = NULL;
  int i=0, j=0;
  CommandCode last_cmd = UNKNOWN;
  char cmd_result[MAX_RESULT];
  extern char *cmd_to_str[N_CMD][N_CMDT];
  Object **objects;
  Character **characters = NULL, *character = NULL;
  Player **players;
  char right = '>', left = '<', back = '^', next = 'v';

  /*INITIALIZES SOME VARIABLES*/
  screen_area_clear(ge->map);
  if ((id_act = (game_get_player_location(game))) != NO_ID) {
    id_back = game_get_connection(game, id_act, N);
    id_next = game_get_connection(game, id_act, S);
    id_left = game_get_connection(game, id_act, W);
    id_right = game_get_connection(game, id_act, E);
    player_objects = player_get_objects_ids(game_get_player(game));

    if (space_empty == NULL) { 
      if (!(space_empty = (char **)calloc(HEIGHT_MAP, sizeof(char *)))) {
        return;
      }
      for (i = 0; i < HEIGHT_SPACE; i++) {
        if (!(space_empty[i] = (char *)calloc((WIDTH_SPACE + 1), sizeof(char)))) {
          for (j = 0; j < i; j++) {
            free(space_empty[j]);
          }
          free(space_empty);
          return;
        }
      }
      for (i = 0; i < HEIGHT_SPACE; i++) {
        for (j = 0; j < WIDTH_SPACE; j++) {
          space_empty[i][j] = ' ';
        }
      }
    }

    /*PRINT THE SPACE*/
    space_actual = graphic_engine_print_space(id_act, game);

    if(!(space_left = graphic_engine_print_space(id_left, game))){
      space_left = space_empty;
      left = ' ';
    }
    else if(game_connection_is_open(game, id_act, W) == FALSE){
      left = 'x';
    }

    if(!(space_right = graphic_engine_print_space(id_right, game))){
      space_right = space_empty;
      right = ' ';
    }
    else if(game_connection_is_open(game, id_act, E) == FALSE){
      right = 'x';
    }

    if(!(space_next = graphic_engine_print_space(id_next, game))){
      space_next = space_empty;
      next = ' ';
    }
    else if(game_connection_is_open(game, id_act, S) == FALSE){
      next = 'x';
    }

    if(!(space_back = graphic_engine_print_space(id_back, game))){
      space_back = space_empty;
      back = ' ';
    }    
    else if(game_connection_is_open(game, id_act, N) == FALSE){
      back = 'x';
    }

    /*PRINT THE FIRST BLOCK*/

    screen_area_puts(ge->map, "                                                                                         ");

    space1 = space_empty;
    space2 = space_back;
    space3 = space_empty;

    for(i=0; i<HEIGHT_SPACE; i++){
      sprintf(str,"  %s   %s   %s", space1[i],space2[i],space3[i]);
      screen_area_puts(ge->map,str);
    }

    sprintf(str, "                                       %c          ",back);
    screen_area_puts(ge->map,str);
    
    space1 = space_left;
    space2 = space_actual;
    space3 = space_right;

    for(i=0; i<MID_SPACE; i++){
      sprintf(str,"  %s   %s   %s", space1[i],space2[i],space3[i]);
      screen_area_puts(ge->map,str);
    }

    sprintf(str,"  %s %c %s %c %s", space1[MID_SPACE],left, space2[MID_SPACE], right, space3[MID_SPACE]);
    screen_area_puts(ge->map,str);

    for(i=MID_SPACE+1; i<HEIGHT_SPACE; i++){
      sprintf(str,"  %s   %s   %s", space1[i],space2[i],space3[i]);
      screen_area_puts(ge->map,str);
    }

    sprintf(str, "                                       %c          ",next);
    screen_area_puts(ge->map,str);
    
    space1 = space_empty;
    space2 = space_next;
    space3 = space_empty;

    for(i=0; i<HEIGHT_SPACE; i++){
      sprintf(str,"  %s   %s   %s", space1[i],space2[i],space3[i]);
      screen_area_puts(ge->map,str);
    }

    /* Paint in the description area */
    screen_area_clear(ge->descript);
    /*PASAMOS ARRAY DE OBJETOS A IDS*/
    if(!(objects = game_get_objects_discovered(game))){
      screen_area_puts(ge->descript, "There are no objects discovered");
    }
    else{
      if(!(objects_location =(Id*)calloc(game_get_n_objects_discovered(game),sizeof(Id)))){
        return;
      }
        for(i=0; i < game_get_n_objects_discovered(game); i++){
          objects_location[i] = game_get_object_location(game, object_get_id(objects[i]));
        }
      
      /*IMPRESION*/
      if (objects_location != NULL) {
        sprintf(str, "  Objects: ");
        screen_area_puts(ge->descript, str);
        for(i=0; i< game_get_n_objects_discovered(game); i++){
          sprintf(str, " %s: %i",object_get_name(game_get_object(game,object_get_id(objects[i]))), (int)objects_location[i]);
          screen_area_puts(ge->descript, str);
        }
      }
    }
    screen_area_puts(ge->descript, "          ");

    /*PASAMOS ARRAY DE CHARACTERS A IDS*/
    if(!(characters = game_get_characters_discovered(game))){
      screen_area_puts(ge->descript, "There are no characters discovered");
    }

    else{
      if(!(characters_location = (Id*)calloc(game_get_n_characters_discovered(game),sizeof(Id)))){
        return;
      }
      
      for(i=0; i< game_get_n_characters_discovered(game) ; i++){
        characters_location[i] = game_get_character_location(game, character_get_id(characters[i]));
      }
      /*IMPRESION*/
      if (game_get_ncharacters(game) != 0) {
        sprintf(str, "  Characters: ");
        screen_area_puts(ge->descript, str);
        for(i=0; i< game_get_n_characters_discovered(game); i++){
          sprintf(str, "    %6.6s : %i (%i)",character_get_gdesc(characters[i]), (int)characters_location[i],character_get_health(characters[i]));
          screen_area_puts(ge->descript, str);
        }
      }
    }
    screen_area_puts(ge->descript, "       ");
    
    players = game_get_players(game);
    /*IMPRESION*/
    sprintf(str,"  Players: " );
    screen_area_puts(ge->descript, str);
    for(i=0; i< game_get_nplayers(game); i++){
      sprintf(str, "    %6.6s : %i (%i)",player_get_name(players[i]), (int)player_get_location(players[i]),player_get_health(players[i]));
      screen_area_puts(ge->descript, str);
    }

    screen_area_puts(ge->descript, "       ");
    
    if(player_objects[0]!= NO_ID){
      sprintf(str, "  Player objects:");
      screen_area_puts(ge->descript, str);
      if(inventory_get_n_objs(player_get_backpack(game_get_player(game)))==1){
        sprintf(str,"      %s", object_get_name(game_get_object(game, player_objects[0])));
        screen_area_puts(ge->descript, str);
      }
      if(inventory_get_n_objs(player_get_backpack(game_get_player(game)))>1){
        sprintf(str,"      %s", object_get_name(game_get_object(game, player_objects[0])));
        for(i = 1; i < inventory_get_n_objs(player_get_backpack(game_get_player(game))); i++ ){
          sprintf(buffer, "%s, %s", str, object_get_name(game_get_object(game, player_objects[i])));
          strcpy(str, buffer);
        }
          screen_area_puts(ge->descript, str);
      }
    }

    else{
      screen_area_puts(ge->descript, "  Player has no objects");
    }

    screen_area_puts(ge->descript, "        ");

    if(game_get_message(game) != NULL){
      sprintf(str," Message: %s",game_get_message(game));
      screen_area_puts(ge->descript, str);
    }

    /* Paint in the banner area */
    screen_area_puts(ge->banner, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CLUEDO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    /* Paint in the help area */
    screen_area_clear(ge->help);
    sprintf(str, " The commands you can use are:");
    screen_area_puts(ge->help, str);
    sprintf(str, " move or m (north/n or south/s or west/w or east/e) take or t, drop or d, attack or t, chat or c,    exit or e");
    screen_area_puts(ge->help, str);

    /* Paint in the feedback area */
    last_cmd = command_get_code(game_get_last_command(game));
    if(command_get_last_cmd_status(game_get_last_command(game)) == ERROR){
      strcpy(cmd_result, "ERROR");
    }
    else{
      strcpy(cmd_result, "OK");
    }
    if(last_cmd != NO_CMD){
      sprintf(str, " %s (%s): %s", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], cmd_result);
      screen_area_puts(ge->feedback, str);
    }

    /* PAINT THE FACE AREA*/

    screen_area_clear(ge->face);
    if(last_cmd == CHAT && (command_get_last_cmd_status(game_get_last_command(game)) == OK)){
      screen_area_puts(ge->face, "");
      strncpy(character_name, command_get_strin(game_get_last_command(game)), MAX_STR);
      character = game_get_character_from_name(game, character_name);
      sprintf(str, "Character: %s", character_name);
      screen_area_puts(ge->face, str);
      screen_area_puts(ge->face, "");
      screen_area_puts(ge->face, "  ------------------------   ");
      for(i=0; i < FACE_HEIGHT; i++){
        sprintf(str, " |   %s   |", character_get_face(character, i));
        screen_area_puts(ge->face, str);
      }
      screen_area_puts(ge->face, "  ------------------------   ");
    }



    /* PAINT THE COLOR */    
    screen_paint(game_get_turn(game));
    printf("prompt turn %i:> ", game_get_turn(game));

    /* PONER FREES DE LOS ESPACIOS */
    if (space_back != space_empty) {
      free_gengine_paint_game(space_back);
    }
    if (space_next != space_empty) {
      free_gengine_paint_game(space_next);
    }
    if (space_right != space_empty) {
      free_gengine_paint_game(space_right);
    }
    if (space_left != space_empty) {
      free_gengine_paint_game(space_left);
    }
    if (space_actual != space_empty) {
      free_gengine_paint_game(space_actual);
    }
    if (space_empty != NULL) {
      free_gengine_paint_game(space_empty);
    }

    free(objects_location);
    free(objects);
    free(characters_location);
    free(characters);
  }
  
}
