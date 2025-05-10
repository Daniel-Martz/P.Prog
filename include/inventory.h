/**
 * @brief It defines the Inventory module
 * 
 * @file inventory.h
 * @author Jimena Sanchiz y Jaime
 * 
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"
#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Structure of the inventory
 * 
 */
typedef struct _Inventory Inventory;

/**
 * @brief Creates the strcuture 'Inventory', allocating memory and initializing its arguments
 * 
 * @author Jimena Sanchiz
 * 
 * @return A pointer to inventory with the structure (and its arguments) created
 */
Inventory *inventory_create(void);

/**
 * @brief "Destroys" the inventory's elements and frees its memory
 * 
 * @author Jimena Sanchiz
 * 
 * @param inventory A pointer to the structure
 * 
 * @return OK if everything worked correctly, ERROR if it didn't
 */
Status inventory_destroy(Inventory *inventory);

/**
 * @brief Adds a new object id to the array of elements in inventory
 * @author Jimena Sancbiz
 * 
 * @param inventory A pointer to Inventory structure
 * @param obj_id The new id which is going to be added
 * 
 * @return OK if everything worked correctly, ERROR if it didn't
 */
Status inventory_add_obj_id(Inventory *inventory, Id obj_id);

/**
 * @brief Deletes an element from the array of ids in inventory
 * 
 * @author Jimena Sanchiz
 * 
 * @param inventory A pointer to Inventor structure
 * @param obj_id The new id which is going to be deleted
 * 
 * @return OK if everything worked correctly, ERROR if it didn't
 */
Status inventory_delete_obj_id(Inventory *inventory, Id obj_id);

/**
 * @brief This function sets the maximum number of objects ids in the inventory
 * 
 * @author Jimena Sanchiz
 * 
 * @param inventory A pointer to Inventory structure
 * @param max_objs The maximum number of objects ids in the inventory
 * 
 * @return OK if everything worked correctly, ERROR if it didn't
 */
Status inventory_set_max_objs(Inventory *inventory, int max_objs);

/**
 * @brief This function gets the maximum number of objects ids in the inventory
 * 
 * @author Jimena Sanchiz
 * 
 * @param inventory A pointer to Inventory structure
 * 
 * @return -1 if there was a problem, and the number of max_obj in the inventory if everything was OK.
 */
int inventory_get_max_objs(Inventory *inventory);

/**
 * @brief This function gets the number of objects ids in the inventory
 * 
 * @author Jimena Sanchiz
 * 
 * @param inventory A pointer to Inventory structure
 * 
 * @return -1 if there was a problem, and the number of objects ids in the inventory if everything was OK.
 */
int inventory_get_n_objs(Inventory *inventory);

/**
 * @brief This function gets the array of objects ids in the inventory
 * 
 * @author Jimena Sanchiz
 * 
 * @param inventory A pointer to Inventory structure
 * 
 * @return NULL if there was a problem, and the array of objects ids in the inventory if everything was OK.
 */
Id *inventory_get_obj_ids(Inventory *inventory);

/**
 * @brief Prints the elements of the inventory
 * 
 * @author Jimena Sanchiz
 * 
 * @param inventory A pointer to Inventory structure
 * 
 * @return OK if everything worked correctly, ERROR if it didn't
 */
Status inventory_print(Inventory *inventory);

/**
 * @brief Checks if a given object is already in the inventory
 * 
 * @author Jaime Romero
 * 
 * @param inv A pointer to Inventory structure
 * @param id Id of the object to search
 * 
 * @return OK if it is already in the inventory an ERROR if not
 */
Status inventory_object_is_there(Inventory *inv, Id id);

#endif
