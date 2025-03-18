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
#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include "types.h"

/**
 * @brief It assigns to the space every id, loaded from a file
 * 
 * @author Jaime Romero
 * @param game A pointer to Game
 * @param filename A string with the name of the file
 * 
 * @return OK if everything worked correctly or ERROR if it didn't
 */
Status game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief It assigns to each object its id, loaded from a file
 * 
 * @author Jaime Romero
 * @param game A pointer to Game
 * @param filename A string with the name of the file
 * 
 * @return OK if everything worked correctly or ERROR if it didn't
 */
Status game_reader_load_objects(Game *game, char *filename);

/**
 * @brief It assigns to each character its id and all the variables needed, loaded from a file
 * 
 * @author Daniel Martínez
 * @param game A pointer to Game
 * @param filename A string with the name of the file
 * 
 * @return OK if everything worked correctly or ERROR if it didn't
 */
Status game_reader_load_characters(Game *game, char *filename);

/**
 * @brief It assigns to each player its id and all the information needed
 * 
 * @author Jaime Romero
 * @param game A pointer to Game
 * @param filename A string with the name of the file
 * 
 * @return OK if everything worked correctly or ERROR if it didn't
 */
Status game_reader_load_players(Game *game, char *filename);

/**
 * @brief It reads the information for the links
 * 
 * @author Jaime Romero
 * @param game A pointer to Game
 * @param filename A string with the name of the file
 * 
 * @return OK if everything worked correctly or ERROR if it didn't
 */
Status game_reader_load_links(Game *game, char *filename);

#endif