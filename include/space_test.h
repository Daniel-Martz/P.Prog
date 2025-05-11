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
#include "types.h"

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
 * @test Test function for setting a new character in the space
 * @pre Character ID
 * @post Output == OK
 */
void test1_space_set_newCharacter();
/**
 * @test Test function for setting a new character in the space
 * @pre pointer to space = NULL 
 * @post Output == ERROR
 */
void test2_space_set_newCharacter();
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
 * @test Test deleting an existing object from space
 * @pre Space with object
 * @post Returns OK and object count decreases
 */
void test1_space_object_del();
/**
 * @test Test deleting non-existent object from space
 * @pre Space without the object
 * @post Returns ERROR
 */
void test2_space_object_del();
/**
 * @test Test deleting object from NULL space
 * @pre NULL space pointer
 * @post Returns ERROR
 */
void test3_space_object_del();

/**
 * @test Test deleting an existing character from space
 * @pre Space with character
 * @post Returns OK and character count decreases
 */
void test1_space_character_del();
/**
 * @test Test deleting non-existent character from space
 * @pre Space without the character
 * @post Returns ERROR
 */
void test2_space_character_del();
/**
 * @test Test deleting character from NULL space
 * @pre NULL space pointer
 * @post Returns ERROR
 */
void test3_space_character_del();

/**
 * @test Test checking existing object in space
 * @pre Space with object
 * @post Returns TRUE
 */
void test1_space_object_is_there();
/**
 * @test Test checking non-existent object in space
 * @pre Space without the object
 * @post Returns FALSE
 */
void test2_space_object_is_there();
/**
 * @test Test checking object in NULL space
 * @pre NULL space pointer
 * @post Returns ERROR
 */
void test3_space_object_is_there();
/**
 * @test Test checking existing character in space
 * @pre Space with character
 * @post Returns TRUE
 */
void test1_space_character_is_there();
/**
 * @test Test checking non-existent character in space
 * @pre Space without the character
 * @post Returns FALSE
 */
void test2_space_character_is_there();
/**
 * @test Test checking character in NULL space
 * @pre NULL space pointer
 * @post Returns ERROR
 */
void test3_space_character_is_there();

/**
 * @test Test getting number of characters in space
 * @pre Space with characters
 * @post Returns correct number of characters
 */
void test1_space_get_ncharacters();

/**
 * @test Test getting number of characters from NULL space
 * @pre NULL space pointer
 * @post Returns POINT_ERROR
 */
void test2_space_get_ncharacters();

/**
 * @test Test getting number of characters from space with no characters
 * @pre Space with no characters
 * @post Returns 0
 */
void test3_space_get_ncharacters();

/**
 * @test Test getting character IDs from space with characters
 * @pre Space with characters
 * @post Returns correct array of character IDs
 */
void test1_space_get_characters_ids();

/**
 * @test Test getting character IDs from NULL space
 * @pre NULL space pointer
 * @post Returns NULL
 */
void test2_space_get_characters_ids();

/**
 * @test Test getting character IDs from space with no characters
 * @pre Space with no characters
 * @post Returns NULL
 */
void test3_space_get_characters_ids();

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
