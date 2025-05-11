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

#define MAX_TESTS 31/*!< It defines the number of tests*/

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
  if (all || test == 6) test1_space_set_new_object();
  if (all || test == 7) test2_space_set_new_object();
  if (all || test == 8) test1_space_set_newCharacter();
  if (all || test == 9) test2_space_set_newCharacter();
  if (all || test == 10) test1_space_set_gdesc();
  if (all || test == 11) test2_space_set_gdesc();

  if (all || test == 12) test1_space_get_id();
  if (all || test == 13) test2_space_get_id();
  if (all || test == 14) test1_space_get_name();
  if (all || test == 15) test2_space_get_name();
  if (all || test == 16) test1_space_get_nobjects();
  if (all || test == 17) test2_space_get_nobjects();

  if (all || test == 18) test1_space_get_objects_ids();

  if (all || test == 13) test1_space_get_gdesc();
  if (all || test == 20) test2_space_get_gdesc();
  if (all || test == 21) test3_space_get_gdesc();
  if (all || test == 22) test4_space_get_gdesc();
  if (all || test == 23) test1_space_get_discovered();
  if (all || test == 24) test2_space_get_discovered();
  if (all || test == 25) test1_space_set_discovered();
  if (all || test == 26) test2_space_set_discovered();
  if (all || test == 27) test1_space_print();
  if (all || test == 28) test2_space_print();
  if (all || test == 29) test3_space_print();
  if (all || test == 30) test4_space_print();
  if (all || test == 31) test5_space_print();

  if (all || test == 32) test1_space_object_del();
  if (all || test == 33) test2_space_object_del();
  if (all || test == 34) test3_space_object_del();

  if (all || test == 35) test1_space_character_del();
  if (all || test == 36) test2_space_character_del();
  if (all || test == 37) test3_space_character_del();

  if (all || test == 38) test1_space_object_is_there();
  if (all || test == 39) test2_space_object_is_there();
  if (all || test == 40) test3_space_object_is_there();

  if (all || test == 41) test1_space_character_is_there();
  if (all || test == 42) test2_space_character_is_there();
  if (all || test == 43) test3_space_character_is_there();

  if (all || test == 44) test1_space_get_ncharacters();
  if (all || test == 45) test2_space_get_ncharacters();
  if (all || test == 46) test3_space_get_ncharacters();

  if (all || test == 47) test1_space_get_characters_ids();
  if (all || test == 48) test2_space_get_characters_ids();
  if (all || test == 49) test3_space_get_characters_ids();



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

void test1_space_set_newCharacter(){
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_newCharacter(s, 6) == OK);
  space_destroy(s);
}

void test2_space_set_newCharacter(){
  Space* s = NULL;
  PRINT_TEST_RESULT(space_set_newCharacter(s, 4) == ERROR);
}

void test1_space_set_gdesc(){
  Space *s;
  const char array[N_ROWS][N_COLUMNS] = {
    "Fila1_123456789",  
    "Fila2_abcdefghi",   
    "Fila3_ABCDEFGHI",   
    "Fila4_987654321",   
    "Fila5_xyzXYZ123",   
    "Fila6_000000000"    
  };
  
  s = space_create(6);
  PRINT_TEST_RESULT(space_set_gdesc(s, array) == OK);
  space_destroy(s);
}

void test2_space_set_gdesc(){
  Space* s = NULL;
  const char array[5][18] = {
    "Fila1111111111111",
    "Fila2222222222222",
    "Fila3333333333333",
    "Fila4444444444444",
    "Fila5555555555555"
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

void test1_space_get_gdesc(){
  Space *s;
  int i=0; 
  const char array[5][18] = {
    "Fila1111111111111",
    "Fila2222222222222",
    "Fila3333333333333",
    "Fila4444444444444",
    "Fila5555555555555"
  };
  s = space_create(21);
  space_set_gdesc(s, array);
  
  for (i = 0; i < 5; i++)
  {
    if ((strcmp(space_get_gdesc(s, i), array[i])))
    {
      PRINT_TEST_RESULT(ERROR);
      space_destroy(s);
      return;
    }
  }
  PRINT_TEST_RESULT(OK);
  space_destroy(s);
}

void test2_space_get_gdesc(){
  Space *s=NULL;
  const char array[5][18] = {
    "Fila1111111111111",
    "Fila2222222222222",
    "Fila3333333333333",
    "Fila4444444444444",
    "Fila5555555555555"
  };
  space_set_gdesc(s, array);
  PRINT_TEST_RESULT(space_get_gdesc(s, 1) == NULL);
}

void test3_space_get_gdesc(){
  Space *s;
  const char array[5][18] = {
    "Fila1111111111111",
    "Fila2222222222222",
    "Fila3333333333333",
    "Fila4444444444444",
    "Fila5555555555555"
  };
  s = space_create(23);
  space_set_gdesc(s, array);
  PRINT_TEST_RESULT(space_get_gdesc(s, -1) == NULL);
}

void test4_space_get_gdesc(){
  Space *s;
  const char array[5][18] = {
    "Fila1111111111111",
    "Fila2222222222222",
    "Fila3333333333333",
    "Fila4444444444444",
    "Fila5555555555555"
  };
  s = space_create(23);
  space_set_gdesc(s, array);
  PRINT_TEST_RESULT(space_get_gdesc(s, 10) == NULL);
}

void test1_space_get_discovered() {
  Space *s = space_create(1);
  space_set_discovered(s, OK);
  PRINT_TEST_RESULT(space_get_discovered(s) == TRUE);
  space_destroy(s);
}

void test2_space_get_discovered() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_discovered(s) == FALSE);
}

