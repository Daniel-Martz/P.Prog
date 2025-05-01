/**
 * @brief It implements the Inventory module
 * 
 * @file inventory.c
 * @author Jimena Sanchiz
 * 
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 */
#include "inventory.h"
#define MAX_OBJ 10/*!< It defines the maximum capacity for the bagpack*/

/**
 * @brief This struct stores all the information of an inventory.
 *
 * @author Daniel Martinez
 */
struct _Inventory {
    Set *objs; /*!< A set of object ids */
    int max_objs; /*!< The maximum number of object ids */
};

Inventory *inventory_create(void) {
    Inventory *inventory = NULL;
    inventory = (Inventory *) malloc (sizeof(Inventory));
    if(inventory == NULL) {
        return NULL;
    }
    inventory->objs = set_create();
    if(inventory->objs == NULL) {
        free(inventory);
        return NULL;
    }
    inventory->max_objs = MAX_OBJ;

    return inventory;
}

Status inventory_destroy(Inventory *inventory) {
    Status state = ERROR;

    if(inventory == NULL){
        return state;
    }

    state = set_destroy(inventory->objs);
    free(inventory);  
    return state;
}

Status inventory_add_obj_id(Inventory *inventory, Id obj_id) {
    if(inventory == NULL || obj_id == NO_ID || set_get_nids(inventory->objs) >= inventory->max_objs) {
        return ERROR;
    }
    return set_add(inventory->objs, obj_id);
}

Status inventory_delete_obj_id(Inventory *inventory, Id obj_id) {
    if(inventory == NULL || obj_id == NO_ID) {
        return ERROR;
    }
    return set_del(inventory->objs, obj_id);
}

Status inventory_set_max_objs(Inventory *inventory, int max_objs) {
    if(inventory == NULL || max_objs < 0) {
        return ERROR;
    }
    inventory->max_objs = max_objs;
    return OK;
}

int inventory_get_max_objs(Inventory *inventory) {
    if(inventory == NULL) {
        return -1;
    }
    return inventory->max_objs;
}

int inventory_get_n_objs(Inventory *inventory) {
    if(inventory == NULL) {
        return POINT_ERROR;
    }
    return set_get_nids(inventory->objs);
}

Id *inventory_get_obj_ids(Inventory *inventory) {
    if(inventory == NULL) return NULL;
    return set_get_ids(inventory->objs);
}

Status inventory_print(Inventory *inventory) {
    Status state = ERROR;
    if(inventory == NULL) {
        return ERROR;
    }
   
    state = set_print(inventory->objs);
    fprintf(stdout, "\nMax objects: %d", inventory->max_objs);

    return state;
}

Status inventory_object_is_there(Inventory *inv, Id id){
    return set_id_is_there(inv->objs, id);
}

