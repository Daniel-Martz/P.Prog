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

/**
 * @brief Applies a random healing effect to the player
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * The function heals the player with a 20% probability. 
 * It does not apply the effect if the game is in deterministic mode.
 */
void game_rules_random_heal(Game *game);

/**
 * @brief Applies a random attack effect to the player
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * The function checks whether a hostile character is in the player's space. 
 * If a hostile character exists, the player has a 10% chance of being attacked and losing one hit point. 
 * The function does not execute in deterministic mode.
 */
void game_rules_random_attack(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard1" has 0 health (dies), the function creates a key ("Key1") 
 * that can be used to open a door (linked via `link1_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door1(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard2" has 0 health (dies), the function creates a key ("Key2") 
 * that can be used to open a door (linked via `link2_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door2(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard3" has 0 health (dies), the function creates a key ("Key3") 
 * that can be used to open a door (linked via `link3_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door3(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard4" has 0 health (dies), the function creates a key ("Key4") 
 * that can be used to open a door (linked via `link4_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door4(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard5" has 0 health (dies), the function creates a key ("Key5") 
 * that can be used to open a door (linked via `link5_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door5(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard6" has 0 health (dies), the function creates a key ("Key6") 
 * that can be used to open a door (linked via `link6_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door6(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard7" has 0 health (dies), the function creates a key ("Key7") 
 * that can be used to open a door (linked via `link7_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door7(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard8" has 0 health (dies), the function creates a key ("Key8") 
 * that can be used to open a door (linked via `link8_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door8(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard9" has 0 health (dies), the function creates a key ("Key9") 
 * that can be used to open a door (linked via `link9_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door9(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard10" has 0 health (dies), the function creates a key ("Key10") 
 * that can be used to open a door (linked via `link10_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door10(Game *game);

/**
 * @brief Generates a key when the guard dies
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * If the guard named "Guard11" has 0 health (dies), the function creates a key ("Key11") 
 * that can be used to open a door (linked via `link11_id`). 
 * The key is made movable and added to the game, appearing in the player's location.
 */
void game_rules_open_door11(Game *game);

/**
 * @brief Checks if the boss has been defeated
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * The function verifies whether the boss character's health has reached zero.
 * If the boss is defeated, the game is marked as finished, and a congratulatory message is displayed.
 */
void game_rules_check_boss_defeat(Game *game);

/**
 * @brief Changes the turn in the game
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * The function manages turn progression among multiple players. 
 * If the game has more than one player and the last command executed was a successful guess, 
 * the turn advances to the next player cyclically. The function does not modify the turn if 
 * the game is finished or if there is only one player.
 */
void game_rules_change_turn(Game *game);

/**
 * @brief Executes all game rule functions
 * @author Jorge Martín
 * @param game Pointer to Game
 * 
 * The function sequentially runs various game mechanics, including random healing, random attacks, 
 * door unlocking conditions, checking boss defeat, and turn management. 
 * Each individual rule function is executed to ensure the game's logic progresses as expected.
 */
void game_rules_run_all(Game *game);

#endif

