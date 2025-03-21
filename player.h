/**
 * @brief It defines the player module
 * @file player.h
 * @author Daniel Martinez y Jaime Romero
 * 
 * @version 0.1
 * @date 2025-02-7
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

#define G_DESC 7

typedef struct _Player Player;

/*============================Init============================*/

/**
 * @brief Creates a new player from a certain Id given
 * @author Daniel Martinez
 *
 * @param id Player identifier
 * 
 * @return A new player, initiaized
 */
Player* player_create (Id id);

/**
 * @brief it destroys a player, freeing the allocated memory for it
 * @author Daniel Martinez
 *
 * @param player a pointer to the player that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_destroy (Player* player);


/*============================Get============================*/

/**
 * @brief It gets the id of the player
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @return the id of the player
 */
Id player_get_id (Player* player);

/**
 * @brief It gets the object the player is carrying
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @return the object that the player is carrying
 */
Id player_get_object (Player* player);

/**
 * @brief Gets the player's name
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @return a string with the name of the player
 */
const char* player_get_name (Player* player);

/**
 * @brief Reads the player's health
 * @author Jaime Romero
 *
 * @param player a pointer to Player
 * @return An integrer with the player's health
 */
int player_get_health(Player* player);

/**
 * @brief It gets the player's location
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @return the location of the player
 */
Id player_get_location (Player* player);

/**
 * @brief Gets the player's description
 * @author Jaime Romero
 *
 * @param player a pointer to Player
 * @return a string with the player's description
 */
const char* player_get_gdesc(Player *player);

/*============================Set============================*/

/**
 * @brief Assigns an id to a player
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_id (Player* player, Id id);

/**
 * @brief Assigns a name to a player
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_name (Player* player, const char* name);

/**
 * @brief Changes the object a player is carrying
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_object (Player* player, Id object);

/**
 * @brief Establishes the player's hp
 * @author Jaime Romero
 *
 * @param player a pointer to Player
 * @param health Player's healthpoints
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status player_set_health(Player* player, int health);

/**
 * @brief Changes the player's location
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_location (Player* player, Id location);

/**
 * @brief Defines the player's description
 * @author Jaime Romero
 *
 * @param Player A pointer to player
 * @param gdesc Character's description
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status player_set_gdesc(Player *player, const char* gdesc);

/*============================Print============================*/

/**
 * @brief Prints the player's information
 * The function displays the player's Id, location, object and name
 * @author Daniel Martinez
 * 
 * @param player A pointer to the player
 * @return OK if everything goes well, ERROR if there is any failure
 */
Status player_print (Player* player);

#endif
