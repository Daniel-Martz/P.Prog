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

#define G_DESC 7 /*!< It establishes the maximum size for gdesc*/
#define MAX_MESSAGE 400/*!< It establishes the maximum length of the character message*/
#define FACE_HEIGHT 11/*!<Constant for the height of the character face*/ 
#define FACE_WIDTH 19/*!<Constant for the width of the character face*/

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
char* character_get_gdesc(Character* character);

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
 * @brief Reads the character's damage
 * @author Jimena Sanchiz
 *
 * @param character a pointer to Character
 * @return An integrer with the character's damage
 */
int character_get_damage(Character* character);

/**
 * @brief Gets if the character is friendly or not
 * @author Jaime Romero
 *
 * @param character A pointer to Character
 * @return TRUE if the character is friendly or FALSE if not
 */
Bool character_get_friendly(Character* character);

/**
 * @brief Gets the id of the player that the character is following
 * @author Jimena Sanchíz
 *
 * @param character A pointer to Character
 * @return The id of the player that the character is following
 */
Id character_get_following(Character* character);

/**
 * @brief Gets a row of the face description of a character
 * @author Daniel Martínez
 *
 * @param character A pointer to character
 * @param row the row of the matrix
 * @return a string with a line of the face description
 */
const char* character_get_face(Character* character, int row);

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
 * @brief Establishes the character's dp
 * @author Jimena Sanchiz
 *
 * @param character a pointer to Character
 * @param damage Character's damage points
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status character_set_damage(Character* character, int damage);

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

/**
 * @brief Sets the id of the player that the character is following
 * @author Jimena Sanchíz
 *
 * @param character A pointer to Character
 * @param id The id of the player that the character is following
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status character_set_following(Character* character, Id id);

/**
 * @brief Sets the a matrix of characters that is the face of him
 * @author Daniel Martínez
 *
 * @param character A pointer to Character
 * @param face The matrix of chars for the face
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status character_set_face(Character *character, const char face[FACE_HEIGHT][FACE_WIDTH]);

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
