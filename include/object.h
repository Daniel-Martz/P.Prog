/**
 * @brief It defines the object module
 * 
 * @file object.h
 * @author Jaime Romero
 * 
 * @version 0.1
 * @date 2025-02-08
 * 
 * @copyright Copyright (c) 2025
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 50/*!< The maximum size for objects names*/
#define MAX_DESCRIP 100/*!< The maximum size for the objects descriptions*/
#define DRAW_HEIGHT 14/*!<Constant for the height of the character's draw*/
#define DRAW_WIDTH 25/*!<Constant for the width of the character's draw*/

/**
 * @brief Structure of the object
 * 
 */
typedef struct _Object Object;

/**
 * @brief Creates a new object from a given Id and name
 * 
 * @author Jaime Romero
 * 
 * @param id Object identifier
 * 
 * @return The created object
 */
Object* object_create (Id id);

/**
 * @brief Destroys an object and frees memory
 * 
 * @author Jaime Romero
 * 
 * @param obj A pointer to the object that needs to be destroyed
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status object_destroy(Object* obj);

/**
 * @brief Gets the Id of an object
 * 
 * @author Jaime Romero
 * 
 * @param obj A pointer to the object
 * 
 * @return The Id of the object
 */
Id object_get_id(Object* obj); 

/**
 * @brief Assigns an Id to an object. I'm not sure if this function 
 * is necessary since it is not in space.h
 * 
 * @author Jaime Romero
 * 
 * @param obj A pointer to the object
 * @param id A variable for the object's Id
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status object_set_id (Object* obj, Id id);

/**
 * @brief Assigns a name to an object
 * 
 * @author Jaime Romero
 * 
 * @param obj A pointer to the object
 * @param name A string with the object's name
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status object_set_name (Object* obj, char* name);

/**
 * @brief Gets the name of the object
 * 
 * @author Jaime Romero
 *
 * @param obj A pointer to the object
 * @return A string with the object's name
 */
const char* object_get_name (Object* obj);

/**
 * @brief Prints the object's information  
 * The function displays the Id and name of the object
 * 
 * @author Jaime Romero
 * 
 * @param obj A pointer to the object
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status object_print (Object* obj);

/**
 * @brief Gets the description of the object
 * 
 * @author Jaime Romero
 *
 * @param obj A pointer to the object
 * @return A string with the object's description
 */
const char* object_get_description(Object *obj);

/**
 * @brief Assigns a description to an object
 * 
 * @author Jaime Romero
 * 
 * @param obj A pointer to the object
 * @param objdes A string with the object's description
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status object_set_description(Object *obj, const char *objdes);

/**
 * @brief Assigns health to an object
 * 
 * @author Jaime Romero
 * 
 * @param obj A pointer to the object
 * @param health The amount of health taken o given to the player
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status object_set_health(Object *obj, int health);

/**
 * @brief Gets the health managed by the object
 * @author Jaime Romero
 * 
 * @param obj A pointer to Object
 * @return The amount of health the object takes or gives
 */
int object_get_health(Object *obj);

/**
 * @brief Sets if the object is movable or not
 * 
 * @author Jaime Romero
 * 
 * @param obj A pointer to the object
 * @param mov A boolean variable indicating if the object can be moved
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status object_set_movable(Object *obj, Bool mov);

/**
 * @brief Gets if the object is movable or not
 * @author Jaime Romero
 * 
 * @param obj A pointer to Object
 * @return TRUE if it's movable, FALSE if not
 */
Bool object_is_movable(Object *obj);

/**
 * @brief Sets if the object depends on other objects
 * 
 * @author Jaime Romero
 * 
 * @param obj A pointer to the object
 * @param dependency An id of the object it depends on (NO_ID if it odesn't depend on anything)
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status object_set_dependency(Object *obj, Id dependency);

/**
 * @brief Gets if the object is depends on anything
 * @author Jaime Romero
 * 
 * @param obj A pointer to Object
 * @return The id of the object id depends on
 */
Id object_get_dependency(Object *obj);

/**
 * @brief Sets if the object can open other links
 * 
 * @author Jaime Romero
 * 
 * @param obj A pointer to the object
 * @param open An id of the link it opens (NO_ID if it odesn't open anything)
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status object_set_open(Object *obj, Id open);

/**
 * @brief Gets the link that can be opened by the object
 * @author Jaime Romero
 * 
 * @param obj A pointer to Object
 * @return An id of the link it can open
 */
Id object_get_open(Object *obj);

/**
 * @brief Sets if the object is offensive or not
 * 
 * @author Jimena Sanchiz
 * 
 * @param obj A pointer to the object
 * @param mov A boolean variable indicating if the object is offensive
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status object_set_offensive(Object *obj, Bool offensive);

/**
 * @brief Gets if the object is offensive or not
 * @author Jimena Sanchiz
 * 
 * @param obj A pointer to Object
 * @return TRUE if it's offensive, FALSE if not
 */
Bool object_get_offensive(Object *obj);

/**
 * @brief Gets if the object is offensive or not
 * @author Daniel Martínez
 * 
 * @param obj A pointer to Object
 * @return "weapon" if it's offensive, "healing object" if not
 */
const char* object_get_stroffensive(Object *object);

/**
 * @brief Sets the a matrix of characters that is the real description of the object
 * @author Daniel Martínez
 *
 * @param object A pointer to Object
 * @param draw The matrix of chars for the draw of the object
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status object_set_draw(Object *object, const char draw[DRAW_HEIGHT][DRAW_WIDTH]);

/**
 * @brief Gets a row of the real description of an object
 * @author Daniel Martínez
 *
 * @param object A pointer to object
 * @param row the row of the matrix
 * @return a string with a line of the object description
 */
const char* object_get_draw(Object* object, int row);

#endif

