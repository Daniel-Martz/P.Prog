/**
 * @brief It defines the space module interface
 *
 * @file space.h
 * @author Daniel Martinez y Jaime Romero
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

#define N_ROWS 5  /*Number of rows in the description*/
#define N_COLUMNS 10 /*9 plus a space for '\0'*/
#define MAX_DESC 9 /*the maximum size for gdesc*/

typedef struct _Space Space;

/*=======================Create and Destroy========================*/

/**
 * @brief It creates a new space, allocating memory and initializing its members
 * @author Daniel Martinez
 *
 * @param id the identification number for the new space
 * @return a new space, initialized
 */
Space* space_create(Id id);

/**
 * @brief It destroys a space, freeing the allocated memory
 * @author Daniel Martinez
 *
 * @param space a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_destroy(Space* space);

/*============================Set============================*/

/**
 * @brief It sets the name of a space
 * @author Daniel Martinez
 *
 * @param space a pointer to the space
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_name(Space* space, char* name);

/**
 * @brief This set the character of the space
 * 
 * @author Daniel Martínez
 * 
 * @param space A pointer to Space structure
 * @param id The id of the character
 * 
 * @return ERROR if there was a problem, OK if everything was good
 */
Status space_set_character(Space *space, Id id);

/**
 * @brief This set a new object to the space
 * 
 * @author Daniel Martínez
 * 
 * @param space A pointer to Space structure
 * @param id The id of the object
 * 
 * @return ERROR if there was a problem, OK if everything was good
 */
Status space_set_new_object(Space* space, Id object_id);

/**
 * @brief Defines the new space's description
 * @author Jaime Romero
 *
 * @param space A pointer to space
 * @param new_gdesc space's description
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status space_set_gdesc (Space* space, const char new_gdesc[N_ROWS][N_COLUMNS]);

/**
 * @brief This delete an object from the space
 * 
 * @author Daniel Martínez
 * 
 * @param space A pointer to Space structure
 * @param id The id of the object
 * 
 * @return ERROR if there was a problem, OK if everything was good
 */
Status space_object_del(Space *space, Id object_id);

/**
 * @brief It sets if the space was discovered or not
 * 
 * @author Jimena Sanchiz
 * 
 * @param space A pointer to Space structure
 * @param discovered the boolean that shows if the space was discovered or not
 * 
 * @return ERROR if there was a problem, OK if everything was good
 */
Status space_set_discovered(Space *space, Bool discovered);

/*============================Get============================*/

/**
 * @brief It gets the id of a space
 * @author Daniel Martinez
 *
 * @param space a pointer to the space
 * @return the id of space
 */
Id space_get_id(Space* space);

/**
 * @brief It gets the name of a space
 * @author Daniel Martinez
 *
 * @param space a pointer to the space
 * @return  a string with the name of the space
 */
const char* space_get_name(Space* space);

/**
 * @brief This function gets the number of ids that there are in the space
 * 
 * @author Daniel Martínez
 * 
 * @param space A pointer to the space
 * 
 * @return 0 if there was a problem or no objects, and the number of objects in the space if everything was OK.
 */
long space_get_nobjects(Space* space);

/**
 * @brief This function check if an object is in the space
 * 
 * @author Daniel Martínez
 * 
 * @param space A pointer to Space structure
 * @param object_id The object id we want to check
 * 
 * @return ERROR if there was a problem or id is not in the space, OK if the object is in the space
 */
Status space_object_is_there(Space* space, Id object_id);

/**
 * @brief This get the array of objects ids in the space
 * 
 * @author Daniel Martínez
 * 
 * @param space A pointer to space
 * 
 * @return NULL if there was a problem, or the array of objects ids if everything was OK.
 */
Id* space_get_objects_ids(Space* space);

/**
 * @brief This get the id of the character in the space
 * 
 * @author Daniel Martínez
 * 
 * @param space A pointer to Space structure
 * 
 * @return NO_ID if there was a problem or there is no caharacter in the sapce, or the character id of the space.
 */
Id space_get_character(Space *space);

/**
 * @brief Gets the game's description (game's interface)
 * @author Jaime Romero
 *
 * @param space A pointer to Space
 * @param row the row of the array
 * @return a string with the description of the space
 */
const char* space_get_gdesc(Space* space, int row);

/**
 * @brief Gets if the space was discovered or not (game's interface)
 * @author Jimena Sanchiz
 *
 * @param space A pointer to Space
 * @return if the space was discovered or not
 */
Bool space_get_discovered(Space *space);

/*============================Print============================*/

/**
 * @brief It prints the space information This functions shows the id and name 
 * of the space, the graphic descripction, whether it has an object or not, whether it has a character or not and whether it was discovered or not.
 * @author Daniel Martinez
 * 
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_print(Space* space);

#endif
