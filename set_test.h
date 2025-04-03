/** 
 * @brief It declares the tests for the set module
 * 
 * @file set_test.h
 * @author Jaime Romero
 * @version 0.1 
 * @date 2025-02-18
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

#include "test.h"
#include "set.h"

/**
 * @test Test set creation
 * @pre None
 * @post Non NULL pointer to set
 */
void test1_set_create();

/**
 * @test Test set creation
 * @pre None
 * @post Initial number of ids is 0
 */
void test2_set_create();

/**
 * @test Test adding id to set
 * @pre Valid set pointer and id
 * @post Output == OK
 */
void test1_set_add();

/**
 * @test Test adding duplicate id to set
 * @pre Set with existing id
 * @post Output == ERROR
 */
void test2_set_add();

/**
 * @test Test deleting id from set
 * @pre Set containing the id
 * @post Output == OK
 */
void test1_set_del();

/**
 * @test Test deleting id from empty set
 * @pre Empty set
 * @post Output == ERROR
 */
void test2_set_del();

/**
 * @test Test getting number of ids from empty set
 * @pre Empty set
 * @post Output == 0
 */
void test1_set_get_nids();

/**
 * @test Test getting number of ids from non-empty set
 * @pre Set with one id
 * @post Output == 1
 */
void test2_set_get_nids();

/**
 * @test Test getting number of ids after deletion
 * @pre Set with one id that gets removed
 * @post Output == 0
 */
void test3_set_get_nids();

/**
 * @test Test id presence in set
 * @pre Set containing the id
 * @post Output == OK
 */
void test1_set_id_is_there();

/**
 * @test Test id presence in empty set
 * @pre Empty set
 * @post Output == ERROR
 */
void test2_set_id_is_there();

/**
 * @test Test getting ids array
 * @pre Set with multiple ids
 * @post Retrieved array matches added ids
 */
void test1_set_get_ids();

/**
 * @test Test getting ids array from empty set
 * @pre Empty set
 * @post All array elements are NO_ID
 */
void test2_set_get_ids();

#endif