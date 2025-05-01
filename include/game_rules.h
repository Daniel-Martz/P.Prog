/**
 * @brief It defines the game rules functions
 *
 * @file game_rules.h
 * @author Jorge Martín
 * @version 0
 * @date 22-04-2025
 * @copyright Copyright (c) 2025
 */

#ifndef GAME_RULES_H
#define GAME_RULES_H
 
#include "game.h"
#include "types.h"
 

void game_rules_random_heal(Game *game);

void game_rules_random_attack(Game *game);

void game_rules_change_turn(Game *game);

void game_rules_open_final_door(Game *game);

void game_rules_check_boss_defeat(Game *game);

void game_rules_run_all(Game *game);
 
#endif

