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

#define MAX_TESTS 50 /*!< It defines the number of tests*/
#define TEST 10/*!< It defines an arbitrary test number*/

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
  if (all || test == 17) test1_character_get_damage();
  if (all || test == 18) test2_character_get_damage();
  if (all || test == 19) test1_character_set_id();
  if (all || test == 20) test2_character_set_id();
  if (all || test == 21) test1_character_set_name();
  if (all || test == 22) test2_character_set_name();
  if (all || test == 23) test3_character_set_name();
  if (all || test == 24) test1_character_set_gdesc();
  if (all || test == 25) test2_character_set_gdesc();
  if (all || test == 26) test3_character_set_gdesc();
  if (all || test == 27) test1_character_set_health();
  if (all || test == 28) test2_character_set_health();
  if (all || test == 29) test3_character_set_health();
  if (all || test == 30) test1_character_set_friendly();
  if (all || test == 31) test2_character_set_friendly();
  if (all || test == 32) test1_character_set_message();
  if (all || test == 33) test2_character_set_message();
  if (all || test == 34) test3_character_set_message();
  if (all || test == 35) test1_character_set_following();
  if (all || test == 36) test2_character_set_following();
  if (all || test == 37) test1_character_set_damage();
  if (all || test == 38) test2_character_set_damage();
  if (all || test == 39) test3_character_set_damage();
  if (all || test == 40) test1_character_get_face();
  if (all || test == 41) test2_character_get_face();
  if (all || test == 42) test3_character_get_face();
  if (all || test == 43) test1_character_get_strfriendly();
  if (all || test == 44) test2_character_get_strfriendly();
  if (all || test == 45) test3_character_get_strfriendly();
  if (all || test == 46) test1_character_set_face();
  if (all || test == 47) test2_character_set_face();
  if (all || test == 48) test3_character_set_face();
  
  PRINT_PASSED_PERCENTAGE;

  return 0;
}

/* CREATE & DESTROY */
void test1_character_create() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(c != NULL);
    character_destroy(c);
}

void test2_character_create() {
    Character* c = character_create(NO_ID);
    PRINT_TEST_RESULT(c == NULL);
}

/* GET ID */
void test1_character_get_id() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_get_id(c) == TEST);
    character_destroy(c);
}

void test2_character_get_id() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_id(c) == NO_ID);
}

/* GET NAME */
void test1_character_get_name() {
    Character* c = character_create(TEST);
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
    Character* c = character_create(TEST);
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
    Character* c = character_create(TEST);
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
    Character* c = character_create(TEST);
    character_set_health(c, TEST);
    PRINT_TEST_RESULT(character_get_health(c) == TEST);
    character_destroy(c);
}

void test2_character_get_health() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_health(c) == POINT_ERROR);
}

/* GET FRIENDLY */
void test1_character_get_friendly() {
    Character* c = character_create(TEST);
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
    Character* c = character_create(TEST);
    character_set_following(c, TEST);
    PRINT_TEST_RESULT(character_get_following(c) == TEST);
    character_destroy(c);
}

void test2_character_get_following() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_following(c) == NO_ID);
}

/* GET DAMAGE */
void test1_character_get_damage() {
    Character* c = character_create(TEST);
    character_set_damage(c, TEST);
    PRINT_TEST_RESULT(character_get_damage(c) == TEST);
    character_destroy(c);
}

void test2_character_get_damage() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_damage(c) == POINT_ERROR);
}

/* SET ID */
void test1_character_set_id() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_id(c, TEST) == OK);
    character_destroy(c);
}

void test2_character_set_id() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_id(c, TEST) == ERROR);
}

/* SET NAME */
void test1_character_set_name() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_name(c, "NewName") == OK);
    character_destroy(c);
}

void test2_character_set_name() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_name(c, "NewName") == ERROR);
}

void test3_character_set_name() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_name(c, NULL) == ERROR);
    character_destroy(c);
}

