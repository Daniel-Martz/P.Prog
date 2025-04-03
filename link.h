/**
 * @brief It defines the link module
 * @file link.h
 * @author Jorge Martin
 *
 * @version 0.1
 * @date 2025-03-18
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

typedef struct _Link Link;

/**
 * @brief Creates the strcuture 'Link', allocating memory and initializing its arguments
 * 
 * @author Jorge Martín
 * 
 * @return A pointer to set with the structure (and its arguments) created
 */
Link *link_create(Id id);

/**
 * @brief "Destroys" the link and frees its memory
 * 
 * @author Jorge Martín
 * 
 * @param link A pointer to the link
 * 
 * @return OK if everything worked correctly, ERROR if it didn't
 */
Status link_destroy(Link *link);

/**
 * @brief Gets the name of the link
 * 
 * @author Jorge Martín
 *
 * @param link A pointer to the link
 * 
 * @return A string with the link's name
 */
char *link_get_name(Link *link);

/**
 * @brief Assigns a name to the link
 * 
 * @author Jorge Martín
 * 
 * @param obj A pointer to the link
 * @param name A string with the link's name
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status link_set_name(Link *link, char *name);

/**
 * @brief Gets the id of the link's origin
 * 
 * @author Jorge Martín
 *
 * @param link A pointer to the link
 * 
 * @return The id of the link's origin (NO_ID if there's an error)
 */
Id link_get_origin(Link *link);

/**
 * @brief Sets the id of the link's origin
 * 
 * @author Jorge Martín
 *
 * @param link A pointer to the link
 * @param origin The id of the origin space
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status link_set_origin(Link *link, Id origin);

/**
 * @brief Gets the id of the link's destination
 * 
 * @author Jorge Martín
 *
 * @param link A pointer to the link
 * 
 * @return The id of the link's destination (NO_ID if there's an error)
 */
Id link_get_destination(Link *link);

/**
 * @brief Sets the id of the link's destination
 * 
 * @author Jorge Martín
 *
 * @param link A pointer to the link
 * @param destination The id of the destination space
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status link_set_destination(Link *link, Id destination);

/**
 * @brief Gets the direction of the link 
 * 
 * @author Jorge Martín
 *
 * @param link A pointer to the link
 * 
 * @return The direction of the link
 */
Direction link_get_direction(Link *link);

/**
 * @brief Sets the direction of the link
 * 
 * @author Jorge Martín
 *
 * @param link A pointer to the link
 * @param direction The direction of the link
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status link_set_direction(Link *link, Direction direction);

/**
 * @brief Gets if the link is open or not
 * 
 * @author Jorge Martín
 *
 * @param link A pointer to the link
 * 
 * @return If the link is open(TRUE) or not(FALSE) (FALSE if there's a failure)
 */
Bool link_get_open(Link *link);

/**
 * @brief Sets the link open status
 * 
 * @author Jorge Martín
 *
 * @param link A pointer to the link
 * @param status The open status of the link
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status link_set_open(Link *link, Bool status);

/**
 * @brief Prints the link
 * 
 * @author Jorge Martín
 *
 * @param link A pointer to the link
 * 
 * @return OK if everything goes well, ERROR if there is a failure
 */
Status link_print(Link *link);

#endif
