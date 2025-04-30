/** 
 * @brief It declares the tests for the inventory module
 * 
 * @file inventory_test.h
 * @author Jimena Sanchiz
 * @version 0.0 
 * @date 25-03-2025
 * @copyright GNU Public License
 */

 #ifndef INVENTORY_TEST_H
 #define INVENTORY_TEST_H
 
 #include "test.h"
 #include "inventory.h"

 /**
 * @test Test inventory creation
 * @pre Valid inventory ID
 * @post Non NULL pointer to inventory
 */
void test1_inventory_create();

/**
 * @test Test inventory creation
 * @pre Invalid inventory ID (NO_ID)
 * @post Output == NULL
 */
void test2_inventory_create();

 /**
 * @test Test function for adding an object id to the inventory
 * @pre Valid object pointer and ID
 * @post Output == OK
 */
void test1_inventory_add_obj_id();

 /**
 * @test Test function for adding an object id to the inventory
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_inventory_add_obj_id();

 /**
 * @test Test function for deleting an object id from the inventory
 * @pre Valid object pointer and ID
 * @post Output == OK
 */
void test1_inventory_delete_obj_id();

 /**
 * @test Test function for deleting an object id from the inventory
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_inventory_delete_obj_id();

 /**
 * @test Test function for setting the maximum number of ids in the inventory
 * @pre Valid object pointer and ID
 * @post Output == OK
 */
void test1_inventory_set_max_objs();

 /**
 * @test Test function for setting the maximum number of ids in the inventory
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_inventory_set_max_objs();

 /**
 * @test Test function for getting the maximum number of ids in the inventory
 * @pre Valid object pointer
 * @post Output != NO_ID
 */
void test1_inventory_get_max_objs();

 /**
 * @test Test function for getting the maximum number of ids in the inventory
 * @pre NULL object pointer
 * @post Output == NO_ID
 */
void test2_inventory_get_max_objs();

 /**
 * @test Test function for getting the number of object ids in the inventory
 * @pre Valid object pointer
 * @post Output != NO_ID
 */
void test1_inventory_get_n_objs();

 /**
 * @test Test function for getting the number of object ids in the inventory
 * @pre NULL object pointer
 * @post Output == NO_ID
 */
void test2_inventory_get_n_objs();

 /**
 * @test Test function for getting the array of object ids in the inventory
 * @pre Valid object pointer
 * @post Output != NO_ID
 */
void test1_inventory_get_obj_ids();

 /**
 * @test Test function for getting the array of object ids in the inventory
 * @pre NULL object pointer
 * @post Output == NO_ID
 */
void test2_inventory_get_obj_ids();

/**
 * @test Test function for getting if the object is in the inventory
 * @pre Valid inventory pointer
 * @post Output == Expected value
 */
void test1_object_is_in_inventory();

/**
 * @test Test function for getting if the object is in the inventory
 * @pre NULL inventory pointer
 * @post Output == FALSE
 */
void test2_object_is_in_inventory();

 #endif
