/** 
 * @brief It tests space module
 * 
 * @file space_test.c
 * @author Jaime Romero
 * @version 0.0 
 * @date 17-02-2025
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "space_test.h"

#define MAX_TESTS 30

/** 
 * @brief Main function for SPACE unit tests. 
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
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_space_create();
  if (all || test == 2) test2_space_create();
  if (all || test == 3) test1_space_set_name();
  if (all || test == 4) test2_space_set_name();
  if (all || test == 5) test3_space_set_name();
  if (all || test == 6) test1_space_set_north();
  if (all || test == 7) test2_space_set_north();
  if (all || test == 8) test1_space_set_south();
  if (all || test == 9) test2_space_set_south();
  if (all || test == 10) test1_space_set_east();
  if (all || test == 11) test2_space_set_east();
  if (all || test == 12) test1_space_set_west();
  if (all || test == 13) test2_space_set_west();
  if (all || test == 14) test1_space_set_new_object();
  if (all || test == 15) test2_space_set_new_object();
  if (all || test == 16) test1_space_set_character();
  if (all || test == 17) test2_space_set_character();
  if (all || test == 18) test1_space_set_gdesc();
  if (all || test == 19) test2_space_set_gdesc();

  if (all || test == 20) test1_space_get_id();
  if (all || test == 21) test2_space_get_id();
  if (all || test == 22) test1_space_get_name();
  if (all || test == 23) test2_space_get_name();
  if (all || test == 24) test1_space_get_north();
  if (all || test == 25) test2_space_get_north();
  if (all || test == 26) test1_space_get_south();
  if (all || test == 27) test2_space_get_south();
  if (all || test == 28) test1_space_get_east();
  if (all || test == 29) test2_space_get_east();
  if (all || test == 30) test1_space_get_west();
  if (all || test == 31) test2_space_get_west();
  if (all || test == 32) test1_space_get_nobjects();
  if (all || test == 33) test2_space_get_nobjects();

  if (all || test == 34) test1_space_get_objects_ids();
  if (all || test == 35) test1_space_get_character();
  if (all || test == 36) test2_space_get_character();

  if (all || test == 37) test1_space_get_gdesc();
  if (all || test == 38) test2_space_get_gdesc();
  if (all || test == 39) test3_space_get_gdesc();
  if (all || test == 40) test4_space_get_gdesc();

  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_space_create() {
  int result;
  Space *s;
  s = space_create(5);
  result=s!=NULL ;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_create() {
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_get_id(s) == 4);
  space_destroy(s);
}

void test1_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_set_north() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_north(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_north() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_north(s, 4) == ERROR);
}

void test1_space_set_south() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_south(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_south() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_south(s, 4) == ERROR);
}

void test1_space_set_east() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_east(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_east() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_east(s, 4) == ERROR);
}

void test1_space_set_west() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_west(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_west() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_west(s, 4) == ERROR);
}

void test1_space_set_new_object() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_new_object(s, 245) == OK); /*Falla en set_add*/
  space_destroy(s);
}

void test2_space_set_new_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_new_object(s, 3) == ERROR);
}

void test1_space_set_character(){
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_character(s, 6) == OK);
  space_destroy(s);
}

void test2_space_set_character(){
  Space* s = NULL;
  PRINT_TEST_RESULT(space_set_character(s, 4) == ERROR);
}

void test1_space_set_gdesc(){
  Space *s;
  const char array[5][10] = {
    "Fila11111",
    "Fila22222",
    "Fila33333",
    "Fila44444",
    "Fila55555"
  };
  s = space_create(3);
  PRINT_TEST_RESULT(space_set_gdesc(s, array) == OK);
  space_destroy(s);
}

void test2_space_set_gdesc(){
  Space* s = NULL;
  const char array[5][10] = {
    "Fila11111",
    "Fila22222",
    "Fila33333",
    "Fila44444",
    "Fila55555"
  };
  PRINT_TEST_RESULT(space_set_gdesc(s, array) == ERROR);
}

void test1_space_get_name() {
  Space *s;
  s = space_create(1);
  space_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

void test1_space_get_nobjects() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_get_nobjects(s) == 0);
  space_destroy(s);
}

void test2_space_get_nobjects() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_nobjects(s) == NO_ID);
}

void test1_space_get_north() {
  Space *s;
  s = space_create(5);
  space_set_north(s, 4);
  PRINT_TEST_RESULT(space_get_north(s) == 4);
  space_destroy(s);
}

void test2_space_get_north() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_north(s) == NO_ID);
}

void test1_space_get_south() {
  Space *s;
  s = space_create(5);
  space_set_south(s, 2);
  PRINT_TEST_RESULT(space_get_south(s) == 2);
  space_destroy(s);
}

void test2_space_get_south() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_south(s) == NO_ID);
}

void test1_space_get_east() {
  Space *s;
  s = space_create(5);
  space_set_east(s, 1);
  PRINT_TEST_RESULT(space_get_east(s) == 1);
  space_destroy(s);
}

void test2_space_get_east() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_east(s) == NO_ID);
}

void test1_space_get_west() {
  Space *s;
  s = space_create(5);
  space_set_west(s, 6);
  PRINT_TEST_RESULT(space_get_west(s) == 6);
  space_destroy(s);
}

void test2_space_get_west() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_west(s) == NO_ID);
}

void test1_space_get_id() {
  Space *s;
  s = space_create(25);
  PRINT_TEST_RESULT(space_get_id(s) == 25);
  space_destroy(s);
}

void test2_space_get_id() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

void test1_space_get_objects_ids(){
  Space *s=NULL;
  PRINT_TEST_RESULT(space_get_objects_ids(s) == NULL);
}

void test1_space_get_character(){
  Space *s;
  s = space_create(21);
  space_set_character(s, 33);
  PRINT_TEST_RESULT(space_get_character(s) == 33);
  space_destroy(s);
}

void test2_space_get_character(){
  Space *s=NULL;
  PRINT_TEST_RESULT(space_get_character(s) == NO_ID);
}

void test1_space_get_gdesc(){
  Space *s;
  int i=0; 
  const char array[5][10] = {
    "Fila11111",
    "Fila22222",
    "Fila33333",
    "Fila44444",
    "Fila55555"
  };
  s = space_create(21);
  space_set_gdesc(s, array);
  
  for (i = 0; i < 5; i++)
  {
    if ((strcmp(space_get_gdesc(s, i), array[i])))
    {
      PRINT_TEST_RESULT(FALSE);
      space_destroy(s);
      return;
    }
  }
  PRINT_TEST_RESULT(TRUE);
  space_destroy(s);
}

void test2_space_get_gdesc(){
  Space *s=NULL;
  const char array[5][10] = {
    "Fila11111",
    "Fila22222",
    "Fila33333",
    "Fila44444",
    "Fila55555"
  };
  space_set_gdesc(s, array);
  PRINT_TEST_RESULT(space_get_gdesc(s, 1) == NULL);
}

void test3_space_get_gdesc(){
  Space *s;
  const char array[5][10] = {
    "Fila11111",
    "Fila22222",
    "Fila33333",
    "Fila44444",
    "Fila55555"
  };
  s = space_create(23);
  space_set_gdesc(s, array);
  PRINT_TEST_RESULT(space_get_gdesc(s, -1) == NULL);
}

void test4_space_get_gdesc(){
  Space *s;
  const char array[5][10] = {
    "Fila11111",
    "Fila22222",
    "Fila33333",
    "Fila44444",
    "Fila55555"
  };
  s = space_create(23);
  space_set_gdesc(s, array);
  PRINT_TEST_RESULT(space_get_gdesc(s, 10) == NULL);
}
