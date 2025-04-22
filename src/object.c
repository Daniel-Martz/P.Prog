/**
 * @brief It implements the object module
 * @file object.c
 * @author Jaime Romero
 * 
 * @version 0.1
 * @date 2025-02-08
 * 
 * @copyright Copyright (c) 2025
 */
#include "object.h"
#include <string.h>

/**
 * @brief This struct stores all the information of an object
 * 
 * @author Daniel Martínez
 */
struct _Object {
    Id id; /*!<The identification of the object*/
    char name[NAME_SIZE]; /*!<Objects name*/
    char description[MAX_DESCRIP]; /*!<The description of the object*/
    int health; /*!<The health taken or given by the object*/
    Bool movable; /*!<Boolean inidcating if the object can be moved*/
    Id dependency; /*!<Id of the object it depends on*/
    Id open; /*!<Id of the link an object can open*/
};

Object* object_create (Id id){

    Object *obj=NULL;

    if (id == NO_ID) return NULL;

    obj = (Object*)malloc(sizeof(Object));
    if (!obj) return NULL; 

    obj->id = id;
    obj->name[0] = '\0';
    obj->description[0] = '\0';
    obj->health = 0;
    obj->movable = FALSE;
    obj->dependency = NO_ID;
    obj->open = NO_ID;

    return obj;
}

Status object_destroy(Object* obj){

    if (!obj) return ERROR;

    free(obj);
    return OK;
}

Id object_get_id(Object* obj){

    if (!obj) return NO_ID;

    return obj->id;
}

Status object_set_id (Object* obj, Id id){

    if (!obj) return ERROR;

    obj->id=id;
    return OK;
}

Status object_set_name (Object* obj, char* name){

    if (!obj || !name) return ERROR;

    if (!strcpy(obj->name, name))
    {
        return ERROR;
    }

    return OK;
}

const char* object_get_name (Object* obj){
    if (!obj) return NULL;
    return obj->name;
}

const char* object_get_description(Object *obj){
    if (!obj) return NULL;
    return obj->description; 
}

Status object_set_description(Object *obj, const char *objdes){
    
    if((!obj) || (!objdes)) return ERROR;

    if(!(strcpy(obj->description, objdes))) return ERROR;

    return OK;
}

Status object_set_health(Object *obj, int health){
    if(!obj) return ERROR;
    obj->health = health;
    return OK;
}

int object_get_health(Object *obj){
    return obj->health;
}

Status object_set_movable(Object *obj, Bool mov){
    if(!obj) return ERROR;
    obj->movable = mov;
    return OK;
}

Bool object_is_movable(Object *obj){
    if(!obj) return FALSE;
    return obj->movable;
}

Status object_set_dependency(Object *obj, Id dependency){
    if(!obj) return ERROR;
    obj->dependency = dependency;
    return OK;
}

Id object_get_dependency(Object *obj){
    if(!obj) return NO_ID;
    return obj->dependency;
}

Status object_set_open(Object *obj, Id open){
    if(!obj) return ERROR;
    obj->open = open;
    return OK;
}

Id object_get_open(Object *obj){
    if(!obj) return NO_ID;
    return obj->open;
}

Status object_print (Object* obj){

    if (!obj) return ERROR;

    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", obj->id, obj->name);

    return OK;
}
