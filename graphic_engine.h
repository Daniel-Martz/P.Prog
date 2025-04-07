/**
 * @brief It defines the graphic engine interface
 * @file graphic_engine.h
 * @author Daniel Martinez
 * @version 0.1
 * @date 2025-02-08
 * 
 * @copyright Copyright (c) 2025
 */

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"

/**
 * @brief Structure of the graphic engine
 * 
 */
typedef struct _Graphic_engine Graphic_engine; 

/**
 * @brief It creates the graphic engine doing the allocation of space and establishes to every graphic object it dimension
 * @author Daniel Martínez
 * 
 * @return It returns a pointer to the graphic engine or NULL if there is a problem during the allocation
*/
Graphic_engine *graphic_engine_create(void);

/**
 * @brief It destroys every object of the graphic engine passed by argument and frees the memories
 * @author Daniel Martínez
 * 
 * @param ge a pointer to a graphic engine
*/
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief It is responsible for updating and displaying the game's text-based 
 * graphic interface. It draws the map with the player and object's 
 * location and displays information in different screen areas.
 * (description, banner, help, and feedback). Finally, it prints the result on the terminal
 * @author Daniel Martínez
 * 
 * @param ge A pointer to Grafic_engine
 * @param game A pointer to Game
*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
