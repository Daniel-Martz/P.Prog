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

void test1_inventory_create();
void test2_inventory_create();
void test1_inventory_add_obj_id();
void test2_inventory_add_obj_id();
void test1_inventory_delete_obj_id();
void test2_inventory_delete_obj_id();
void test1_inventory_set_max_objs();
void test2_inventory_set_max_objs();
void test1_inventory_get_max_objs();
void test2_inventory_get_max_objs();
void test1_inventory_get_n_objs();
void test2_inventory_get_n_objs();
void test1_inventory_get_obj_ids();
void test2_inventory_get_obj_ids();

 #endif
