/**
 * @brief It implements the functions needed to create a new character 
 * @file character.c
 * @author Jaime Romero
 * 
 * @version 0.1
 * @date 2025-02-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"

struct _Character
{
    Id id;/*!< The identification for the character*/
    char name[WORD_SIZE];/*!<Character's name*/
    char gdesc[G_DESC];/*!<Character's description*/
    long health;/*!<character's healthpoints*/
    Bool friendly;/*!<Boolean value indicating if the character is friendly or not*/
    char message[MAX_MESSAGE];/*!<Message delivered by the Character*/
};

/*============================Init============================*/
Character* character_create(Id id){

    Character *character=NULL;
    
    if(id==NO_ID) return NULL;

    character=(Character*)malloc(sizeof(Character));
    if(!character) return NULL;

    /*Initialzation of a new character*/
    character->id = id;
    character->name[0]= '\0';
    character->gdesc[0] = '\0';
    character->health = 0;
    character->friendly= TRUE; /*Initialized to True, it will be changed later*/
    character->message[0]='\0';

    return character;
}

Status character_destroy (Character* character){

    if(!character) return ERROR;

    free(character);
    return OK;
}

/*============================Get============================*/
Id character_get_id (Character* character){

    if (!character) return NO_ID;
    return character->id;
}

const char* character_get_name(Character* character){
    if(!character) return NULL;
    return character->name;
}

const char* character_get_gdesc(Character* character){
    if(!character) return NULL;
    return character->gdesc;
}

const char* character_get_message(Character* character){
    if(!character) return NULL;
    return character->message;
}

int character_get_health(Character* character){
    if(!character) return -1;
    return character->health;
}

Bool character_get_friendly(Character *character){
    if(!character) return FALSE;
    return character->friendly;
}

/*============================Set============================*/
Status character_set_id (Character* character, Id id){
    if (!character) return ERROR;
    character->id = id;
    return OK;
}

Status character_set_name(Character* character, const char* name){
    if (!character || !name) return ERROR;

    if (!(strcpy(character->name, name)))
    {
        return ERROR;
    }
    return OK;
}

Status character_set_gdesc(Character* character, const char* gdesc){
    if (!character || !gdesc) return ERROR;

    if (!(strcpy(character->gdesc, gdesc)))
    {
        return ERROR;
    }
    return OK;
}

Status character_set_health(Character* character, int health){
    if (!character || health < 0) return ERROR;
    
    character->health = health;
    if(health == 0){
        strcpy(character->gdesc, "x_x");
    }

    return OK;
}

Status character_set_friendly(Character* character, Bool friendly){
    if (!character) return ERROR;

    character->friendly = friendly;
    return OK;
}

Status character_set_message(Character* character, const char* message){
    if (!character || !message) return ERROR;

    if (!(strcpy(character->message, message)))
    {
        return ERROR;
    }
    return OK;    
}

/*============================Print============================*/
Status character_print (Character* character){
    if (!character) return ERROR;

    fprintf(stdout, " Character Id: %ld\n Name: %s\n Description: %s\n", character->id, character->name, character->gdesc);
    fprintf(stdout, " Health: %ld\n Friendly: %u\n Message: %s\n", character->health, character->friendly, character->message);

    return OK;
}
