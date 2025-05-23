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
#include <string.h>
#include <stdlib.h>

#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "types.h"

#define MAX_STR 410/*!< Constant assigned fpr the maximum length of a string*/
#define MAX_BUFFER 300/*!< Constant assigned for the lenght of an auxiliary buffer*/
#define WIDTH_MAP 90/*!< Constant asignated for the width of the map*/
#define WIDTH_DES 50/*!< Constant asignated for the width of the description*/
#define WIDTH_BAN 150/*!< Constant asignated for the width of the banner*/
#define HEIGHT_MAP 60/*!< Constant asignated for the height of the map*/
#define HEIGHT_BAN 1/*!< Constant asignated for the height of the banner*/
#define HEIGHT_DES 54/*!< Constant asignated for the height of description interface*/
#define HEIGHT_HLP 9/*!< Constant asignated for the height of help interface*/
#define HEIGHT_CLUES 20/*!< Constante asignated for the height of the clues interface*/
#define WIDTH_CLUES 70/*!< Constant asignated for the width of the clues interface*/
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
#define LIMIT_1 21/*!< Constant for the LIMIT_1 to write in a line*/
#define LIMIT_2 10/*!< Constant for the LIMIT_2 to write in a line*/
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
  Area *vision;/*!< It defines the area for the vision of the player*/
  Area *clues; /*!< It defines the area to print the clues*/
};

/*--------------------------------------PRIVATE FUNCTIONS--------------------------------------*/

/**
 * @brief It frees all the allocated memory for paint_game
 * @author Jaime Romero
 * 
 * @param space A double poinyter to the space which is going to be freed
 */
