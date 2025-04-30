/** 
 * @brief It declares the tests for the character module
 * 
 * @file character_test.h
 * @author Jaime Romero
 * @version 0.1 
 * @date 2025-02-24
 * @copyright GNU Public License
 */

#ifndef CHARACTER_TEST_H
#define CHARACTER_TEST_H

#include "test.h"
#include "character.h"

/**
 * @test Test character creation
 * @pre Valid character ID
 * @post Non NULL pointer to character
 */
void test1_character_create();

/**
 * @test Test character creation
 * @pre Invalid character ID (NO_ID)
 * @post Output == NULL
 */
void test2_character_create();

/**
 * @test Test function for getting character ID
 * @pre Valid character pointer
 * @post Output == character's ID
 */
void test1_character_get_id();

/**
 * @test Test function for getting character ID
 * @pre NULL character pointer
 * @post Output == NO_ID
 */
void test2_character_get_id();

/**
 * @test Test function for getting character name
 * @pre Valid character pointer with name set
 * @post Output == Expected name
 */
void test1_character_get_name();

/**
 * @test Test function for getting character name
 * @pre NULL character pointer
 * @post Output == NULL
 */
void test2_character_get_name();

/**
 * @test Test function for getting character graphical description
 * @pre Valid character pointer with gdesc set
 * @post Output == Expected graphical description
 */
void test1_character_get_gdesc();

/**
 * @test Test function for getting character graphical description
 * @pre NULL character pointer
 * @post Output == NULL
 */
void test2_character_get_gdesc();

/**
 * @test Test function for getting character message
 * @pre Valid character pointer with message set
 * @post Output == Expected message
 */
void test1_character_get_message();

/**
 * @test Test function for getting character message
 * @pre NULL character pointer
 * @post Output == NULL
 */
void test2_character_get_message();

/**
 * @test Test function for getting character health
 * @pre Valid character pointer with health set
 * @post Output == Expected health value
 */
void test1_character_get_health();

/**
 * @test Test function for getting character health
 * @pre NULL character pointer
 * @post Output == POINT_ERROR (-1)
 */
void test2_character_get_health();

/**
 * @test Test function for getting character friendliness
 * @pre Valid character pointer with friendly status set
 * @post Output == Expected friendly value
 */
void test1_character_get_friendly();

/**
 * @test Test function for getting character friendliness
 * @pre NULL character pointer
 * @post Output == FALSE
 */
void test2_character_get_friendly();

/**
 * @test Test function for getting the id of the player that the character is following
 * @pre Valid character pointer with the id of the followed character
 * @post Output == Expected player id
 */
void test1_character_get_following();

/**
 * @test Test function for getting characters followed player
 * @pre NULL character pointer
 * @post Output == FALSE
 */
void test2_character_get_following();

/**
 * @test Test function for setting character ID
 * @pre Valid character pointer and ID
 * @post Output == OK
 */
void test1_character_set_id();

/**
 * @test Test function for setting character ID
 * @pre NULL character pointer
 * @post Output == ERROR
 */
void test2_character_set_id();

/**
 * @test Test function for setting character name
 * @pre Valid character pointer and non-NULL name
 * @post Output == OK
 */
void test1_character_set_name();

/**
 * @test Test function for setting character name
 * @pre NULL character pointer
 * @post Output == ERROR
 */
void test2_character_set_name();

/**
 * @test Test function for setting character name
 * @pre Valid character pointer and NULL name
 * @post Output == ERROR
 */
void test3_character_set_name();

/**
 * @test Test function for setting character graphical description
 * @pre Valid character pointer and non-NULL gdesc
 * @post Output == OK
 */
void test1_character_set_gdesc();

/**
 * @test Test function for setting character graphical description
 * @pre NULL character pointer
 * @post Output == ERROR
 */
void test2_character_set_gdesc();

/**
 * @test Test function for setting character graphical description
 * @pre Valid character pointer and NULL gdesc
 * @post Output == ERROR
 */
void test3_character_set_gdesc();

/**
 * @test Test function for setting character health
 * @pre Valid character pointer and positive health value
 * @post Output == OK
 */
void test1_character_set_health();

/**
 * @test Test function for setting character health
 * @pre Valid character pointer and negative health value
 * @post Output == ERROR
 */
void test2_character_set_health();

/**
 * @test Test function for setting character health
 * @pre NULL character pointer
 * @post Output == ERROR
 */
void test3_character_set_health();

/**
 * @test Test function for setting character friendliness
 * @pre Valid character pointer
 * @post Output == OK
 */
void test1_character_set_friendly();

/**
 * @test Test function for setting character friendliness
 * @pre NULL character pointer
 * @post Output == ERROR
 */
void test2_character_set_friendly();

/**
 * @test Test function for setting character message
 * @pre Valid character pointer and non-NULL message
 * @post Output == OK
 */
void test1_character_set_message();

/**
 * @test Test function for setting character message
 * @pre Valid character pointer and NULL message
 * @post Output == ERROR
 */
void test2_character_set_message();

/**
 * @test Test function for setting character message
 * @pre NULL character pointer
 * @post Output == ERROR
 */
void test3_character_set_message();

/**
 * @test Test function for setting the id of the player that the character is following
 * @pre Valid character pointer
 * @post Output == OK
 */
void test1_character_set_following();

/**
 * @test Test function for setting the id of the player that the character is following
 * @pre NULL character pointer
 * @post Output == ERROR
 */
void test2_character_set_following();

#endif