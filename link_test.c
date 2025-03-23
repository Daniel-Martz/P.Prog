/**
 * @brief It tests link module
 *
 * @file link_test.c
 * @author Jorge Martín
 * @version 0.0
 * @date 23-03-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_test.h"

#define MAX_TESTS 22
#define TEST 10

/**
 * @brief Main function for link unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char **argv)
{
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
  
  if (all || test == 1) test1_link_create();
  if (all || test == 2) test2_link_create();
  if (all || test == 3) test1_link_get_name();
  if (all || test == 4) test2_link_get_name();
  if (all || test == 5) test1_link_set_name();
  if (all || test == 6) test2_link_set_name();
  if (all || test == 7) test1_link_get_origin();
  if (all || test == 8) test2_link_get_origin();
  if (all || test == 9) test1_link_set_origin();
  if (all || test == 10) test2_link_set_origin();
  if (all || test == 11) test1_link_get_destination();
  if (all || test == 12) test2_link_get_destination();
  if (all || test == 13) test1_link_set_destination();
  if (all || test == 14) test2_link_set_destination();
  if (all || test == 15) test1_link_get_direction();
  if (all || test == 16) test2_link_get_direction();
  if (all || test == 17) test1_link_set_direction();
  if (all || test == 18) test2_link_set_direction();
  if (all || test == 19) test1_link_get_open();
  if (all || test == 20) test2_link_get_open();
  if (all || test == 21) test1_link_set_open();
  if (all || test == 22) test2_link_set_open();
  
  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_link_create()
{
    Link *link = NULL;
    link = link_create(1);
    PRINT_TEST_RESULT(link != NULL);
    link_destroy(link);
}

void test2_link_create()
{
    Link *link = NULL;
    PRINT_TEST_RESULT(link == NULL);
}

void test1_link_get_name() {
    Link *link = NULL;
    link = link_create(1);
    PRINT_TEST_RESULT(link_get_name(link) != NULL);
    link_destroy(link);
}

void test2_link_get_name() {
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_name(link) == NULL);
}

void test1_link_set_name() {
    Link *link = NULL;
    char name[MAX_NAME] = "Hola";
    link = link_create(1);
    link_set_name(link, name);
    PRINT_TEST_RESULT(!strcmp(link_get_name(link), name));
    link_destroy(link);
}

void test2_link_set_name() {
    Link *link = NULL;
    link = link_create(1);
    PRINT_TEST_RESULT(!strcmp(link_get_name(link), ""));
    link_destroy(link);
}

void test1_link_get_origin() {
    Link *link = NULL;
    link = link_create(1);
    PRINT_TEST_RESULT(link_get_origin(link) == NO_ID);
    link_destroy(link);
}

void test2_link_get_origin() {
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_origin(link) == NULL);
}

void test1_link_set_origin() {
    Link *link = NULL;
    link = link_create(1);
    link_set_origin(link, 10);
    PRINT_TEST_RESULT(link_get_origin(link) == 10);
    link_destroy(link);
}

void test2_link_set_origin() {
    Link *link = NULL;
    link = link_create(1);
    link_set_origin(link, 10);
    PRINT_TEST_RESULT(link_get_origin(link) != NO_ID);
    link_destroy(link);
}

void test1_link_get_destination() {
    Link *link = NULL;
    link = link_create(1);
    PRINT_TEST_RESULT(link_get_destination(link) == NO_ID);
    link_destroy(link);
}

void test2_link_get_destination() {
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_destination(link) == NULL);
}

void test1_link_set_destination() {
    Link *link = NULL;
    link = link_create(1);
    link_set_destination(link, 10);
    PRINT_TEST_RESULT(link_get_destination(link) == 10);
    link_destroy(link);
}

void test2_link_set_destination() {
    Link *link = NULL;
    link = link_create(1);
    link_set_destination(link, 10);
    PRINT_TEST_RESULT(link_get_destination(link) != NO_ID);
    link_destroy(link);
}

void test1_link_get_direction() {
    Link *link = NULL;
    link = link_create(1);
    PRINT_TEST_RESULT(link_get_direction(link) == U);
    link_destroy(link);
}

void test2_link_get_direction() {
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_destination(link) == NULL);
}

void test1_link_set_direction() {
    Link *link = NULL;
    link = link_create(1);
    link_set_direction(link, E);
    PRINT_TEST_RESULT(link_get_direction(link) == E);
    link_destroy(link);
}

void test2_link_set_direction() {
    Link *link = NULL;
    link = link_create(1);
    link_set_direction(link, E);
    PRINT_TEST_RESULT(link_get_direction(link) != U);
    link_destroy(link);
}

void test1_link_get_open() {
    Link *link = NULL;
    link = link_create(1);
    PRINT_TEST_RESULT(link_get_open(link) == FALSE);
    link_destroy(link);
}

void test2_link_get_open() {
    Link *link = NULL;
    PRINT_TEST_RESULT(link_get_destination(link) == NULL);
}

void test1_link_set_open() {
    Link *link = NULL;
    link = link_create(1);
    link_set_open(link, TRUE);
    PRINT_TEST_RESULT(link_get_open(link) == TRUE);
    link_destroy(link);
}

void test2_link_set_open() {
    Link *link = NULL;
    link = link_create(1);
    link_set_open(link, TRUE);
    PRINT_TEST_RESULT(link_get_open(link) != NULL);
    link_destroy(link);
}


