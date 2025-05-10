/**
 * @brief It tests player module
 *
 * @file player_test.c
 * @author Jorge Martín
 * @version 0.0
 * @date 25-03-2025
 * @copyright GNU Public License
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "player_test.h"
 
 #define MAX_TESTS 28/*!< It defines the number of tests*/
 #define TEST_ID_1 1/*!< It defines a constant for id*/
#define TEST_ID_2 2/*!< It defines a constant for id*/
#define TEST_OBJECT_ID 10/*!< It defines a constant for id*/
#define TEST_LOCATION_ID 5/*!< It defines a constant for id*/
#define TEST_HEALTH_POSITIVE 5/*!< It defines a constant fo helath*/
#define TEST_HEALTH_NEGATIVE -1/*!< It defines a constant fo helath*/
#define TEST_DAMAGE 5/*!< It defines a constant for damage*/
#define TEST_DAMAGE_INVALID -1/*!< It defines a constant for damage*/
#define TEST_NAME "name"/*!< It defines a string constant*/
#define TEST_GDESC "gdesc"/*!< It defines a string constant*/

 /**
  * @brief Main function for player unit tests.
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
   
    if (all || test == 1)  test1_player_create();
    if (all || test == 2)  test2_player_create();
    if (all || test == 3)  test1_player_get_id();
    if (all || test == 4)  test2_player_get_id();
    if (all || test == 5)  test1_player_get_backpack();
    if (all || test == 6)  test2_player_get_backpack();
    if (all || test == 7)  test1_player_get_name();
    if (all || test == 8)  test2_player_get_name();
    if (all || test == 9)  test1_player_get_health();
    if (all || test == 10)  test2_player_get_health();
    if (all || test == 11)  test1_player_get_location();
    if (all || test == 12)  test2_player_get_location();
    if (all || test == 13)  test1_player_get_gdesc();
    if (all || test == 14)  test2_player_get_gdesc();
    if (all || test == 15)  test1_player_set_id();
    if (all || test == 16)  test2_player_set_id();
    if (all || test == 17)  test1_player_add_object();
    if (all || test == 18)  test2_player_add_object();
    if (all || test == 19)  test1_player_set_name();
    if (all || test == 20)  test2_player_set_name();
    if (all || test == 21)  test1_player_set_health();
    if (all || test == 22)  test2_player_set_health();
    if (all || test == 23)  test1_player_set_location();
    if (all || test == 24)  test2_player_set_location();
    if (all || test == 25)  test1_player_set_gdesc();
    if (all || test == 26)  test2_player_set_gdesc();
    if (all || test == 27)  test1_player_delete_object();
    if (all || test == 28)  test2_player_delete_object();
    if (all || test == 29) test1_player_get_damage();
    if (all || test == 30) test2_player_get_damage();
    if (all || test == 31) test1_player_set_damage();
    if (all || test == 32) test2_player_set_damage();
    if (all || test == 33) test3_player_set_damage();

   PRINT_PASSED_PERCENTAGE;

   return 0;
}

void test1_player_create() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player != NULL);
    player_destroy(player);
}

void test2_player_create() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player == NULL);
}

void test1_player_get_id() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_get_id(player) == TEST_ID_1);
    player_destroy(player);
}

void test2_player_get_id() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_id(player) == NO_ID);
}

void test1_player_get_backpack() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_get_backpack(player) != NULL);
    player_destroy(player);
}

void test2_player_get_backpack() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_backpack(player) == NULL);
}

void test1_player_get_name() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_get_name(player) != NULL);
    player_destroy(player);
}

void test2_player_get_name() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_name(player) == NULL);
}

void test1_player_get_health() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_get_health(player) == 0);
    player_destroy(player);
}

void test2_player_get_health() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_health(player) == NO_ID);
}

void test1_player_get_location() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_get_location(player) == NO_ID);
    player_destroy(player);
}

void test2_player_get_location() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_location(player) == NO_ID);
}

void test1_player_get_gdesc() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_get_gdesc(player) != NULL);
    player_destroy(player);
}

void test2_player_get_gdesc() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_gdesc(player) == NULL);
}

void test1_player_set_id() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_set_id(player, TEST_ID_2) == OK);
    player_destroy(player);
}

void test2_player_set_id() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_id(player, TEST_ID_2) == ERROR);
}

void test1_player_add_object() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_add_object(player, TEST_OBJECT_ID) == OK);
    player_destroy(player);
}

void test2_player_add_object() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_add_object(player, TEST_OBJECT_ID) == ERROR);
}

void test1_player_set_name() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_set_name(player, TEST_NAME) == OK);
    player_destroy(player);
}

void test2_player_set_name() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_name(player, TEST_NAME) == ERROR);
}

void test1_player_set_health() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_set_health(player, TEST_HEALTH_POSITIVE) == OK);
    player_destroy(player);
}

void test2_player_set_health() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_health(player, TEST_HEALTH_POSITIVE) == ERROR);
}

void test1_player_set_location() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_set_location(player, TEST_LOCATION_ID) == OK);
    player_destroy(player);
}

void test2_player_set_location() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_location(player, TEST_LOCATION_ID) == ERROR);
}

void test1_player_set_gdesc() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_set_gdesc(player, TEST_GDESC) == OK);
    player_destroy(player);
}

void test2_player_set_gdesc() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_gdesc(player, TEST_GDESC) == ERROR);
}

void test1_player_delete_object() {
    Player *player = NULL;
    player = player_create(TEST_ID_1);
    player_add_object(player, TEST_OBJECT_ID);
    PRINT_TEST_RESULT(player_delete_object(player, TEST_OBJECT_ID) == OK);
    player_destroy(player);
}

void test2_player_delete_object() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_delete_object(player, TEST_OBJECT_ID) == ERROR);
}

void test1_player_get_damage() {
    Player *player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_get_damage(player) == 1); 
    player_destroy(player);
}

void test2_player_get_damage() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_get_damage(player) == NO_ID);
}

void test1_player_set_damage() {
    Player *player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_set_damage(player, TEST_DAMAGE) == OK);
    player_destroy(player);
}

void test2_player_set_damage() {
    Player *player = NULL;
    PRINT_TEST_RESULT(player_set_damage(player, TEST_DAMAGE) == ERROR);
}

void test3_player_set_damage() {
    Player *player = player_create(TEST_ID_1);
    PRINT_TEST_RESULT(player_set_damage(player, TEST_DAMAGE_INVALID) == ERROR); 
    player_destroy(player);
}
