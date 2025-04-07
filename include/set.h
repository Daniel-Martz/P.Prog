/**
 * @brief It defines the Set module (Set structure and its functions)
 * 
 * @file set.h
 * @author Jaime Romero
 * 
 * @version 0.1
 * @date 2025-02-18
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef SET_H
#define SET_H

#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SET 100/*!< Maximum number of sets*/

/**
 * @brief Structure of the set
 * 
 */
typedef struct _Set Set;

/**
 * @brief Creates the strcuture 'Set', allocating memory and initializing its arguments
 * 
 * @author Jaime Romero
 * 
 * @return A pointer to set with the structure (and its arguments) created
 */
Set* set_create (void);

/**
 * @brief "Destroys" the set of elements and frees its memory
 * 
 * @author Jaime Romero
 * 
 * @param set A pointer to the structure
 * 
 * @return OK if everything worked correctly, ERROR if it didn't
 */
Status set_destroy (Set* set);

/**
 * @brief Prints the array of elements (ids) 
 * 
 * @author Jaime Romero
 * 
 * @param set A pointer to Set structure
 * 
 * @return OK if everything worked correctly, ERROR if it didn't
 */
Status set_print (Set* set);

/**
 * @brief Adds a new element to the array of elements in set
 * @author Jaime Romero
 * 
 * @param set A pointer to Set structure
 * @param id The new id which is going to be added
 * 
 * @return OK if everything worked correctly, ERROR if it didn't
 */
Status set_add (Set* set, Id id);

/**
 * @brief Deletes an element from the array of ids in set
 * 
 * @author Jaime Romero
 * 
 * @param set A pointer to Set structure
 * @param id The Id which is going to be deleted
 * 
 * @return OK if everything worked correctly, ERROR if it didn't
 */
Status set_del (Set* set, Id id);

/**
 * @brief This function gets the number of ids that there are in the set
 * 
 * @author Daniel Martínez
 * 
 * @param set A pointer to Set structure
 * 
 * @return -1 if there was a problem, and the number of ids in the set if everything was OK.
 */
long set_get_nids(Set* set);

/**
 * @brief This function check if an id is in the set
 * 
 * @author Daniel Martínez
 * 
 * @param set A pointer to Set structure
 * @param id The id we want to check
 * 
 * @return ERROR if there was a problem or id is not in the set, OK if id is in the set
 */
Status set_id_is_there(Set* set, Id id);

/**
 * @brief This get the array of ids in the set
 * 
 * @author Daniel Martínez
 * 
 * @param set A pointer to Set structure
 * 
 * @return NULL if there was a problem, or the array of ids if everything was OK.
 */
Id* set_get_ids(Set* set);

#endif
