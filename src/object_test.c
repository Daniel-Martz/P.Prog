/** 
 * @brief It tests the object module
 * 
 * @file object_test.c
 * @author Jimena Sanchiz
 * @version 0.0 
 * @date 25-03-2025
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "object_test.h"

#define MAX_TESTS 15 /*!< It defines the number of tests*/
#define TEST 10 /*!< It defines an arbitrary test number*/

/** 
 * @brief Main function for object unit tests. 
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

if (all || test == 1)test1_object_create();
if (all || test == 2)test2_object_create();
if (all || test == 3)test1_object_get_id();
if (all || test == 4)test2_object_get_id();
if (all || test == 5)test1_object_set_id();
if (all || test == 6)test2_object_set_id();
if (all || test == 7)test1_object_set_name();
if (all || test == 8)test2_object_set_name();
if (all || test == 9)test1_object_get_name();
if (all || test == 10)test2_object_get_name();
if (all || test == 11)test1_object_get_description();
if (all || test == 12)test2_object_get_description();
if (all || test == 13)test1_object_set_description();
if (all || test == 14)test2_object_set_description();
if (all || test == 15)test3_object_set_description();
if (all || test == 16) test1_object_set_health();
if (all || test == 17) test2_object_set_health();
if (all || test == 18) test1_object_get_health();
if (all || test == 19) test2_object_get_health();
if (all || test == 20) test1_object_set_movable();
if (all || test == 21) test2_object_set_movable();
if (all || test == 22) test1_object_is_movable();
if (all || test == 23) test2_object_is_movable();
if (all || test == 24) test1_object_set_dependency();
if (all || test == 25) test2_object_set_dependency();
if (all || test == 26) test1_object_get_dependency();
if (all || test == 27) test2_object_get_dependency();
if (all || test == 28) test1_object_set_open();
if (all || test == 29) test2_object_set_open();
if (all || test == 30) test1_object_get_open();
if (all || test == 31) test2_object_get_open();
if (all || test == 32) test1_object_set_offensive();
if (all || test == 33) test2_object_set_offensive();
if (all || test == 34) test1_object_get_offensive();
if (all || test == 35) test2_object_get_offensive();
if (all || test == 36) test1_object_set_draw();
if (all || test == 37) test2_object_set_draw();
if (all || test == 38) test1_object_get_draw();
if (all || test == 39) test2_object_get_draw();
if (all || test == 40) test3_object_get_draw();
if (all || test == 41) test4_object_get_draw();

PRINT_PASSED_PERCENTAGE;

return 0;

}

void test1_object_create(){
   int result;
   Object *o;
   o = object_create(TEST);
   result = (o!=NULL);
   PRINT_TEST_RESULT(result);
   object_destroy(o);
}

void test2_object_create() {
   Object *o = NULL;
   PRINT_TEST_RESULT((o = object_create(NO_ID)) == NULL);
}

void test1_object_get_id() {
   Object *o;
   o = object_create(TEST);
   PRINT_TEST_RESULT(object_get_id(o) == TEST);
   object_destroy(o);
}

void test2_object_get_id() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_get_id(o) == NO_ID);
}

void test1_object_set_id() {
   Object *o;
   o = object_create(TEST);
   PRINT_TEST_RESULT(object_set_id(o, TEST) == OK);
   object_destroy(o);
}

void test2_object_set_id() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_set_id(o, TEST) == ERROR);
}

void test1_object_set_name() {
   Object *o;
   o = object_create(TEST);
   PRINT_TEST_RESULT(object_set_name(o, "hola") == OK);
   object_destroy(o);
}

void test2_object_set_name() {
   Object *o=NULL;
   PRINT_TEST_RESULT(object_set_name(o, "hola") == ERROR);
}

void test1_object_get_name() {
   Object *o;
   o = object_create(TEST);
   object_set_name(o, "hola");
   PRINT_TEST_RESULT(strcmp(object_get_name(o), "hola") == 0);
   object_destroy(o);
}

void test2_object_get_name() {
   Object *o = NULL;
   object_set_name(o, "hola");
   PRINT_TEST_RESULT(object_get_name(o) == NULL);
}

void test1_object_get_description(){
   Object *o = NULL;
   o = object_create(TEST);
   object_set_description(o, "pelota");
   PRINT_TEST_RESULT(strcmp(object_get_description(o), "pelota") == 0);
   object_destroy(o);
}

void test2_object_get_description(){
   Object *o = NULL;
   object_set_description(o, "pelota");
   PRINT_TEST_RESULT(object_get_description(o) == NULL);
}

void test1_object_set_description(){
   Object *obj = NULL;
   obj = object_create(TEST);
   PRINT_TEST_RESULT(object_set_description(obj, "pelota") == OK);
   object_destroy(obj);
}

void test2_object_set_description(){
   Object *o=NULL;
   PRINT_TEST_RESULT(object_set_description(o, "pelota") == ERROR);
}

void test3_object_set_description(){
   Object *o = NULL;
   o = object_create(TEST);
   PRINT_TEST_RESULT(object_set_description(o, NULL) == ERROR);
   object_destroy(o);
}

/* HEALTH TESTS */
void test1_object_set_health() {
   Object *o = object_create(TEST);
   PRINT_TEST_RESULT(object_set_health(o, 10) == OK);
   object_destroy(o);
}

