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

struct _Inventory {
    Set *objs;
    int max_objs;
};

Inventory *inventory_create() {
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
    inventory->max_objs = 10;

    return inventory;
}

Status inventory_destroy(Inventory *inventory) {
    if(inventory) {
        set_destroy(inventory->objs);
        free(inventory);
    }  
}

Status inventory_add_obj_id(Inventory *inventory, Id obj_id) {
    if(inventory == NULL) {
        return ERROR;
    }
    return set_add(inventory->objs, obj_id);
}

Status inventory_delete_obj_id(Inventory *inventory, Id obj_id) {
    if(inventory == NULL) {
        return ERROR;
    }
    return set_del(inventory->objs, obj_id);
}

Status inventory_set_max_objs(Inventory *inventory, int max_objs) {
    if(inventory == NULL) {
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

Status inventory_print(Inventory *inventory) {
    if(inventory == NULL) {
        return ERROR;
    }
    if(set_print(inventory->objs) == ERROR) {
        return ERROR;
    }
    fprintf(stdout, "\nMax objects: %d", inventory->max_objs);
}