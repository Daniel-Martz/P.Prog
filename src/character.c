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


/**
 * @brief This struct stores all the information of a character
 *
 * @author Daniel Martínez
 */
struct _Character
{
    Id id;/*!< The identification for the character*/
    char name[WORD_SIZE];/*!<Character's name*/
    char gdesc[G_DESC];/*!<Character's description*/
    int health;/*!<character's healthpoints*/
    int damage;/*!<character's damage points*/
    Bool friendly;/*!<Boolean value indicating if the character is friendly or not*/
    char message[MAX_MESSAGE];/*!<Message delivered by the Character*/
    Id following;/*!<Id of the player that is being followed*/
    char face[FACE_HEIGHT][FACE_WIDTH];/*!<Matrix of the character's face*/
};

/*============================Init============================*/
Character* character_create(Id id){
    int i;
    Character *character=NULL;
    
    if(id==NO_ID) return NULL;

    character=(Character*)malloc(sizeof(Character));
    if(!character) return NULL;

    /*Initialzation of a new character*/
    character->id = id;
    character->name[0]= '\0';
    character->gdesc[0] = '\0';
    character->health = 0;
    character->damage = 0;
    character->friendly= TRUE; /*Initialized to True, it will be changed later*/
    character->message[0]='\0';
    character->following = NO_ID; /*Initialized to NO_ID, it will be changed later*/
    for(i = 0; i<FACE_HEIGHT; i++){
        character->face[i][0] = '\0';
    }

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

int character_get_damage(Character* character) {
    if(!character) return -1;
    return character->damage;
}

Bool character_get_friendly(Character *character){
    if(!character) return FALSE;
    return character->friendly;
}

Id character_get_following(Character* character){
    if(!character) return NO_ID;
    return character->following;
}

const char* character_get_face(Character* character, int row){
    if (!character || row < 0 || row >= FACE_HEIGHT) return NULL;
  
    return character->face[row];
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

Status character_set_damage(Character* character, int damage) {
    if (!character || damage < 0) return ERROR;
    character->damage = damage;
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

Status character_set_following(Character* character, Id following){
    if (!character) return ERROR;

    character->following = following;
    return OK;
}

Status character_set_face(Character *character, const char face[FACE_HEIGHT][FACE_WIDTH]){
    int i;
    if(!character || !face) return ERROR;

    for(i = 0; i<FACE_HEIGHT; i++){
        if(!(strcpy(character->face[i],face[i]))){
            return ERROR;
        }
    }
    return OK;
}

/*============================Print============================*/
Status character_print (Character* character){
    int i;
    if (!character) return ERROR;

    fprintf(stdout, " Character Id: %ld\n Name: %s\n Description: %s\n", character->id, character->name, character->gdesc);
    fprintf(stdout, " Health: %d\n Damage: %d\n Friendly: %u\n Message: %s\n", character->health, character->damage, character->friendly, character->message);
    if(character->following != NO_ID){
        fprintf(stdout, " Following: %ld\n", character->following);
    }
    else{
        fprintf(stdout, " Not following anyone\n");
    }
    fprintf(stdout, " Face:\n");
    for (i = 0; i < FACE_HEIGHT; i++) {
        fprintf(stdout, "  %s\n", character->face[i]);
    }
    return OK;
}
