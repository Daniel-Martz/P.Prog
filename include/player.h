/**
 * @brief It defines the player module
 * @file player.h
 * @author Daniel Martinez, Jaime Romero, Jimena y Jorge
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
#include "inventory.h"

#define G_DESC 8/*!< It defines the size of the player gdesc*/

/**
 * @brief Structure of the player
 * 
 */
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
 * @brief It gets all the ids of the objects that the player ports
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @return an array of object's ids
 */
Id *player_get_objects_ids (Player *player);

/**
 * @brief It gets the backpack the player is carrying
 * @author Jimena Sanchiz
 *
 * @param player a pointer to the player
 * @return the backpack of objects that the player is carrying
 */
Inventory *player_get_backpack (Player* player);

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
 * @brief Reads the player's damage
 * @author Jimena Sanchiz
 *
 * @param player a pointer to Player
 * @return An integrer with the player's damage
 */
int player_get_damage(Player *player);

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

/**
 * @brief It gets the team of the player
 * @author Jorge Martin
 *
 * @param player a pointer to the player
 * @return the team of the player
 */
Id player_get_team(Player *player);

/*============================Set============================*/

/**
 * @brief Assigns an id to a player
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @param id The id of the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_id (Player* player, Id id);

/**
 * @brief Adds a new object to the backpack of a player
 * @author Jimena Sanchiz
 *
 * @param player a pointer to the player
 * @param obj_id The id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_add_object (Player* player, Id obj_id);

/**
 * @brief Assigns a name to a player
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @param name cont string of the player name
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_name (Player* player, const char* name);

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
 * @brief Establishes the player's dp
 * @author Jimena Sanchiz
 *
 * @param player a pointer to Player
 * @param damage Player's damage points
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status player_set_damage(Player* player, int damage);

/**
 * @brief Changes the player's location
 * @author Daniel Martinez
 *
 * @param player a pointer to the player
 * @param location The id of the location
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_location (Player* player, Id location);

/**
 * @brief Defines the player's description
 * @author Jaime Romero
 *
 * @param player A pointer to player
 * @param gdesc Character's description
 * 
 * @return OK if everything goes well, ERROR if anything goes wrong
 */
Status player_set_gdesc(Player *player, const char* gdesc);

/**
 * @brief Sets the team of the player
 * @author Jorge Martin
 *
 * @param player a pointer to the player
 * @param team The id of the team
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_team(Player *player, Id team);

/**
 * @brief Deletes an object from the backpack of a player
 * @author Jimena Sanchiz
 *
 * @param player a pointer to the player
 * @param obj_id Object id
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_delete_object(Player *player, Id obj_id);

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
