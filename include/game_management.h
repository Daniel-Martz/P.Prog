/**
 * @brief It defines the functions in charge of creating the spaces  
 * @file game_reader.h
 * @author Jaime Romero, Daniel Martínez
 * 
 * @version 0.1
 * @date 2025-02-08
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "game.h"
#include "types.h"
#include "link.h"
#include "inventory.h"

/**
 * @brief It loads the information from a file to the game
 * 
 * @author Jaime Romero
 * @param game A pointer to Game
 * @param filename A string with the name of the file
 * 
 * @return Game with all the information loaded
 */
Game *game_management_load(char *filename);

/**
 * @brief It saves the game in a file
 * 
 * @author Jaime Romero
 * @param game A pointer to Game
 * @param filename A string with the name of the file
 * 
 * @return OK if everything worked correctly or ERROR if it didn't
 */
Status game_management_save(Game *game, char *filename);

#endif
