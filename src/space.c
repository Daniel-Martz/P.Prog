/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Daniel Martinez
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "space.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief This struct stores all the information of a space.
 *
 * @author Daniel Martinez
 */
struct _Space {
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Set *objects;              /*!< It contains the set of the arrays of object */
  Id character;              /*!< It contains the id of the character */
  char gdesc[N_ROWS][N_COLUMNS]; /*!< An array of five strings, with 9 characters each (+1 for the '\0')*/
  Bool discovered;/*!< It contains if the space is discovered or not*/
};

/*=======================Create and Destroy========================*/
Space* space_create(Id id) {
  Space* newSpace = NULL;
  int i=0;

  /* Error control */
  if (id == NO_ID) return NULL;

  newSpace = (Space*)malloc(sizeof(Space));
  if (newSpace == NULL) {
    return NULL;
  }

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->character = NO_ID;
  for (i = 0; i < 5; i++)
  {
    newSpace->gdesc[i][0] = '\0';
  }
  newSpace->objects = set_create();
  newSpace->discovered = FALSE;

  return newSpace;
}

Status space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }

  set_destroy(space->objects);
  free(space);
  
  return OK;
}

/*============================Set============================*/
Status space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }
  return OK;
}

Status space_set_new_object(Space* space, Id object_id) {
  if (!space) {
    return ERROR;
  }

  if(set_add(space->objects, object_id) == ERROR){ /*Esta función está mal, hay que pasar un puntero a set, no space->objects*/
    return ERROR;
  }
  return OK;
}

Status space_set_character(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->character = id;
  return OK;
}

Status space_set_gdesc (Space* space, const char new_gdesc[N_ROWS][N_COLUMNS]){
  int i=0;

  if (!space || new_gdesc == NULL)
  {
    return ERROR; 
  }
  
  /*Copy in the game description the new game description, copying only 9 characters plus '\0'*/
  for (i = 0; i < N_ROWS; i++)
  {
    /*Check if the number of characters in the new description is equal to 9 to avoid errors*/
    if (strlen(new_gdesc[i]) != MAX_DESC) return ERROR;
    
    strncpy(space->gdesc[i], new_gdesc[i], N_COLUMNS); 
  }
  
  return OK;
}

Status space_object_del(Space *space, Id object_id){
  if(!space || (object_id == NO_ID)){
    return ERROR;
  }
  set_del(space->objects, object_id);
  return OK;
}

Status space_set_discovered(Space *space, Bool discovered) {
  if (!space) {
    return ERROR;
  }
  space->discovered = discovered;
  return OK;

}

/*============================Get============================*/
Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

const char* space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

Status space_object_is_there(Space* space, Id object_id) {
  if (!space) {
    return ERROR;
  }

  return set_id_is_there(space->objects, object_id);
}

long space_get_nobjects(Space* space){
  if(!space) return POINT_ERROR;
  
  return set_get_nids(space->objects);
}

Id* space_get_objects_ids(Space* space){
  if(!space) return NULL;

  return set_get_ids(space->objects);
}

Id space_get_character(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->character;
}

const char* space_get_gdesc(Space* space, int row){
  if (!space || row < 0 || row >= N_ROWS) return NULL;

  return space->gdesc[row];
}


Bool space_get_discovered(Space *space) {
  if (!space) {
    return FALSE;
  }
  return space->discovered;
}

/*============================Print============================*/
Status space_print(Space* space) {
  int i=0;

  /* Error Control */
  if (!space) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  /*2. Print the new graphic description*/
  for (i = 0; i < N_ROWS; i++) {
      fprintf(stdout, "%s\n", space->gdesc[i]);
  }

  /* 4. Print if there is an object in the space or not */
  if (space_get_nobjects(space)) {
    fprintf(stdout, "---> There is an object in the space.\n");
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }

  /* 5. Print if there is a character in the space or not */
  if (space_get_character(space) != NO_ID) {
    fprintf(stdout, "---> There is a character in the space.\n");
  } else {
    fprintf(stdout, "---> No character in the space.\n");
  }

   /* 6. Prints if the space was discovered or not */
   if(space_get_discovered(space) == TRUE) {
    fprintf(stdout, "---> The space was discovered.\n");
   } else {
    fprintf(stdout, "---> The space was not discovered.\n");
   }
  

  return OK;
}
