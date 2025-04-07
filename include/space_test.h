/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Jaime Romero
 * @version 0.0 
 * @date 17-02-2025
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

#include "space.h"
#include "set.h"
#include "test.h"

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Non NULL pointer to space 
 */
void test1_space_create();
/**
 * @test Test space creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();
/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK 
 */
void test1_space_set_name();
/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_name();
/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */
void test3_space_set_name();
/**
 * @test Test function for adding a new object to the space
 * @pre Object ID
 * @post Output == OK
 */
void test1_space_set_new_object();
/**
 * @test Test function for adding a new object to the space
 * @pre pointer to space = NULL 
 * @post Output == ERROR
 */
void test2_space_set_new_object();
/**
 * @test Test function for setting a character in the space
 * @pre Character ID
 * @post Output == OK
 */
void test1_space_set_character();
/**
 * @test Test function for setting a character in the space
 * @pre pointer to space = NULL 
 * @post Output == ERROR
 */
void test2_space_set_character();
/**
 * @test Test function for setting the graphic description of the space
 * @pre String with graphic description
 * @post Output == OK
 */
void test1_space_set_gdesc();
/**
 * @test Test function for setting the graphic description of the space
 * @pre pointer to space = NULL 
 * @post Output == ERROR
 */
void test2_space_set_gdesc();
/**
 * @test Test function for getting the space ID
 * @pre Space pointer is valid
 * @post Output == Space ID
 */
void test1_space_get_id();
/**
 * @test Test function for getting the space ID
 * @pre pointer to space = NULL 
 * @post Output == NO_ID
 */
void test2_space_get_id();
/**
 * @test Test function for getting the space name
 * @pre Space pointer is valid
 * @post Output == Space name
 */
void test1_space_get_name();
/**
 * @test Test function for getting the space name
 * @pre pointer to space = NULL 
 * @post Output == NULL
 */
void test2_space_get_name();
/**
 * @test Test function for getting the number of objects in the space
 * @pre Space pointer is valid
 * @post Output == Number of objects
 */
void test1_space_get_nobjects();
/**
 * @test Test function for getting the number of objects in the space
 * @pre pointer to space = NULL 
 * @post Output == NO_ID
 */
void test2_space_get_nobjects();
/**
 * @test Test function for getting the IDs of objects in the space
 * @pre Space pointer is valid
 * @post Output == Pointer to the set of object IDs
 */
void test1_space_get_objects_ids();
/**
 * @test Test function for getting the character in the space
 * @pre pointer to space = NULL 
 * @post Output == NO_ID
 */
void test1_space_get_character();
/**
 * @test Test function for getting the character in the space
 * @pre pointer to space = NULL 
 * @post Output == NO_ID
 */
void test2_space_get_character();
/**
 * @test Test function for getting the graphic description of the space
 * @pre Space pointer is valid
 * @post Output == graphic description string
 */
void test1_space_get_gdesc();
/**
 * @test Test function for getting the graphic description of the space
 * @pre pointer to space = NULL 
 * @post Output == NULL
 */
void test2_space_get_gdesc();
/**
 * @test Test function for getting the graphic description of the space
 * @pre Space pointer is valid, but graphic description is not set
 * @post Output == NULL
 */
void test3_space_get_gdesc();
/**
 * @test Test function for getting the graphic description of the space
 * @pre Space pointer is valid, but graphic description is not set
 * @post Output == NULL
 */
void test4_space_get_gdesc();
/**
 * @test Test getting discovered status from valid space
 * @pre Space with discovered status set
 * @post Returns correct discovered status
 */
void test1_space_get_discovered();
/**
* @test Test getting discovered status from NULL space
* @pre NULL space pointer
* @post Returns FALSE
*/
void test2_space_get_discovered();
/**
* @test Test setting discovered status on valid space
* @pre Valid space pointer
* @post Returns OK and status is set
*/
void test1_space_set_discovered();
/**
* @test Test setting discovered status on NULL space
* @pre NULL space pointer
* @post Returns ERROR
*/
void test2_space_set_discovered();
/**
 * @test Test printing a normal space
 * @pre Space with all fields populated
 * @post Output == OK
 */
void test1_space_print();
/**
* @test Test printing NULL space
* @pre NULL space pointer
* @post Output == ERROR
*/
void test2_space_print();
/**
* @test Test printing space with no objects
* @pre Space with no objects
* @post Output == OK
*/
void test3_space_print();
/**
* @test Test printing space with no character
* @pre Space with no character
* @post Output == OK
*/
void test4_space_print();
/**
* @test Test printing space with empty name
* @pre Space with empty name
* @post Output == OK
*/
void test5_space_print();

#endif
