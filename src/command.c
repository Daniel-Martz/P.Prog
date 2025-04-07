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

#define CMD_LENGHT 30/*!< It denotes the length needed for the string that stores the introduced command */
#define MAX_SIZE 30/*!< It denotes the maximum sizez for an array*/

/**
 * @brief Store commands and it significate
 * 
 * @author Daniel Martínez
 */
char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"m", "Move"}, {"i", "Inspect"}, {"t", "Take"}, {"d", "Drop"}, {"a", "Attack"}, {"c", "Chat"}};

/**
 * @brief This struct stores all the information of a command
 *
 * @author Daniel Martínez
 */
struct _Command {
  CommandCode code; /*!< Name of the command */
  char objname[MAX_SIZE]; /*!< Name of the object to take */
  Direction direction; /*!< Direction to move */
  Status last_cmd_status; /*!< It contains the status of the last command*/
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
  newCommand->direction = U;
  newCommand->last_cmd_status = ERROR;

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
  if(!command){
    return ERROR;
  }

  if(!objname){
    if(!strcpy(command->objname," \0")){
      return ERROR;
    }
    return OK;
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

Status command_set_direction(Command *command, Direction direction) {
  if(!command) {
    return ERROR;
  }

  command->direction=direction;
  return OK;
}

Direction command_get_direction(Command *command) {
  if(!command) {
    return U;
  }

  return command->direction;
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
    if(cmd == DROP){
      token = strtok(NULL, "0 \n");
      command_set_objname(command, token);
    }
    if(cmd == MOVE){
      token = strtok(NULL, "0 \n");
      if (token == NULL) {
        command_set_direction(command, U);
      }
      else if (!strcasecmp(token, "North") || !strcasecmp(token, "n")) {
        command_set_direction(command, N);
      }
      else if (!strcasecmp(token, "East") || !strcasecmp(token, "e")) {
        command_set_direction(command, E);
      }
      else if (!strcasecmp(token, "South") || !strcasecmp(token, "s")) {
        command_set_direction(command, S);
      }
      else if (!strcasecmp(token, "West") || !strcasecmp(token, "w")) {
        command_set_direction(command, W);
      }
      else {
        command_set_direction(command, U);
      }
    }
    if(cmd == INSPECT){
      token = strtok(NULL, "0 \n");
      command_set_objname(command, token);
    }
    return command_set_code(command, cmd);
  }
  else
    return command_set_code(command, EXIT);
  
}

Status command_get_last_cmd_status(Command *cmd){
  if(!cmd) return ERROR;
  return cmd->last_cmd_status;
}

Status command_set_last_cmd_status(Command *cmd, Status cmd_status){
  if(!cmd) return ERROR;

  cmd->last_cmd_status = cmd_status;

  return OK;
}

Status command_get_input_from_string(Command* command, char* str) {
  char *token = NULL;
  int i = UNKNOWN - NO_CMD + 1;
  CommandCode cmd;

  if (!command) {
    return ERROR;
  }

  if (str) {
    token = strtok(str, " \n");
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

    if(cmd == DROP){
      token = strtok(NULL, "0 \n");
      command_set_objname(command, token);
    }

    if(cmd == MOVE){
      token = strtok(NULL, "0 \n");
      if (!strcasecmp(token, "North") || !strcasecmp(token, "n")) {
        command_set_direction(command, N);
      }
      else if (!strcasecmp(token, "East") || !strcasecmp(token, "e")) {
        command_set_direction(command, E);
      }
      else if (!strcasecmp(token, "South") || !strcasecmp(token, "s")) {
        command_set_direction(command, S);
      }
      else if (!strcasecmp(token, "West") || !strcasecmp(token, "w")) {
        command_set_direction(command, W);
      }
      else {
        command_set_direction(command, U);
      }
    }

    if(cmd == INSPECT){
      token = strtok(NULL, "0 \n");
      command_set_objname(command, token);
    }
    
    return command_set_code(command, cmd);
  }
  else
    return command_set_code(command, EXIT);
}
