/**
 * @brief It defines the command interpreter interface
 *
 * @file command.h
 * @author Daniel Martinez
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define N_CMDT 2/*!< It defines a constant for the the abreviature of the command and the command*/
#define N_CMD 15/*!< It defines a constant for the number of commands */

/**
 * @brief It establishes a data type for the two posible ways to refer to a command
 * 
 * @author Daniel Martínez
 */
typedef enum { CMDS, CMDL } CommandType;

/**
 * @brief It establishses a data type for the posible 7 commands
 * 
 * @author Daniel Martínez
 */
typedef enum { NO_CMD = -1, UNKNOWN, EXIT, MOVE, INSPECT, TAKE, DROP, ATTACK, CHAT, RECRUIT, ABANDON, USE, OPEN, GUESS, COOPERATE} CommandCode;

/**
 * @brief It estiblishes a structure that will contain the name of the command
 * 
 * @author Daniel Martínez
 */
typedef struct _Command Command;

/**
 * @brief It creates a command allocating the space 
    needed and initializates it and returns it
 * @author Daniel Martinez
 *
 * @return a new command created
 */
Command* command_create(void);

/**
 * @brief  It deletes a command and free the memory, it also controls the errors
 * @author Daniel Martínez
 * 
 * @param command a pointer to a command structure
 * @return OK if everything was correct, ERROR if not
 */
Status command_destroy(Command* command);

/**
 * @brief It asignates the code passed as an argument to the command and control errors
 * @author Daniel Martínez
 * 
 * @param command a pointer to a command structure
 * @param code the code of the command
 * @return OK if everything was correct, ERROR if not
*/
Status command_set_code(Command* command, CommandCode code);

/**
 * @brief It returns the code of the command passed by argument and control errors
 * @author Daniel Martínez
 * 
 * @param command a pointer to a command structure
 * @return CommandCode It coould be NO_CMD, NEXT; EXIT...
*/
CommandCode command_get_code(Command* command);

/**
 * @brief It asignates the object name passed as an argument to the command and control errors
 * @author Daniel Martínez
 * 
 * @param command a pointer to a command structure
 * @param objname the name of the object
 * @return OK if everything was correct, ERROR if not
*/
Status command_set_strin(Command *command, const char *objname);

/**
 * @brief It returns the object name stored in the command passed by argument and control errors
 * @author Daniel Martínez
 * 
 * @param command a pointer to a command structure
 * @return A string
*/
char *command_get_strin(Command *command);

/**
 * @brief It asignates the command direction as an argument to the command and control errors
 * @author Jorge Martín
 * 
 * @param command a pointer to a command structure
 * @param direction the direction of the command
 * @return OK if everything was correct, ERROR if not
*/
Status command_set_direction(Command *command, Direction direction);

/**
 * @brief It returns the command direction stored in the command passed by argument and control errors
 * @author Jorge Martín
 * 
 * @param command a pointer to a command structure
 * @return A direction
*/
Direction command_get_direction(Command *command);

/**
 * @brief The users introduces a command and it is asigned to a variable command, controlling erors 
 * @author Daniel Martínez
 * 
 * @param command a pointer to a command structure
 * @return OK if everything was correct, ERROR if not
*/
Status command_get_user_input(Command* command);

/**
 * @brief The string has a command and it is asigned to a variable command, controlling erors 
 * @author Jorge Martín
 * 
 * @param command a pointer to a command structure
 * @param str a string with the command
 * @return OK if everything was correct, ERROR if not
*/
Status command_get_input_from_string(Command* command, char* str);

/**
 * @brief It get the status of the last command
 * 
 * @author Daniel Martínez
 * @param cmd A pointer to Command
 * @return Returns OK or ERROR
 */
Status command_get_last_cmd_status(Command *cmd);

/**
 * @brief It set the status of the command executed
 * 
 * @author Daniel Martínez
 * @param cmd A pointer to command
 * @param cmd_status A command
 * @return Returns OK or ERROR
 */
Status command_set_last_cmd_status(Command *cmd, Status cmd_status);


#endif
