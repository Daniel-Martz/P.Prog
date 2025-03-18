/** 
 * @brief It declares the tests for the set module
 * 
 * @file set_test.h
 * @author Jaime Romero
 * @version 0.0 
 * @date 17-02-2025
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

#include "test.h"
#include "set.h"

/**
 * @test Test set creation
 * @pre No preconditions
 * @post Non NULL pointer to set
 */
void test1_set_create();

/**
 * @test Test set creation
 * @pre No preconditions
 * @post Number of IDs in set == 0
 */
void test2_set_create();

/**
 * @test Test function for adding an ID to the set
 * @pre Valid ID
 * @post Output == OK
 */
void test1_set_add();

/**
 * @test Test function for adding an ID to the set
 * @pre ID already exists in the set
 * @post Output == ERROR
 */
void test2_set_add();

/**
 * @test Test function for deleting an ID from the set
 * @pre ID exists in the set
 * @post Output == OK
 */
void test1_set_del();

/**
 * @test Test function for deleting an ID from the set
 * @pre ID does not exist in the set
 * @post Output == ERROR
 */
void test2_set_del();

/**
 * @test Test function for getting the number of IDs in the set
 * @pre Set is empty
 * @post Output == 0
 */
void test1_set_get_nids();

/**
 * @test Test function for getting the number of IDs in the set
 * @pre Set contains one ID
 * @post Output == 1
 */
void test2_set_get_nids();

/**
 * @test Test function for getting the number of IDs in the set
 * @pre Set has one ID added and then removed
 * @post Output == 0
 */
void test3_set_get_nids();

/**
 * @test Test function for checking if an ID exists in the set
 * @pre ID exists in the set
 * @post Output == OK
 */
void test1_set_id_is_there();

/**
 * @test Test function for checking if an ID exists in the set
 * @pre ID does not exist in the set
 * @post Output == ERROR
 */
void test2_set_id_is_there();

/**
 * @test Test function for getting the IDs in the set
 * @pre Set contains multiple IDs
 * @post Output == Array of IDs matching the expected values
 */
void test1_set_get_ids();

/**
 * @test Test function for getting the IDs in the set
 * @pre Set is empty
 * @post Output == Array of NO_ID values
 */
void test2_set_get_ids();

#endif
