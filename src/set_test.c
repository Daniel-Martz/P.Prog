/** 
 * @brief It tests set module
 * 
 * @file set_test.c
 * @author Jaime Romero
 * @version 0.1 
 * @date 2025-02-18
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "set_test.h"

#define MAX_TESTS 13 /*!< It defines the number of tests*/

/** 
 * @brief Main function for set unit tests. 
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
    printf("Running all test for module Set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }
  
  if (all || test == 1) test1_set_create();
  if (all || test == 2) test2_set_create();
  if (all || test == 3) test1_set_add();
  if (all || test == 4) test2_set_add();
  if (all || test == 5) test1_set_del();
  if (all || test == 6) test2_set_del();
  if (all || test == 7) test1_set_get_nids();
  if (all || test == 8) test2_set_get_nids();
  if (all || test == 9) test3_set_get_nids();
  if (all || test == 10) test1_set_id_is_there();
  if (all || test == 11) test2_set_id_is_there();
  if (all || test == 12) test1_set_get_ids();
  if (all || test == 13) test2_set_get_ids();
  
  PRINT_PASSED_PERCENTAGE;

  return 0;
}

/* CREATE TESTS */
void test1_set_create() {
    Set *s = set_create();
    PRINT_TEST_RESULT(s != NULL);
    set_destroy(s);
}

void test2_set_create() {
    Set *s = set_create();
    PRINT_TEST_RESULT(set_get_nids(s) == 0);
    set_destroy(s);
}

/* ADD TESTS */
void test1_set_add() {
    Set *s = set_create();
    PRINT_TEST_RESULT(set_add(s, 1) == OK);
    set_destroy(s);
}

void test2_set_add() {
    Set *s = set_create();
    set_add(s, 1);
    PRINT_TEST_RESULT(set_add(s, 1) == ERROR); /* Test duplicate addition */
    set_destroy(s);
}

/* DELETE TESTS */
void test1_set_del() {
    Set *s = set_create();
    set_add(s, 1);
    PRINT_TEST_RESULT(set_del(s, 1) == OK);
    set_destroy(s);
}

void test2_set_del() {
    Set *s = set_create();
    PRINT_TEST_RESULT(set_del(s, 1) == ERROR); /* Test deletion from empty set */
    set_destroy(s);
}

/* GET NUMBER OF IDs TESTS */
void test1_set_get_nids() {
    Set *s = set_create();
    PRINT_TEST_RESULT(set_get_nids(s) == 0);
    set_destroy(s);
}

void test2_set_get_nids() {
    Set *s = set_create();
    set_add(s, 1);
    PRINT_TEST_RESULT(set_get_nids(s) == 1);
    set_destroy(s);
}

void test3_set_get_nids() {
    Set *s = set_create();
    set_add(s, 1);
    set_del(s, 1);
    PRINT_TEST_RESULT(set_get_nids(s) == 0);
    set_destroy(s);
}

/* ID PRESENCE TESTS */
void test1_set_id_is_there() {
    Set *s = set_create();
    set_add(s, 1);
    PRINT_TEST_RESULT(set_id_is_there(s, 1) == OK);
    set_destroy(s);
}

void test2_set_id_is_there() {
    Set *s = set_create();
    PRINT_TEST_RESULT(set_id_is_there(s, 1) == ERROR);
    set_destroy(s);
}

/* GET IDs ARRAY TESTS */
void test1_set_get_ids() {
    Set *s = set_create();
    Id test_ids[5] = {1, 2, 3, 4, 5};
    Id *retrieved_ids;
    int i, result = 1;
    
    for (i = 0; i < 5; i++) {
        set_add(s, test_ids[i]);
    }
    
    retrieved_ids = set_get_ids(s);
    for (i = 0; i < 5; i++) {
        if (retrieved_ids[i] != test_ids[i]) {
            result = 0;
            break;
        }
    }
    
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}

void test2_set_get_ids() {
    Set *s = set_create();
    Id *retrieved_ids = set_get_ids(s);
    int i, result = 1;
    
    for (i = 0; i < MAX_SET; i++) {
        if (retrieved_ids[i] != NO_ID) {
            result = 0;
            break;
        }
    }
    
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}