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
#define MAX_DESCRIP 100

/**
 * @brief This struct stores all the information of an object
 *
 * @author Daniel Martínez
 */
struct _Object {
    Id id; /*!<The identification of the object*/
    char name[NAME_SIZE]; /*!<Objects name*/
    char description[MAX_DESCRIP] /*!<The description of the object*/
};

Object* object_create (Id id){

    Object *obj=NULL;

    if (id == NO_ID) return NULL;

    obj = (Object*)malloc(sizeof(Object));
    if (!obj) return NULL; 

    obj->id = id;
    obj->name[0] = '\0';

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

Status object_print (Object* obj){

    if (!obj) return ERROR;

    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", obj->id, obj->name);

    return OK;
}
