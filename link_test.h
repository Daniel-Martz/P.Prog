/** 
 * @brief It declares the tests for the link module
 * 
 * @file link_test.h
 * @author Jorge Martín
 * @version 0.0 
 * @date 23-03-2025
 * @copyright GNU Public License
 */

 #ifndef LINK_TEST_H
 #define LINK_TEST_H
 
 #include "test.h"
 #include "link.h"

 /**
 * @test Test link creation
 * @pre No preconditions
 * @post Non NULL pointer to link
 */
 void test1_link_create();

 /**
 * @test Test link creation
 * @pre No preconditions
 * @post NULL pointer to link
 */
 void test2_link_create();

/**
 * @test Test the function of getting link name
 * @pre No preconditions
 * @post Non NULL pointer to name
 */
 void test1_link_get_name();

 /**
 * @test Test the function of getting link name
 * @pre No preconditions
 * @post NULL pointer to name
 */
 void test2_link_get_name();

 /**
 * @test Test the function of setting link name
 * @pre No preconditions
 * @post Non NULL pointer to name equal to the name
 */
 void test1_link_set_name();

 /**
 * @test Test the function of setting link name
 * @pre No preconditions
 * @post Non NULL pointer to name different to the name
 */
 void test2_link_set_name();

 /**
 * @test Test the function of getting link origin
 * @pre No preconditions
 * @post Id equal to NO_ID
 */
 void test1_link_get_origin();

 /**
 * @test Test the function of getting link origin
 * @pre No preconditions
 * @post NULL pointer
 */
 void test2_link_get_origin();

 /**
 * @test Test the function of setting link origin
 * @pre No preconditions
 * @post Id equal to the id set
 */
 void test1_link_set_origin();

 /**
 * @test Test the function of setting link origin
 * @pre No preconditions
 * @post Id distinct to NO_ID
 */
 void test2_link_set_origin();

 /**
 * @test Test the function of getting link destination
 * @pre No preconditions
 * @post Id equal to NO_ID
 */
 void test1_link_get_destination();

 /**
 * @test Test the function of getting link destination
 * @pre No preconditions
 * @post NULL pointer
 */
 void test2_link_get_destination();

 /**
 * @test Test the function of setting link destination
 * @pre No preconditions
 * @post Id equal to the id set
 */
 void test1_link_set_destination();

 /**
 * @test Test the function of setting link destination
 * @pre No preconditions
 * @post Id distinct to NO_ID
 */
 void test2_link_set_destination();

 /**
 * @test Test the function of getting link direction
 * @pre No preconditions
 * @post direction equal to U
 */
 void test1_link_get_direction();

 /**
 * @test Test the function of getting link direction
 * @pre No preconditions
 * @post NULL pointer
 */
 void test2_link_get_direction();

 /**
 * @test Test the function of setting link direction
 * @pre No preconditions
 * @post Direction equal to the direction set
 */
 void test1_link_set_direction();

 /**
 * @test Test the function of setting link direction
 * @pre No preconditions
 * @post Direction distinct to U
 */
 void test2_link_set_direction();

 /**
 * @test Test the function of getting link open
 * @pre No preconditions
 * @post Open equal to FALSE
 */
 void test1_link_get_open();

 /**
 * @test Test the function of getting link open
 * @pre No preconditions
 * @post NULL pointer
 */
 void test2_link_get_open();

 /**
 * @test Test the function of setting link open
 * @pre No preconditions
 * @post Open equal to the open set
 */
 void test1_link_set_open();

 /**
 * @test Test the function of setting link open
 * @pre No preconditions
 * @post Open distinct to NULL
 */
 void test2_link_set_open();

 #endif