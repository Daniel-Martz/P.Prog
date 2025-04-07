/**
 * @brief It defines the functions used to create a new character 
 * @file character.h
 * @author Jaime Romero
 * 
 * @version 0.1
 * @date 2025-02-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "types.h"

#define G_DESC 7/* It establishes the maximum size for gdesc*/
#define MAX_MESSAGE 100 /* It establishes the maximum length of the character message*/

/**
 * @brief Struct of the character
 * 
 */
typedef struct _Character Character;

/*============================Init============================*/

/**
 * @brief Creates a new character from a certain Id given
 * @author Jaime Romero
 *
 * @param id Character identifier
 * 
 * @return A new character, initiaized
 */
Character* character_create(Id id);

/**
 * @brief It frees the memory stored for Character
 * @author Jaime Romero
 * 
 * @param character A pointer to Character
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status character_destroy (Character* character);

/*============================Get============================*/
/**
 * @brief It gets the id of the character
 * @author Jaime Romero
 *
 * @param character a pointer to the character
 * @return the id of the character
 */
Id character_get_id (Character* character);

/**
 * @brief Gets the character's name
 * @author Jaime Romero
 *
 * @param character a pointer to Character
 * @return a string with the name of the character
 */
const char* character_get_name(Character* character);

/**
 * @brief Gets the character's description
 * @author Jaime Romero
 *
 * @param character a pointer to Character
 * @return a string with the description of the character
 */
const char* character_get_gdesc(Character* character);

/**
 * @brief Gets the character's message
 * @author Jaime Romero
 *
 * @param character a pointer to Character
 * @return a string with the message the character says
 */
const char* character_get_message(Character* character);

/**
 * @brief Reads the character's health
 * @author Jaime Romero
 *
 * @param character a pointer to Character
 * @return An integrer with the character's health
 */
int character_get_health(Character* character);

/**
 * @brief Gets if the character is friendly or not
 * @author Jaime Romero
 *
 * @param character A pointer to Character
 * @return TRUE if the character is friendly or FALSE if not
 */
Bool character_get_friendly(Character* character);

/*============================Set============================*/

/**
 * @brief Assigns an id to a character
 * @author Jaime Romero
 *
 * @param character a pointer to the character
 * @param id The id of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_id (Character* character, Id id);

/**
 * @brief Assigns a name to the character
 * @author Jaime Romero
 *
 * @param character a pointer to Character
 * @param name Character's name
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status character_set_name(Character* character, const char* name);

/**
 * @brief Defines the character's description
 * @author Jaime Romero
 *
 * @param character A pointer to Character
 * @param gdesc Character's description
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status character_set_gdesc(Character* character, const char* gdesc);

/**
 * @brief Establishes the character's hp
 * @author Jaime Romero
 *
 * @param character a pointer to Character
 * @param health Character's healthpoints
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status character_set_health(Character* character, int health);

/**
 * @brief Sets if the character's character (friendly or not)
 * @author Jaime Romero
 *
 * @param character a pointer to Character
 * @param friendly A boolean value indicating if the character is friendly or not
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status character_set_friendly(Character* character, Bool friendly);

/**
 * @brief Sets the character's message
 * @author Jaime Romero
 *
 * @param character a pointer to Character
 * @param message The message given by the character
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status character_set_message(Character* character, const char* message);

/*============================Print============================*/

/**
 * @brief Prints the character's information
 * The function displays the character's information by screen
 * @author Jaime Romero
 * 
 * @param character A pointer to Character
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status character_print (Character* character);



#endif