void graphic_engine_free_space(char**space){
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
  char str[MAX_STR] = " ", str2[MAX_STR] = " ";
  char **strspace;
  const char* gdesc[N_ROWS];
  Space *space= NULL;
  Id *objects_id = NULL;
  int aux_len1 = 0, aux_len2 = 0, i, j;
  Character **followers = NULL;
  Character **charact_space = NULL;
  Player *player = NULL, **team = NULL, **non_team = NULL;
  
  if ((space_id == NO_ID) || !game) return NULL;

  space = game_get_space(game, space_id);

  for (i = 0; i < N_ROWS; i++) {
      gdesc[i] = space_get_gdesc(space, i);
      if (!gdesc[i]) gdesc[i] = "                 ";  
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
  team = game_get_players_in_same_team(game, player);
  non_team = game_get_space_nonteamplayers(game, space_id, player);


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
      if(team != NULL){
        free(team);
      }
      if(non_team != NULL){
        free(non_team);
      }
      return strspace;
    }
/* LINEA CON PLAYERS DEL TEAM Y LOS FOLLOWERS */ 
else {
  if (space_id != player_get_location(player)) {
      sprintf(strspace[LINE_6], "|                     |");
  } 
  else {
    sprintf(str2, " %s", player_get_gdesc(player));
    for (i = 0; i < game_get_n_players_in_same_team(game, player); i++) {
      if( player_get_id(team[i]) != player_get_id(player)){
        strncat(str2, " ", MAX_STR - strlen(str2) - 1);
        strncat(str2, player_get_gdesc(team[i]), MAX_STR - strlen(str2) - 1);
      }
    }

    if(game_get_nfollowingcharacters(game, player_get_id(player)) <= 0){
      snprintf(strspace[LINE_6], WIDTH_SPACE+1 , "|%-21.21s|", str2);
    }
    else{

      for (i = 0; i < game_get_nfollowingcharacters(game, player_get_id(player)); i++) {
        strncat(str, " ", MAX_STR - strlen(str) - 1);
        strncat(str, character_get_gdesc(followers[i]), MAX_STR - strlen(str) - 1);
      }

      aux_len1 = strlen(str);
      aux_len2 = strlen(str2);
      if (aux_len1 > LIMIT_2 && aux_len2 > LIMIT_2) { 
        snprintf(strspace[LINE_6], WIDTH_SPACE +1, "|%-7.7s...|%-7.7s...|",str2, str);
      }
      else if(aux_len1 > LIMIT_2){
        snprintf(strspace[LINE_6], WIDTH_SPACE -3, "|%s|%s",str2, str);
        snprintf(strspace[LINE_6], WIDTH_SPACE +2, "%s...|",strspace[LINE_6]);
      }
      else if(aux_len2 > LIMIT_2){
        snprintf(strspace[LINE_6], WIDTH_SPACE - strlen(str)- 4, "|%s",str2);
        snprintf(strspace[LINE_6], WIDTH_SPACE +2, "%s...|%s|",strspace[LINE_6], str);
      }
      else {
        snprintf(strspace[LINE_6], WIDTH_SPACE +1, "|%-10.10s|%-10.10s|",str2, str);
      }
    }
  } 
  
  /* LINEA CON PLAYERS Y CHARACTERS A PARTE */
  str[0] = '\0';
  str2[0] = '\0';
  if((game_get_space_n_nonfollowingcharacters(game, space, player_get_id(player)) <= 0) && (game_get_space_n_nonteamplayers(game, space_id, player) <= 0)){
    sprintf(strspace[LINE_7], "|                     |");
  }
  else if(game_get_space_n_nonfollowingcharacters(game, space, player_get_id(player)) <= 0){
    for (i = 0; i < game_get_space_n_nonteamplayers(game, space_id, player); i++) {
      strncat(str2, " ", MAX_STR - strlen(str2) - 1);
      strncat(str2, player_get_gdesc(non_team[i]), MAX_STR - strlen(str2) - 1);
    }
    snprintf(strspace[LINE_7], WIDTH_SPACE+1 , "|%-21.21s|", str2);
  }
  else if(game_get_space_n_nonteamplayers(game, space_id, player) <= 0){
    for (i = 0; i < game_get_space_n_nonfollowingcharacters(game, space, player_get_id(player)); i++) {
      strncat(str, " ", MAX_STR - strlen(str) - 1);
      strncat(str, character_get_gdesc(charact_space[i]), MAX_STR - strlen(str) - 1);
    }
    snprintf(strspace[LINE_7], WIDTH_SPACE + 1 , "|%21.21s|", str);
  }
  else{
    for (i = 0; i < game_get_space_n_nonfollowingcharacters(game, space, player_get_id(player)); i++) {
      strncat(str, " ", MAX_STR - strlen(str) - 1);
      strncat(str, character_get_gdesc(charact_space[i]), MAX_STR - strlen(str) - 1);
    }
    for (i = 0; i < game_get_space_n_nonteamplayers(game, space_id, player); i++) {
      strncat(str2, " ", MAX_STR - strlen(str2) - 1);
      strncat(str2, player_get_gdesc(non_team[i]), MAX_STR - strlen(str2) - 1);
    }
    aux_len1 = strlen(str);
    aux_len2 = strlen(str2);
    if (aux_len1 > LIMIT_2 && aux_len2 > LIMIT_2) { 
      snprintf(strspace[LINE_7], WIDTH_SPACE +1, "|%-7.7s...|%-7.7s...|",str2, str);
    }
    else if(aux_len1 > LIMIT_2){
      snprintf(strspace[LINE_7], WIDTH_SPACE -3, "|%s|%s",str2, str);
      snprintf(strspace[LINE_7], WIDTH_SPACE +2, "%s...|",strspace[LINE_7]);
    }
    else if(aux_len2 > LIMIT_2){
      snprintf(strspace[LINE_7], WIDTH_SPACE - strlen(str)-4, "|%s",str2);
      snprintf(strspace[LINE_7], WIDTH_SPACE +2, "%s...|%s|",strspace[LINE_7], str);
    }
    else {
      snprintf(strspace[LINE_7], WIDTH_SPACE +1, "|%-10.10s|%-10.10s|",str2, str);
    }
  }
    /*DESCRIPCION DEL MAPA*/

    for (i = 0; i < N_ROWS; i++) {
      sprintf(strspace[i+LINE_8], "|  %17.17s  |", gdesc[i]);
    }

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
          aux_len1= strlen(str);
          if (aux_len1 > LIMIT_1) { 
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
    if(team != NULL){
      free(team);
    }
    if(non_team != NULL){
      free(non_team);
    }

    return strspace;
  }
}

/*--------------------------------------PUBLIC FUNCTIONS--------------------------------------*/


Graphic_engine *graphic_engine_create(void) {
  static Graphic_engine *ge = NULL; /* Assign NULL to *ge only the first time*/

  if (ge) {/* Avoid errors if the function is called multiple times and the graphic engine has already been created. */
    return ge;
  }

  /* Initializates the screen areaa */
  screen_init(HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + HEIGHT_FDB + 5, WIDTH_MAP + WIDTH_DES +WIDTH_CLUES + 4);
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

    /* Initializates the face window area */
  ge->face = screen_area_init(1, HEIGHT_DES + 3 + HEIGHT_BAN, WIDTH_DES, HEIGHT_HLP + HEIGHT_FDB + HEIGHT_MAP - HEIGHT_DES + 1);

    /* Initializates the clues window area */
  ge->clues = screen_area_init( WIDTH_DES + WIDTH_MAP + 3, 2+ HEIGHT_BAN, WIDTH_CLUES , HEIGHT_CLUES );

    /* Initializates the vision window area */
  ge->vision = screen_area_init( WIDTH_DES + WIDTH_MAP + 3, HEIGHT_CLUES + 4, WIDTH_CLUES ,HEIGHT_MAP - HEIGHT_CLUES + HEIGHT_HLP + HEIGHT_FDB + 1);

  if (!ge->map || !ge->descript || !ge->banner || !ge->help || !ge->feedback || !ge->face || !ge->clues || !ge->vision) {
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
  screen_area_destroy(ge->clues);
  screen_area_destroy(ge->vision);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
  /* Declare de needed local variables of the function */
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_left = NO_ID, id_right = NO_ID, *objects_location = NULL, *characters_location = NULL, *player_objects = NULL;
  char str[MAX_STR], character_name[MAX_STR], object_name[MAX_STR];
  char **space_empty = NULL, object[MAX_STR];
  char **space_left = NULL ,**space_right = NULL, **space_back = NULL, **space_next = NULL, **space_actual = NULL, **space1 = NULL, **space2 = NULL, **space3 = NULL;
  int i=0, j=0;
  CommandCode last_cmd = UNKNOWN;
  char cmd_result[MAX_RESULT], *toks = NULL;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  Object **objects = NULL, *obj_aux = NULL;
  Character **characters = NULL, *character = NULL, **followers = NULL;
  Player **team = NULL, **players = NULL;
  char right = '>', left = '<', back = '^', next = 'v';
  char clue[MAX_MESSAGE] ={0}, *vision_line = NULL;

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
      sprintf(str,"        %s   %s   %s", space1[i],space2[i],space3[i]);
      screen_area_puts(ge->map,str);
    }

    sprintf(str, "                                             %c          ",back);
    screen_area_puts(ge->map,str);
    
    space1 = space_left;
    space2 = space_actual;
    space3 = space_right;

    for(i=0; i<MID_SPACE; i++){
      sprintf(str,"        %s   %s   %s", space1[i],space2[i],space3[i]);
      screen_area_puts(ge->map,str);
    }

    sprintf(str,"        %s %c %s %c %s", space1[MID_SPACE],left, space2[MID_SPACE], right, space3[MID_SPACE]);
    screen_area_puts(ge->map,str);

    for(i=MID_SPACE+1; i<HEIGHT_SPACE; i++){
      sprintf(str,"        %s   %s   %s", space1[i],space2[i],space3[i]);
      screen_area_puts(ge->map,str);
    }

    sprintf(str, "                                             %c          ",next);
    screen_area_puts(ge->map,str);
    
    space1 = space_empty;
    space2 = space_next;
    space3 = space_empty;

    for(i=0; i<HEIGHT_SPACE; i++){
      sprintf(str,"        %s   %s   %s", space1[i],space2[i],space3[i]);
      screen_area_puts(ge->map,str);
    }

    /* Paint in the description area */
    screen_area_clear(ge->descript);
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~ INFORMATION ~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

      /*IMPRESION*/
    sprintf(str,"  Player playing (name: id (damage) (health)): " );
    screen_area_puts(ge->descript, str);
    sprintf(str, "    %6.15s : %i (%i) (%i)",player_get_name(game_get_player(game)), (int)player_get_location(game_get_player(game)), player_get_damage(game_get_player(game)),player_get_health(game_get_player(game)));
    screen_area_puts(ge->descript, str);
    sprintf(str,"  Current position: " );
    screen_area_puts(ge->descript, str);
    sprintf(str, "    %s (id: %i)", space_get_name(game_get_space(game,id_act)),(int)player_get_location(game_get_player(game)));
    screen_area_puts(ge->descript, str);
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");


    if(!(players = game_get_players(game))){
      screen_area_puts(ge->descript, "  There are no players");
    }
    else{
     /*IMPRESION*/
      sprintf(str, "  Players (name: location):");
      screen_area_puts(ge->descript, str);
      for(i=0; i< game_get_nplayers(game); i++){
        sprintf(str, "    %s: %s", player_get_name(players[i]), space_get_name(game_get_space(game, player_get_location(players[i]))));
        screen_area_puts(ge->descript, str);
      }
    }
    screen_area_puts(ge->descript, "          ");


    /*PASAMOS ARRAY DE OBJETOS A IDS*/
    
    if(!(objects = game_get_objects_discovered(game))){
      screen_area_puts(ge->descript, "  There are no objects discovered");
    }
    else{
      if(!(objects_location =(Id*)calloc(game_get_n_objects_discovered(game),sizeof(Id)))){
        return;
      }
        for(i=0; i < game_get_n_objects_discovered(game); i++){
          objects_location[i] = game_get_object_location(game, object_get_id(objects[i]));
        }
      
      /*IMPRESION*/
      sprintf(str, "  Objects discovered (name: location):");
      screen_area_puts(ge->descript, str);
      if (objects_location != NULL) {
        for(i=0; i< game_get_n_objects_discovered(game); i++){
          sprintf(str, "    %s: %s [%s]",object_get_name(game_get_object(game,object_get_id(objects[i]))), space_get_name(game_get_space(game, objects_location[i])), object_get_stroffensive(objects[i]));
          screen_area_puts(ge->descript, str);
        }
      }
    }
    screen_area_puts(ge->descript, "          ");

    /*PASAMOS ARRAY DE CHARACTERS A IDS*/
    if(!(characters = game_get_characters_discovered(game))){
      screen_area_puts(ge->descript, "  There are no characters discovered");
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
        sprintf(str, "  Characters discovered (name: location (health)):");
        screen_area_puts(ge->descript, str);
        for(i=0; i< game_get_n_characters_discovered(game); i++){
          if(character_get_following(characters[i]) != player_get_id(game_get_player(game)))
          sprintf(str, "    %.18s: %s (%i) [%s]", character_get_name(characters[i]), space_get_name(game_get_space(game, characters_location[i])) ,character_get_health(characters[i]), character_get_strfriendly(characters[i]));
          screen_area_puts(ge->descript, str);
        }
      }
    }

    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~ BACKPACK ~~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    
    if(player_objects[0]!= NO_ID){
      sprintf(str, "  Player objects:");
      screen_area_puts(ge->descript, str);
      if(inventory_get_n_objs(player_get_backpack(game_get_player(game)))==1){
        obj_aux = game_get_object(game, player_objects[0]);
        if(object_get_offensive(obj_aux) == TRUE){
          strcpy(object, "weapon");
        }
        else{
          strcpy(object, "healing object");
        }
        snprintf(str, MAX_STR, "      %s (%s: %i)", object_get_name(game_get_object(game, player_objects[0])), object, object_get_health(obj_aux));
        screen_area_puts(ge->descript, str);
      }
      if(inventory_get_n_objs(player_get_backpack(game_get_player(game)))>1){
        for(i = 0; i < inventory_get_n_objs(player_get_backpack(game_get_player(game))); i++ ){
          obj_aux = game_get_object(game, player_objects[i]);
          if(object_get_offensive(obj_aux) == TRUE){
            strcpy(object, "weapon");
          }
          else{
            strcpy(object, "healing object");
          }
          snprintf(str, MAX_STR, "      %s (%s: %i)", object_get_name(game_get_object(game, player_objects[i])), object, object_get_health(obj_aux));
          screen_area_puts(ge->descript, str);
        }
      }
    }

    else{
      screen_area_puts(ge->descript, "              You have no objects");
    }  

    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~ FOLLOWERS ~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    if(!(followers = game_get_followingcharacters(game, player_get_id(game_get_player(game))))){
      screen_area_puts(ge->descript, "              There are no followers");
    }
    else{
      screen_area_puts(ge->descript, "     Your followers (name: (damage) (health)):");
      for(i= 0; i<game_get_nfollowingcharacters(game,player_get_id(game_get_player(game))); i++){
        sprintf(str, "         %s: (%i)(%i)", character_get_name(followers[i]), character_get_damage(followers[i]), character_get_health(followers[i]));  
        screen_area_puts(ge->descript,str);
      }
    }
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~ TEAM ~~~~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    if(!(team = game_get_players_in_same_team(game, game_get_player(game)))){
      screen_area_puts(ge->descript, "       You are not cooperating with anyone ");
    }
    else{
      screen_area_puts(ge->descript, "     Your team: (name: (damage) (health)):");
      for(i= 0; i<game_get_n_players_in_same_team(game,game_get_player(game)); i++){
        sprintf(str, "         %s: (%i)(%i)", player_get_name(team[i]), player_get_damage(team[i]), player_get_health(team[i]));  
        screen_area_puts(ge->descript,str);
      }
    }


    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~ MESSAGE ~~~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->descript, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    if(game_get_message(game) != NULL){
      sprintf(str, "%s", game_get_message(game));
      if(str[0] != '\0'){
        screen_area_puts(ge->descript, str);
      }
      else{
        screen_area_puts(ge->descript, "              There is no message");
      }
    }
    else{
      screen_area_puts(ge->descript, "              There is no message");
    }


    /* Paint in the banner area */
    screen_area_puts(ge->banner, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EL CLUB DEL CRIMEN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    /* Paint in the help area */
    screen_area_clear(ge->help);
    screen_area_puts(ge->help, "                                     ");
    sprintf(str, " The commands you can use are:                                                              ");
    screen_area_puts(ge->help, str);
    sprintf(str, " move or m (north/n or south/s or west/w or east/e) | take or t / drop or d (object name)  attack or t / chat or c (character name) | recruit or r / abandon or ab (character name)  use or u [over (character name)] (object name) | open or o (link name) with (object name) cooperate or co with (player name) | abandon team | guess or g | exit or e                save or s / load or l (file_name)");
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


    if((last_cmd == CHAT || last_cmd == RECRUIT || last_cmd == ABANDON || last_cmd == ATTACK) && (command_get_last_cmd_status(game_get_last_command(game)) == OK)){
      strncpy(character_name, command_get_strin(game_get_last_command(game)), MAX_STR);
      if ((strcmp(character_name, "team")!= 0)) {
        character = game_get_character_from_name(game, character_name);
      screen_area_puts(ge->face, "                                     ");
      snprintf(str, MAX_NAME,  "  Character: %s", character_name);
      screen_area_puts(ge->face, str);
      screen_area_puts(ge->face, "                                     ");
      screen_area_puts(ge->face, "             -------------------------   ");
      for(i=0; i < FACE_HEIGHT; i++){
        sprintf(str, "            |   %-19.19s   |", character_get_face(character, i));
        screen_area_puts(ge->face, str);
      }
      screen_area_puts(ge->face, "             -------------------------   ");
      }
    }

    else if((last_cmd == INSPECT || last_cmd == TAKE || last_cmd == DROP || last_cmd == USE || last_cmd == OPEN) && (command_get_last_cmd_status(game_get_last_command(game)) == OK)){
      if(last_cmd == INSPECT || last_cmd == TAKE || last_cmd == DROP){
        strncpy(object_name, command_get_strin(game_get_last_command(game)), MAX_STR);
        obj_aux = game_get_object(game, game_get_object_from_name(game, object_name));
        screen_area_puts(ge->face, "                                     ");
        snprintf(str, MAX_NAME,  "          Object: %s", object_name);
        screen_area_puts(ge->face, str);
        screen_area_puts(ge->face, "          ------------------------------   ");
        for(i=0; i < DRAW_HEIGHT; i++){
          sprintf(str, "         |   %-24.24s   |", object_get_draw(obj_aux, i));
          screen_area_puts(ge->face, str);
        }
        screen_area_puts(ge->face, "          ------------------------------   ");
      }
      else if(last_cmd == USE){

        strncpy(str, command_get_strin(game_get_last_command(game)), MAX_STR);

        toks = strtok(str, " \n");
        if(!strcmp(toks,"over")){
          toks =strtok(str, "\n");
          strcpy(object_name, toks);
        }
        else{
          strcpy(object_name, toks);
        }
        obj_aux = game_get_object(game, game_get_object_from_name(game, object_name));
        screen_area_puts(ge->face, "                                     ");
        snprintf(str, MAX_NAME,  "          Object: %s", object_name);
        screen_area_puts(ge->face, str);
        screen_area_puts(ge->face, "          ------------------------------   ");
        for(i=0; i < DRAW_HEIGHT; i++){
          sprintf(str, "         |   %-24.24s   |", object_get_draw(obj_aux, i));
          screen_area_puts(ge->face, str);
        }
        screen_area_puts(ge->face, "          ------------------------------   ");

      }
      else if(last_cmd == OPEN){
        strncpy(str, command_get_strin(game_get_last_command(game)), MAX_STR);
        toks = strtok(str, " \n");
        toks = strtok(NULL, " \n");
        toks = strtok(NULL, " \n");
        strcpy(object_name, toks);
        obj_aux = game_get_object(game, game_get_object_from_name(game, object_name));
        screen_area_puts(ge->face, "                                     ");
        snprintf(str, MAX_NAME,  "          Object: %s", object_name);
        screen_area_puts(ge->face, str);
        screen_area_puts(ge->face, "          ------------------------------   ");
        for(i=0; i < DRAW_HEIGHT; i++){
          sprintf(str, "         |   %-24.24s   |", object_get_draw(obj_aux, i));
          screen_area_puts(ge->face, str);
        }
        screen_area_puts(ge->face, "          ------------------------------   ");

      }
    }

    screen_area_clear(ge->clues);

    screen_area_puts(ge->clues, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CLUES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->clues, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    if(last_cmd == CHAT && (command_get_last_cmd_status(game_get_last_command(game)) == OK)){
      strcpy(clue, game_get_message(game));
      if(game_clue_is_stored(game, clue) == FALSE){
        game_add_clue(game, clue);
      }
    }
    for(i= 0; i< game_get_nclues(game); i++){
      snprintf(str, MAX_STR, " Pista %i: %s", i+1 , game_get_clue(game,i));
      screen_area_puts(ge->clues, str);
    }
    
    /*VISION AREA*/
    screen_area_puts(ge->vision, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->vision, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ VISION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    screen_area_puts(ge->vision, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    for(i=0; i < VIS_HEIGHT; i++){
      vision_line = space_get_vision(game_get_space(game, id_act), i);
      if(vision_line[0] != '\0'){
        sprintf(str, " %-68.68s", space_get_vision(game_get_space(game, id_act), i));
        screen_area_puts(ge->vision, str);
      }
      else{
        screen_area_puts(ge->vision, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      }
    }


    /* PAINT THE COLOR */    
    screen_paint(game_get_turn(game));
    printf("prompt turn %i:> ", game_get_turn(game));

    /* PONER FREES DE LOS ESPACIOS */
    if (space_back != space_empty) {
      graphic_engine_free_space(space_back);
    }
    if (space_next != space_empty) {
      graphic_engine_free_space(space_next);
    }
    if (space_right != space_empty) {
      graphic_engine_free_space(space_right);
    }
    if (space_left != space_empty) {
      graphic_engine_free_space(space_left);
    }
    if (space_actual != space_empty) {
      graphic_engine_free_space(space_actual);
    }
    if (space_empty != NULL) {
      graphic_engine_free_space(space_empty);
    }

    free(objects_location);
    free(objects);
    free(characters_location);
    free(characters);
  }
  
}

void graphic_engine_clear_face(Graphic_engine *ge){
  if(!ge) return;
  screen_area_clear(ge->face);
  return;
}
  
