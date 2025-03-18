/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Daniel Martinez
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define CMD_LENGHT 30 /* It denotes the length needed for the string that stores the introduced command */
#define MAX_SIZE 30  /* It denotes the maximum sizez for an array*/

/* Store commands and it significate */
char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"n", "Next"}, {"b", "Back"}, {"l", "Left"}, {"R", "Right"}, {"t", "Take"}, {"d", "Drop"}, {"a", "Attack"}, {"c", "Chat"}};

/**
 * @brief Command
 *
 * This struct stores all the information related to a command.
 */
struct _Command {
  CommandCode code; /*!< Name of the command */
  char objname[MAX_SIZE]; /*!< Name of the object to take */
};

/** space_create allocates memory for a new space
 *  and initializes its members
 */
Command* command_create(void) {
  Command* newCommand = NULL;

  newCommand = (Command*)malloc(sizeof(Command));
  if (newCommand == NULL) {
    return NULL;
  }

  /* Initialization of an empty command*/
  newCommand->code = NO_CMD;
  newCommand->objname[0] = '\0';

  return newCommand;
}

Status command_destroy(Command* command) {
  if (!command) {
    return ERROR;
  }

  free(command);
  command = NULL;
  return OK;
}

Status command_set_code(Command* command, CommandCode code) {
  if (!command) {
    return ERROR;
  }

  command->code=code;

  return OK;
}

CommandCode command_get_code(Command* command) {
  if (!command) {
    return NO_CMD;
  }
  return command->code;
}

Status command_set_objname(Command *command, const char *objname){
  if(!command || !objname){
    return ERROR;
  }

  if(!strcpy(command->objname,objname)){
    return ERROR;
  }
  return OK;
}

char *command_get_objname(Command *command){
  if(!command){
  return NULL;
  }
  return command->objname;
}


Status command_get_user_input(Command* command) {
  char input[CMD_LENGHT] = "", *token = NULL;
  int i = UNKNOWN - NO_CMD + 1;
  CommandCode cmd;

  if (!command) {
    return ERROR;
  }

  if (fgets(input, CMD_LENGHT, stdin)) {
    token = strtok(input, " \n");
    if (!token) {
      return command_set_code(command, UNKNOWN);
    }

    cmd = UNKNOWN;
    while (cmd == UNKNOWN && i < N_CMD) {
      if (!strcasecmp(token, cmd_to_str[i][CMDS]) || !strcasecmp(token, cmd_to_str[i][CMDL])) {
        cmd = i + NO_CMD;
      } else {
        i++;
      }
    }
    if(cmd == TAKE){
      token = strtok(NULL, "0 \n");
      command_set_objname(command, token);
    }
    return command_set_code(command, cmd);
  }
  else
    return command_set_code(command, EXIT);
  
}