void test1_space_set_discovered() {
  Space *s = space_create(2);
  Status result = space_set_discovered(s, ERROR);
  Bool status_result = (space_get_discovered(s) == FALSE);
  PRINT_TEST_RESULT(result == OK && status_result);
  space_destroy(s);
}

void test2_space_set_discovered() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_discovered(s, OK) == ERROR);
}

void test1_space_print() {
  const char gdesc[5][18] = {
      "Graphic1  ",
      "Graphic2  ",
      "Graphic3  ",
      "Graphic4  ",
      "Graphic5  "
  };
  Space *s = space_create(1);
  space_set_name(s, "Test Space");
  space_set_newCharacter(s, 5);
  
  space_set_gdesc(s, gdesc);
  
  space_set_new_object(s, 10);
  space_set_new_object(s, 20);
  
  PRINT_TEST_RESULT(space_print(s) == OK);
  space_destroy(s);
}

void test2_space_print() {
  PRINT_TEST_RESULT(space_print(NULL) == ERROR);
}

void test3_space_print() {
  const char gdesc[5][18] = {
    "         ",
    "         ",
    "         ",
    "         ",
    "         "
  };
  Space *s = space_create(2);
  space_set_name(s, "Empty Space");
  
 
  space_set_gdesc(s, gdesc);
  
  PRINT_TEST_RESULT(space_print(s) == OK);
  space_destroy(s);
}

void test4_space_print() {
  const char gdesc[5][18] = {
    "NoChar1  ",
    "NoChar2  ",
    "NoChar3  ",
    "NoChar4  ",
    "NoChar5  "
};
  Space *s = space_create(3);
  space_set_name(s, "No Character");
  
  space_set_gdesc(s, gdesc);
  
  space_set_new_object(s, 30);
  
  PRINT_TEST_RESULT(space_print(s) == OK);
  space_destroy(s);
}

void test5_space_print() {
  const char gdesc[5][18] = {
    "Empty1   ",
    "Empty2   ",
    "Empty3   ",
    "Empty4   ",
    "Empty5   "
};
  Space *s = space_create(4);
  space_set_name(s, "");
  

  space_set_gdesc(s, gdesc);
  
  PRINT_TEST_RESULT(space_print(s) == OK);
  space_destroy(s);
}

void test1_space_object_del() {
  Space *s = space_create(1);
  space_set_new_object(s, 10);
  PRINT_TEST_RESULT(space_object_del(s, 10) == OK && space_get_nobjects(s) == 0);
  space_destroy(s);
}

void test2_space_object_del() {
  Space *s = space_create(1);
  PRINT_TEST_RESULT(space_object_del(s, 10) == ERROR); 
  space_destroy(s);
}

void test3_space_object_del() {
  PRINT_TEST_RESULT(space_object_del(NULL, 10) == ERROR);
}

void test1_space_character_del() {
  Space *s = space_create(1);
  space_set_newCharacter(s, 5);
  PRINT_TEST_RESULT(space_character_del(s, 5) == OK && space_get_ncharacters(s) == 0);
  space_destroy(s);
}

void test2_space_character_del() {
  Space *s = space_create(1);
  PRINT_TEST_RESULT(space_character_del(s, 5) == ERROR); 
  space_destroy(s);
}

void test3_space_character_del() {
  PRINT_TEST_RESULT(space_character_del(NULL, 5) == ERROR);
}

void test1_space_object_is_there() {
  Space *s = space_create(1);
  space_set_new_object(s, 5);
  PRINT_TEST_RESULT(space_object_is_there(s, 5) == OK);
  space_destroy(s);
}

void test2_space_object_is_there() {
  Space *s = space_create(1);
  PRINT_TEST_RESULT(space_object_is_there(s, 5) == ERROR); 
  space_destroy(s);
}

void test3_space_object_is_there() {
  PRINT_TEST_RESULT(space_object_is_there(NULL, 5) == ERROR); 
}

void test1_space_character_is_there() {
  Space *s = space_create(1);
  space_set_newCharacter(s, 3);
  PRINT_TEST_RESULT(space_character_is_there(s, 3) == OK);
  space_destroy(s);
}

void test2_space_character_is_there() {
  Space *s = space_create(1);
  PRINT_TEST_RESULT(space_character_is_there(s, 3) == ERROR); 
  space_destroy(s);
}

void test3_space_character_is_there() {
  PRINT_TEST_RESULT(space_character_is_there(NULL, 3) == ERROR); 
}

void test1_space_get_ncharacters() {
  Space *s = space_create(1);
  space_set_newCharacter(s, 3);
  space_set_newCharacter(s, 4);
  PRINT_TEST_RESULT(space_get_ncharacters(s) == 2);
  space_destroy(s);
}

void test2_space_get_ncharacters() {
  Space *s = space_create(1);
  PRINT_TEST_RESULT(space_get_ncharacters(s) == 0); 
  space_destroy(s);
}

void test3_space_get_ncharacters() {
  PRINT_TEST_RESULT(space_get_ncharacters(NULL) == POINT_ERROR); 
}

void test1_space_get_characters_ids() {
  Space *s = space_create(1);
  Id *ids = space_get_characters_ids(s);
  space_set_newCharacter(s, 3);
  space_set_newCharacter(s, 4);
  
  PRINT_TEST_RESULT(ids != NULL && ids[0] == 3 && ids[1] == 4);
  space_destroy(s);
}

void test2_space_get_characters_ids() {
  Space *s = space_create(1);
  PRINT_TEST_RESULT(space_get_characters_ids(s) != NULL); 
  space_destroy(s);
}

void test3_space_get_characters_ids() {
  PRINT_TEST_RESULT(space_get_characters_ids(NULL) == NULL); 
}