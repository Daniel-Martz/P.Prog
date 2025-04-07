/** 
 * @brief It declares the tests for the object module
 * 
 * @file object_test.h
 * @author Jimena Sanchiz
 * @version 0.0 
 * @date 25-03-2025
 * @copyright GNU Public License
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

#include "test.h"
#include "object.h"

/**
 * @test Test object creation
 * @pre Valid object ID
 * @post Non NULL pointer to object
 */
void test1_object_create();

/**
 * @test Test object creation
 * @pre Invalid object ID (NO_ID)
 * @post Output == NULL
 */
void test2_object_create();

/**
 * @test Test function for getting object ID
 * @pre Valid object pointer
 * @post Output != NO_ID
 */
void test1_object_get_id();

/**
 * @test Test function for getting object ID
 * @pre NULL object pointer
 * @post Output == NO_ID
 */
void test2_object_get_id();

/**
 * @test Test function for setting object ID
 * @pre Valid object pointer and ID
 * @post Output == OK
 */
void test1_object_set_id();

/**
 * @test Test function for setting object ID
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_object_set_id();

/**
 * @test Test function for setting object name
 * @pre Valid object pointer and name
 * @post Output == OK
 */
void test1_object_set_name();

/**
 * @test Test function for setting object name
 * @pre NULL object pointer
 * @post Output == NULL
 */
void test2_object_set_name();

/**
 * @test Test function for getting object name
 * @pre Valid object pointer and name set
 * @post Output == Expected name
 */
void test1_object_get_name();

/**
 * @test Test function for getting object name
 * @pre NULL object pointer
 * @post Output == NULL
 */
void test2_object_get_name();

/**
 * @test Test function for getting object description
 * @pre Valid object pointer with description set
 * @post Output == Expected description
 */
void test1_object_get_description();

/**
 * @test Test function for getting object description
 * @pre NULL object pointer
 * @post Output == NULL
 */
void test2_object_get_description();

/**
 * @test Test function for setting object description
 * @pre Valid object pointer
 * @post Output == OK
 */
void test1_object_set_description();

/**
 * @test Test function for setting object description
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_object_set_description();

/**
 * @test Test function for setting object description
 * @pre Valid object pointer with NULL description
 * @post Output == ERROR
 */
void test3_object_set_description();

#endif
