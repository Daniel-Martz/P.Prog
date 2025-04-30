/** 
 * @brief It tests character module
 * 
 * @file character_test.c
 * @author Jaime Romero
 * @version 0.1 
 * @date 2025-02-24
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "character_test.h"

#define MAX_TESTS 34 /*!< It defines the number of tests*/

/** 
 * @brief Main function for character unit tests. 
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
    printf("Running all test for module Character:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_character_create();
  if (all || test == 2) test2_character_create();
  if (all || test == 3) test1_character_get_id();
  if (all || test == 4) test2_character_get_id();
  if (all || test == 5) test1_character_get_name();
  if (all || test == 6) test2_character_get_name();
  if (all || test == 7) test1_character_get_gdesc();
  if (all || test == 8) test2_character_get_gdesc();
  if (all || test == 9) test1_character_get_message();
  if (all || test == 10) test2_character_get_message();
  if (all || test == 11) test1_character_get_health();
  if (all || test == 12) test2_character_get_health();
  if (all || test == 13) test1_character_get_friendly();
  if (all || test == 14) test2_character_get_friendly();
  if (all || test == 15) test1_character_get_following();
  if (all || test == 16) test2_character_get_following();
  if (all || test == 17) test1_character_set_id();
  if (all || test == 18) test2_character_set_id();
  if (all || test == 19) test1_character_set_name();
  if (all || test == 20) test2_character_set_name();
  if (all || test == 21) test3_character_set_name();
  if (all || test == 22) test1_character_set_gdesc();
  if (all || test == 23) test2_character_set_gdesc();
  if (all || test == 24) test3_character_set_gdesc();
  if (all || test == 25) test1_character_set_health();
  if (all || test == 26) test2_character_set_health();
  if (all || test == 27) test3_character_set_health();
  if (all || test == 28) test1_character_set_friendly();
  if (all || test == 29) test2_character_set_friendly();
  if (all || test == 30) test1_character_set_message();
  if (all || test == 31) test2_character_set_message();
  if (all || test == 32) test3_character_set_message();
  if (all || test == 33) test1_character_set_following();
  if (all || test == 34) test2_character_set_following();
  
  PRINT_PASSED_PERCENTAGE;

  return 0;
}

/* CREATE & DESTROY */
void test1_character_create() {
    Character* c = character_create(1);
    PRINT_TEST_RESULT(c != NULL);
    character_destroy(c);
}

void test2_character_create() {
    Character* c = character_create(NO_ID);
    PRINT_TEST_RESULT(c == NULL);
}

/* GET ID */
void test1_character_get_id() {
    Character* c = character_create(2);
    PRINT_TEST_RESULT(character_get_id(c) == 2);
    character_destroy(c);
}

void test2_character_get_id() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_id(c) == NO_ID);
}

/* GET NAME */
void test1_character_get_name() {
    Character* c = character_create(3);
    character_set_name(c, "Test");
    PRINT_TEST_RESULT(strcmp(character_get_name(c), "Test") == 0);
    character_destroy(c);
}

void test2_character_get_name() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_name(c) == NULL);
}

/* GET DESCRIPTION */
void test1_character_get_gdesc() {
    Character* c = character_create(4);
    character_set_gdesc(c, "Description");
    PRINT_TEST_RESULT(strcmp(character_get_gdesc(c), "Description") == 0);
    character_destroy(c);
}

void test2_character_get_gdesc() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_gdesc(c) == NULL);
}

/* GET MESSAGE */
void test1_character_get_message() {
    Character* c = character_create(5);
    character_set_message(c, "Hello");
    PRINT_TEST_RESULT(strcmp(character_get_message(c), "Hello") == 0);
    character_destroy(c);
}

void test2_character_get_message() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_message(c) == NULL);
}

/* GET HEALTH */
void test1_character_get_health() {
    Character* c = character_create(6);
    character_set_health(c, 100);
    PRINT_TEST_RESULT(character_get_health(c) == 100);
    character_destroy(c);
}

void test2_character_get_health() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_health(c) == POINT_ERROR);
}

/* GET FRIENDLY */
void test1_character_get_friendly() {
    Character* c = character_create(7);
    character_set_friendly(c, TRUE);
    PRINT_TEST_RESULT(character_get_friendly(c) == TRUE);
    character_destroy(c);
}

void test2_character_get_friendly() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_friendly(c) == FALSE);
}

/* GET FOLLOWING */
void test1_character_get_following() {
    Character* c = character_create(8);
    character_set_following(c, 1);
    PRINT_TEST_RESULT(character_get_following(c) == 1);
    character_destroy(c);
}

void test2_character_get_following() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_following(c) == NO_ID);
}

/* SET ID */
void test1_character_set_id() {
    Character* c = character_create(8);
    PRINT_TEST_RESULT(character_set_id(c, 9) == OK);
    character_destroy(c);
}

void test2_character_set_id() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_id(c, 10) == ERROR);
}

/* SET NAME */
void test1_character_set_name() {
    Character* c = character_create(11);
    PRINT_TEST_RESULT(character_set_name(c, "NewName") == OK);
    character_destroy(c);
}

void test2_character_set_name() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_name(c, "NewName") == ERROR);
}

void test3_character_set_name() {
    Character* c = character_create(12);
    PRINT_TEST_RESULT(character_set_name(c, NULL) == ERROR);
    character_destroy(c);
}

/* SET DESCRIPTION */
void test1_character_set_gdesc() {
    Character* c = character_create(13);
    PRINT_TEST_RESULT(character_set_gdesc(c, "NewDesc") == OK);
    character_destroy(c);
}

void test2_character_set_gdesc() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_gdesc(c, "NewDesc") == ERROR);
}

void test3_character_set_gdesc() {
    Character* c = character_create(14);
    PRINT_TEST_RESULT(character_set_gdesc(c, NULL) == ERROR);
    character_destroy(c);
}

/* SET HEALTH */
void test1_character_set_health() {
    Character* c = character_create(15);
    PRINT_TEST_RESULT(character_set_health(c, 50) == OK);
    character_destroy(c);
}

void test2_character_set_health() {
    Character* c = character_create(16);
    PRINT_TEST_RESULT(character_set_health(c, -5) == ERROR);
    character_destroy(c);
}

void test3_character_set_health() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_health(c, 50) == ERROR);
}

/* SET FRIENDLY */
void test1_character_set_friendly() {
    Character* c = character_create(17);
    PRINT_TEST_RESULT(character_set_friendly(c, TRUE) == OK);
    character_destroy(c);
}

void test2_character_set_friendly() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_friendly(c, TRUE) == ERROR);
}

/* SET MESSAGE */
void test1_character_set_message() {
    Character* c = character_create(18);
    PRINT_TEST_RESULT(character_set_message(c, "NewMsg") == OK);
    character_destroy(c);
}

void test2_character_set_message() {
    Character* c = character_create(19);
    PRINT_TEST_RESULT(character_set_message(c, NULL) == ERROR);
    character_destroy(c);
}

void test3_character_set_message() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_message(c, "NewMsg") == ERROR);
}

/* SET FOLLOWING */
void test1_character_set_following() {
    Character* c = character_create(19);
    PRINT_TEST_RESULT(character_set_following(c, 1) == OK);
    character_destroy(c);
}

void test2_character_set_following() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_following(c, 1) == ERROR);
}