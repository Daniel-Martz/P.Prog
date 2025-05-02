/**
 * @brief It implements the player module
 * @file player.h
 * @author Daniel Martinez y Jaime Romero
 * 
 * @version 0.1
 * @date 2025-02-7
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"

#define INIT_HEALTH 0/*!< Constant for the initial hp of the player*/
#define INIT_DAMAGE 0/*!< Constant for the initial dp of the player*/
#define MAX_NAME 20/*!< It defines the maximum length of the player name*/
/**
 * @brief This struct stores all the information of a player
 *
 * @author Daniel Martínez
 */
struct _Player {
    Id id; /*!<The identification for the player*/
    char name[MAX_NAME]; /*!<Player's name*/
    Id location; /*!<Player's location (stored as an Id)*/
    Inventory *backpack; /*!<IInventory of the objects carried by the player*/
    int health; /*!<Player's healthpoints*/
    int damage; /*!<Player's damage points*/
    char gdesc[G_DESC]; /*!<Player's graphic description*/
};

/*============================Init============================*/
Player* player_create (Id id){

    Player *newPlayer=NULL;

    /*Error control*/
    if (id == NO_ID) return NULL;

    newPlayer= (Player*)malloc(sizeof(Player));
    if (!newPlayer) return NULL; 

    /*Initialization of a new Player*/
    newPlayer->id = id;
    newPlayer->name[0] = '\0';
    newPlayer->location = NO_ID;
    if((newPlayer->backpack = inventory_create()) == NULL) return NULL;
    newPlayer->health = INIT_HEALTH;
    newPlayer->damage = INIT_DAMAGE;
    newPlayer->gdesc[0] = '\0';

    return newPlayer;
}

Status player_destroy (Player* player){

    if (!player) return ERROR;

    inventory_destroy(player->backpack);
    free(player);
    return OK;
}

/*============================Get============================*/
Id player_get_id (Player* player){
    if (!player) return NO_ID;
    return player->id;
}

Id *player_get_objects_ids (Player *player){
    Inventory *player_bp = NULL;

    if(!player) return NULL;
    player_bp = player_get_backpack(player);

    return inventory_get_obj_ids(player_bp);

}

Inventory *player_get_backpack (Player* player){
    if (!player) return NULL;
    return player->backpack;
}

const char* player_get_name (Player* player){
    if (!player) return NULL;
    return player->name;
}

int player_get_health(Player* player){
    if(!player) return NO_ID;
    return player->health;
}

int player_get_damage(Player *player) {
    if(!player) return NO_ID;
    return player->damage;
}

Id player_get_location (Player* player){
    if (!player) return NO_ID;
    return player->location;
}

const char* player_get_gdesc(Player *player){
    if (!player) return NULL;
    return player->gdesc;
}

/*============================Set============================*/
Status player_set_id (Player* player, Id id){
    if (!player) return ERROR;
    player->id = id;
    return OK;
}

Status player_add_object (Player* player, Id obj_id){
    if (!player) return ERROR;
    return inventory_add_obj_id(player->backpack, obj_id);
}

Status player_set_name (Player* player, const char* name){
    if (!player || !name) return ERROR;

    if (!strcpy(player->name, name))
    {
        return ERROR;
    }

    return OK;
}

Status player_set_health(Player* player, int health){
    if (!player || health < 0) return ERROR;

    player->health = health;

    return OK;
}

Status player_set_damage(Player *player, int damage) {
    if (!player || damage < 0) return ERROR;
    player->damage = damage;
    return OK;
}

Status player_set_location (Player* player, Id location){
    if (!player) return ERROR;
    player->location = location;
    return OK;
}


Status player_set_gdesc(Player *player, const char* gdesc){
    if (!player || !gdesc) return ERROR;
    
    if (!(strcpy(player->gdesc, gdesc)))
    {
        return ERROR;
    }
    return OK;
}

Status player_delete_object(Player *player, Id obj_id) {
    if(!player) return ERROR;
    return inventory_delete_obj_id(player->backpack, obj_id);
}

/*============================Print============================*/
Status player_print (Player* player){
    if (!player) return ERROR;

    fprintf(stdout, " Player ID: %ld\n Name: %s\n", player->id, player->name);
    return OK;
}
