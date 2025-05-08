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

/**
 * @test Test function for setting object health
 * @pre Valid object pointer and positive health value
 * @post Output == OK
 */
void test1_object_set_health();

/**
 * @test Test function for setting object health
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_object_set_health();

/**
 * @test Test function for getting object health
 * @pre Valid object pointer with health set
 * @post Output == Expected health value
 */
void test1_object_get_health();

/**
 * @test Test function for getting object health
 * @pre NULL object pointer
 * @post Output == 0
 */
void test2_object_get_health();

/**
 * @test Test function for setting object as movable
 * @pre Valid object pointer
 * @post Output == OK
 */
void test1_object_set_movable();

/**
 * @test Test function for setting object as movable
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_object_set_movable();

/**
 * @test Test function for checking if object is movable
 * @pre Valid object pointer with movable set
 * @post Output == TRUE
 */
void test1_object_is_movable();

/**
 * @test Test function for checking if object is movable
 * @pre NULL object pointer
 * @post Output == FALSE
 */
void test2_object_is_movable();

/**
 * @test Test function for setting object dependency
 * @pre Valid object pointer
 * @post Output == OK
 */
void test1_object_set_dependency();

/**
 * @test Test function for setting object dependency
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_object_set_dependency();

/**
 * @test Test function for getting object dependency
 * @pre Valid object pointer with dependency set
 * @post Output == Expected dependency ID
 */
void test1_object_get_dependency();

/**
 * @test Test function for getting object dependency
 * @pre NULL object pointer
 * @post Output == NO_ID
 */
void test2_object_get_dependency();

/**
 * @test Test function for setting object open ID
 * @pre Valid object pointer
 * @post Output == OK
 */
void test1_object_set_open();

/**
 * @test Test function for setting object open ID
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_object_set_open();

/**
 * @test Test function for getting object open ID
 * @pre Valid object pointer with open ID set
 * @post Output == Expected open ID
 */
void test1_object_get_open();

/**
 * @test Test function for getting object open ID
 * @pre NULL object pointer
 * @post Output == NO_ID
 */
void test2_object_get_open();

/**
 * @test Test function for setting object as offensive
 * @pre Valid object pointer
 * @post Output == OK
 */
void test1_object_set_offensive();

/**
 * @test Test function for setting object as offensive
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_object_set_offensive();

/**
 * @test Test function for checking if object is offensive
 * @pre Valid object pointer with offensive set
 * @post Output == TRUE
 */
void test1_object_get_offensive();

/**
 * @test Test function for checking if object is offensive
 * @pre NULL object pointer
 * @post Output == FALSE
 */
void test2_object_get_offensive();

/**
 * @test Test function for setting object draw representation
 * @pre Valid object pointer and draw matrix
 * @post Output == OK
 */
void test1_object_set_draw();

/**
 * @test Test function for setting object draw representation
 * @pre NULL object pointer
 * @post Output == ERROR
 */
void test2_object_set_draw();

/**
 * @test Test function for getting object draw line
 * @pre Valid object pointer and index within range
 * @post Output == Expected draw line string
 */
void test1_object_get_draw();

/**
 * @test Test function for getting object draw line
 * @pre NULL object pointer
 * @post Output == NULL
 */
void test2_object_get_draw();

/**
 * @test Test function for getting object draw line
 * @pre Valid object pointer with invalid index (-1)
 * @post Output == NULL
 */
void test3_object_get_draw();

/**
 * @test Test function for getting object draw line
 * @pre Valid object pointer with index out of bounds
 * @post Output == NULL
 */
void test4_object_get_draw();


#endif