/* SET DESCRIPTION */
void test1_character_set_gdesc() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_gdesc(c, "NewDesc") == OK);
    character_destroy(c);
}

void test2_character_set_gdesc() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_gdesc(c, "NewDesc") == ERROR);
}

void test3_character_set_gdesc() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_gdesc(c, NULL) == ERROR);
    character_destroy(c);
}

/* SET HEALTH */
void test1_character_set_health() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_health(c, TEST) == OK);
    character_destroy(c);
}

void test2_character_set_health() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_health(c, -TEST) == ERROR);
    character_destroy(c);
}

void test3_character_set_health() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_health(c, TEST) == ERROR);
}

/* SET FRIENDLY */
void test1_character_set_friendly() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_friendly(c, TRUE) == OK);
    character_destroy(c);
}

void test2_character_set_friendly() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_friendly(c, TRUE) == ERROR);
}

/* SET MESSAGE */
void test1_character_set_message() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_message(c, "NewMsg") == OK);
    character_destroy(c);
}

void test2_character_set_message() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_message(c, NULL) == ERROR);
    character_destroy(c);
}

void test3_character_set_message() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_message(c, "NewMsg") == ERROR);
}

/* SET FOLLOWING */
void test1_character_set_following() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_following(c, TEST) == OK);
    character_destroy(c);
}

void test2_character_set_following() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_following(c, TEST) == ERROR);
}

/* SET DAMAGE */
void test1_character_set_damage() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_damage(c, TEST) == OK);
    character_destroy(c);
}

void test2_character_set_damage() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_damage(c, -TEST) == ERROR);
    character_destroy(c);
}

void test3_character_set_damage() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_set_health(c, TEST) == ERROR);
}

/* GET FACE */
void test1_character_get_face() {
    Character* c = character_create(TEST);
    const char face[FACE_HEIGHT][FACE_WIDTH] = {"  O  ", " /|\\ ", " / \\ "};
    character_set_face(c, face);
    PRINT_TEST_RESULT(strcmp(character_get_face(c, 0), "  O  ") == 0);
    character_destroy(c);
}

void test2_character_get_face() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_face(c, 0) == NULL);
}

void test3_character_get_face() {
    Character* c = character_create(TEST);
    const char face[FACE_HEIGHT][FACE_WIDTH] = {"  O  ", " /|\\ ", " / \\ "};
    character_set_face(c, face);
    PRINT_TEST_RESULT(character_get_face(c, FACE_HEIGHT) == NULL); 
    character_destroy(c);
}

/* GET STRFRIENDLY */
void test1_character_get_strfriendly() {
    Character* c = character_create(TEST);
    character_set_friendly(c, TRUE);
    PRINT_TEST_RESULT(strcmp(character_get_strfriendly(c), "friendly") == 0);
    character_destroy(c);
}

void test2_character_get_strfriendly() {
    Character* c = character_create(TEST);
    character_set_friendly(c, FALSE);
    PRINT_TEST_RESULT(strcmp(character_get_strfriendly(c), "enemy") == 0);
    character_destroy(c);
}

void test3_character_get_strfriendly() {
    Character* c = NULL;
    PRINT_TEST_RESULT(character_get_strfriendly(c) == NULL);
}

/* SET FACE */
void test1_character_set_face() {
    Character* c = character_create(TEST);
    const char face[FACE_HEIGHT][FACE_WIDTH] = {"  O  ", " /|\\ ", " / \\ "};
    PRINT_TEST_RESULT(character_set_face(c, face) == OK);
    character_destroy(c);
}

void test2_character_set_face() {
    Character* c = NULL;
    const char face[FACE_HEIGHT][FACE_WIDTH] = {"  O  ", " /|\\ ", " / \\ "};
    PRINT_TEST_RESULT(character_set_face(c, face) == ERROR);
}

void test3_character_set_face() {
    Character* c = character_create(TEST);
    PRINT_TEST_RESULT(character_set_face(c, NULL) == ERROR);
    character_destroy(c);
}
