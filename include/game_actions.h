/**
 * @brief It defines the game update interface
 *
 * @file game_actions.h
 * @author Daniel Martinez
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include "command.h"
#include "character.h"
#include "game.h"
#include "types.h"
#include "object.h"

/**
 * @brief First of all it establishes the command passed as an argument as the last command of the game
 * then it does an action depending on the command:
 *  UNKNOWN: Do nothing
 *  EXIT: Abort game
 *  MOVES: Moves to somewhere
 *  INSPECT: Inspect an object
 *  CHAT: Chat with a friendly character
 *  ATTACK: Attack a non-friendly character
 *  TAKE: Pick up an object in the space
 *  DROP: Drop to the space an object
 *  RECRUIT: Recruit a friendly character
 *  ABANDON: Abandon a friendly character
 * @author Daniel Martínez
 * 
 * @param game pointer to Game structure
 * @param command  Pointer to the command that contains the action
 * @return OK if everything was correct, ERROR if not
*/
Status game_actions_update(Game *game, Command *command);

#endif
