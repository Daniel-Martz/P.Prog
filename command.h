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

#define N_CMDT 2 /* It defines a constant for the the abreviature of the command and the command*/
#define N_CMD 11 /* It defines a constant for the number of commands */

/* It establishes a data type for the two posible ways to refer to a command */
typedef enum { CMDS, CMDL } CommandType;

/*It establishses a data type for the posible 7 commands*/
typedef enum { NO_CMD = -1, UNKNOWN, EXIT, NEXT, BACK, LEFT, RIGHT, TAKE, DROP, ATTACK, CHAT } CommandCode;

/*It estiblishes a structure that will contain the name of the command*/
typedef struct _Command Command;

/**
 * @brief It creates a command allocating the space 
    needed and initializates it and returns it
 * @author Daniel Martinez
 *
 * @param void There is noargument passed to the function
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
Status command_set_objname(Command *command, const char *objname);

/**
 * @brief It returns the object name stored in the command passed by argument and control errors
 * @author Daniel Martínez
 * 
 * @param command a pointer to a command structure
 * @return A string
*/
char *command_get_objname(Command *command);

/**
 * @brief The users introduces a command and it is asigned to a variable command, controlling erors 
 * @author Daniel Martínez
 * 
 * @param command a pointer to a command structure
 * @return OK if everything was correct, ERROR if not
*/
Status command_get_user_input(Command* command);

#endif
