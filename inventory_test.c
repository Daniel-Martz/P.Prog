/** 
 * @brief It tests the inventory module
 * 
 * @file inventory_test.c
 * @author Jimena Sanchiz
 * @version 0.0 
 * @date 25-03-2025
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "inventory_test.h"

#define MAX_TESTS 14/*It defines the number of tests*/
#define TEST 10

/** 
 * @brief Main function for inventory unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1)test1_inventory_create();
  if (all || test == 2)test2_inventory_create();
  if (all || test == 3)test1_inventory_add_obj_id();
  if (all || test == 4)test2_inventory_add_obj_id();
  if (all || test == 5)test1_inventory_delete_obj_id();
  if (all || test == 6)test2_inventory_delete_obj_id();
  if (all || test == 7)test1_inventory_set_max_objs();
  if (all || test == 8)test2_inventory_set_max_objs();
  if (all || test == 9)test1_inventory_get_max_objs();
  if (all || test == 10)test2_inventory_get_max_objs();
  if (all || test == 11)test1_inventory_get_n_objs();
  if (all || test == 12)test2_inventory_get_n_objs();
  if (all || test == 13)test1_inventory_get_obj_ids();
  if (all || test == 14)test2_inventory_get_obj_ids();
  
  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_inventory_create() {
    int result;
    Inventory *i = NULL;
    i = inventory_create();
    result=(i!=NULL);
    PRINT_TEST_RESULT(result);
    inventory_destroy(i);
}

void test2_inventory_create() {
    int result;
    Inventory *i=NULL;
    i = inventory_create();
    result = (inventory_get_n_objs(i) == 0);
    PRINT_TEST_RESULT(result);
    inventory_destroy(i);
}

void test1_inventory_add_obj_id() {
    Inventory *i;
    i = inventory_create();
    PRINT_TEST_RESULT(inventory_add_obj_id(i, TEST) == OK);
    inventory_destroy(i);
}

void test2_inventory_add_obj_id() {
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_add_obj_id(i, TEST) == ERROR);
}

void test1_inventory_delete_obj_id() {
    Inventory *i;
    i = inventory_create();
    inventory_add_obj_id(i, TEST);
    PRINT_TEST_RESULT(inventory_delete_obj_id(i, TEST) == OK);
    inventory_destroy(i);
}

void test2_inventory_delete_obj_id() {
    Inventory *i = NULL;
    inventory_add_obj_id(i, TEST);
    PRINT_TEST_RESULT(inventory_delete_obj_id(i, TEST) == ERROR);
}

void test1_inventory_set_max_objs() {
    Inventory *i;
    i = inventory_create();
    PRINT_TEST_RESULT(inventory_set_max_objs(i, TEST) == OK);
    inventory_destroy(i);
}

void test2_inventory_set_max_objs() {
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_set_max_objs(i, TEST) == ERROR);
}

void test1_inventory_get_max_objs() {
    Inventory *i;
    i = inventory_create();
    inventory_set_max_objs(i, TEST);
    PRINT_TEST_RESULT(inventory_get_max_objs(i) == TEST);
    inventory_destroy(i);
}

void test2_inventory_get_max_objs() {
    Inventory *i = NULL;
    inventory_set_max_objs(i, TEST);
    PRINT_TEST_RESULT(inventory_get_max_objs(i) == -1);
}

void test1_inventory_get_n_objs() {
    Inventory *i;
    i = inventory_create();
    inventory_add_obj_id(i, TEST);
    PRINT_TEST_RESULT(inventory_get_n_objs(i) == 1);
    inventory_destroy(i);
}

void test2_inventory_get_n_objs() {
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_get_n_objs(i) == POINT_ERROR);
}

void test1_inventory_get_obj_ids() {
    Inventory *i;
    int j, result = 1;
    Id array[5]={1,2,3,4,5}, *arrayaux=NULL;

    i = inventory_create();
    inventory_add_obj_id(i, 1);
    inventory_add_obj_id(i, 2);
    inventory_add_obj_id(i, 3);
    inventory_add_obj_id(i, 4);
    inventory_add_obj_id(i, 5);

    arrayaux = inventory_get_obj_ids(i);
    for(j=0; j< inventory_get_n_objs(i); j++){
        if(arrayaux[j] != array[j]){
            result = 0;
            break;
        }
    }
    PRINT_TEST_RESULT(result);
    inventory_destroy(i);
}

void test2_inventory_get_obj_ids() {
    Inventory *i=NULL;
    inventory_add_obj_id(i, TEST);
    PRINT_TEST_RESULT(inventory_get_obj_ids(i) == NULL);
}