void test2_object_set_health() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_set_health(o, 10) == ERROR);
}

void test1_object_get_health() {
   Object *o = object_create(TEST);
   object_set_health(o, 5);
   PRINT_TEST_RESULT(object_get_health(o) == 5);
   object_destroy(o);
}

void test2_object_get_health() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_get_health(o) == 0); 
}

void test1_object_set_movable() {
   Object *o = object_create(TEST);
   PRINT_TEST_RESULT(object_set_movable(o, TRUE) == OK);
   object_destroy(o);
}

void test2_object_set_movable() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_set_movable(o, TRUE) == ERROR);
}

void test1_object_is_movable() {
   Object *o = object_create(TEST);
   object_set_movable(o, TRUE);
   PRINT_TEST_RESULT(object_is_movable(o) == TRUE);
   object_destroy(o);
}

void test2_object_is_movable() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_is_movable(o) == FALSE);
}

void test1_object_set_dependency() {
   Object *o = object_create(TEST);
   PRINT_TEST_RESULT(object_set_dependency(o, 20) == OK);
   object_destroy(o);
}

void test2_object_set_dependency() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_set_dependency(o, 20) == ERROR);
}

void test1_object_get_dependency() {
   Object *o = object_create(TEST);
   object_set_dependency(o, 15);
   PRINT_TEST_RESULT(object_get_dependency(o) == 15);
   object_destroy(o);
}

void test2_object_get_dependency() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_get_dependency(o) == NO_ID);
}

void test1_object_set_open() {
   Object *o = object_create(TEST);
   PRINT_TEST_RESULT(object_set_open(o, 30) == OK);
   object_destroy(o);
}

void test2_object_set_open() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_set_open(o, 30) == ERROR);
}

void test1_object_get_open() {
   Object *o = object_create(TEST);
   object_set_open(o, 25);
   PRINT_TEST_RESULT(object_get_open(o) == 25);
   object_destroy(o);
}

void test2_object_get_open() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_get_open(o) == NO_ID);
}

void test1_object_set_offensive() {
   Object *o = object_create(TEST);
   PRINT_TEST_RESULT(object_set_offensive(o, TRUE) == OK);
   object_destroy(o);
}

void test2_object_set_offensive() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_set_offensive(o, TRUE) == ERROR);
}

void test1_object_get_offensive() {
   Object *o = object_create(TEST);
   object_set_offensive(o, TRUE);
   PRINT_TEST_RESULT(object_get_offensive(o) == TRUE);
   object_destroy(o);
}

void test2_object_get_offensive() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_get_offensive(o) == FALSE);
}

void test1_object_set_draw() {
   Object *o = object_create(TEST);
   const char draw[DRAW_HEIGHT][DRAW_WIDTH] = {
       "Dibujo1",
       "Dibujo2",
       "Dibujo3"
   };
   PRINT_TEST_RESULT(object_set_draw(o, draw) == OK);
   object_destroy(o);
}

void test2_object_set_draw() {
   Object *o = NULL;
   const char draw[DRAW_HEIGHT][DRAW_WIDTH] = {
       "Dibujo1",
       "Dibujo2",
       "Dibujo3"
   };
   PRINT_TEST_RESULT(object_set_draw(o, draw) == ERROR);
}

void test1_object_get_draw() {
   Object *o = object_create(TEST);
   const char draw[DRAW_HEIGHT][DRAW_WIDTH] = {
       "Dibujo1",
       "Dibujo2",
       "Dibujo3"
   };
   object_set_draw(o, draw);
   PRINT_TEST_RESULT(strcmp(object_get_draw(o, 1), "Dibujo2") == 0);
   object_destroy(o);
}

void test2_object_get_draw() {
   Object *o = NULL;
   PRINT_TEST_RESULT(object_get_draw(o, 1) == NULL);
}

void test3_object_get_draw() {
   Object *o = object_create(TEST);
   PRINT_TEST_RESULT(object_get_draw(o, -1) == NULL); 
   object_destroy(o);
}

void test4_object_get_draw() {
   Object *o = object_create(TEST);
   PRINT_TEST_RESULT(object_get_draw(o, DRAW_HEIGHT) == NULL); 
   object_destroy(o);
}


