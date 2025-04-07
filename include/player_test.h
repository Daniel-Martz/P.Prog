/** 
 * @brief It declares the tests for the player module
 * 
 * @file player_test.h
 * @author Jorge Martín
 * @version 0.0 
 * @date 25-03-2025
 * @copyright GNU Public License
 */

 #ifndef PLAYER_TEST_H
 #define PLAYER_TEST_H
 
 #include "test.h"
 #include "player.h"

 /* Test create */

 /**
 * @test Test player creation
 * @pre No preconditions
 * @post Non NULL pointer to player
 */
 void test1_player_create();

 /**
 * @test Test player creation
 * @pre No preconditions
 * @post NULL pointer to player
 */
 void test2_player_create();

  /* Test get */

 /**
 * @test Test get player id
 * @pre No preconditions
 * @post Id egual to the one creates
 */
 void test1_player_get_id();

 /**
 * @test Test get player id
 * @pre No preconditions
 * @post NO_ID id
 */
 void test2_player_get_id();

 /**
 * @test Test get player backpack
 * @pre No preconditions
 * @post Non NULL pointer to inventory
 */
 void test1_player_get_backpack();

 /**
 * @test Test get player backpack
 * @pre No preconditions
 * @post NULL pointer to inventory
 */
 void test2_player_get_backpack();

 /**
 * @test Test get player name
 * @pre No preconditions
 * @post Non NULL pointer to name
 */
 void test1_player_get_name();

 /**
 * @test Test get player name
 * @pre No preconditions
 * @post NULL pointer to name
 */
 void test2_player_get_name();

 /**
 * @test Test get player health
 * @pre No preconditions
 * @post health equal to 10 (initial health)
 */
 void test1_player_get_health();

 /**
 * @test Test get player health
 * @pre No preconditions
 * @post health equal to -1 (NO_ID)
 */
 void test2_player_get_health();

 /**
 * @test Test get player location
 * @pre No preconditions
 * @post location equal to NO_ID (player created)
 */
 void test1_player_get_location();

 /**
 * @test Test get player location
 * @pre No preconditions
 * @post location equal to NO_ID (player not created)
 */
 void test2_player_get_location();

 /**
 * @test Test get player gdesc
 * @pre No preconditions
 * @post Non NULL pointer to gdesc
 */
 void test1_player_get_gdesc();

 /**
 * @test Test get player gdesc
 * @pre No preconditions
 * @post NULL pointer to gdesc
 */
 void test2_player_get_gdesc();

 /* Test set */

 /**
 * @test Test set player id
 * @pre No preconditions
 * @post OK while setting a different id
 */
 void test1_player_set_id();

  /**
 * @test Test set player id
 * @pre No preconditions
 * @post ERROR while setting an id to a NULL player
 */
 void test2_player_set_id();

 /**
 * @test Test add objetc to player
 * @pre No preconditions
 * @post OK while adding an object
 */
 void test1_player_add_object();

 /**
 * @test Test add objetc to player
 * @pre No preconditions
 * @post ERROR while adding an object to a NULL player
 */
 void test2_player_add_object();

 /**
 * @test Test set player name
 * @pre No preconditions
 * @post OK while setting a name
 */
 void test1_player_set_name();

 /**
 * @test Test set player name
 * @pre No preconditions
 * @post ERROR while setting a name to a NULL player
 */
 void test2_player_set_name();

 /**
 * @test Test set player health
 * @pre No preconditions
 * @post OK while setting a health value
 */
 void test1_player_set_health();

 /**
 * @test Test set player health
 * @pre No preconditions
 * @post ERROR while setting a health value to a NULL player
 */
 void test2_player_set_health();

 /**
 * @test Test set player location
 * @pre No preconditions
 * @post OK while setting a location
 */
 void test1_player_set_location();

 /**
 * @test Test set player location
 * @pre No preconditions
 * @post ERROR while setting a location to a NULL player
 */
 void test2_player_set_location();

 /**
 * @test Test set player gdesc
 * @pre No preconditions
 * @post OK while setting a gdesc
 */
 void test1_player_set_gdesc();

 /**
 * @test Test set player gdesc
 * @pre No preconditions
 * @post ERROR while setting a gdesc to a NULL player
 */
 void test2_player_set_gdesc();

 /**
 * @test Test delete object of player
 * @pre No preconditions
 * @post OK while deletind an object previosly added
 */
 void test1_player_delete_object();

 /**
 * @test Test delete object of player
 * @pre No preconditions
 * @post ERROR while deleting an object to a NULL player
 */
 void test2_player_delete_object();

 #endif