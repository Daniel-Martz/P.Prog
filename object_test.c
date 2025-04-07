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

#define MAX_TESTS 10
#define TEST 10

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
