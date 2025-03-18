/**
 * @brief It implements the Set module
 * 
 * @file set.c
 * @author Jaime Romero
 * 
 * @version 0.1
 * @date 2025-02-18
 * 
 * @copyright Copyright (c) 2025
 */
#include "set.h"

struct _Set {
    Id *ids;
    long n_ids;
};

/*Public functions*/

Set* set_create(void){
    int i;
    Set *set = NULL;
    
    set=(Set*)malloc(sizeof(Set));
    if (!set) return NULL;
    
    set->ids=(Id*)calloc(MAX_SET, sizeof(Id));
    if (!set->ids){ 
        free(set); /*If ids fails, set is also freed to avoid memory leaks*/
        return NULL;
    }
    
    for(i = 0; i<MAX_SET; i++){
        set->ids[i] = NO_ID;
    }
    
    set->n_ids=0;

    return set;
}

Status set_destroy (Set* set){

    if (!set) return ERROR;

    set->n_ids=0;
    free(set->ids);
    free(set);

    return OK;
}

Status set_add (Set* set, Id id){
    
    int i=0;

    /*Checks if set exists and if the number of Ids is lower than the Max amount*/
    if (!set || set->n_ids >= MAX_SET) return ERROR; 

    /*Checks if the Id is not already in the array of Ids to avoid duplicates*/
    for (i = 0; i < set->n_ids; i++)
    {
        if (set->ids[i]==id)
        {
            return ERROR;
        }   
    }
    
    set->ids[set->n_ids] = id; /*The new id is added to the last position of the array of ids*/
    set->n_ids++;

    return OK;    
}

Status set_del (Set* set, Id id){

    int i=0, position=-1; /*The position is never going to be -1, so if the position is still -1 it means the id hasn't been found*/

    /*Checks if set esxits and if the number of ids is greater than 0 (if it is 0, there is nothing to be deleted)*/
    if (!set || set->n_ids == 0) return ERROR; 

    /*Gets the position of the id that must be deleted*/
    for (i = 0; i < set->n_ids; i++)
    {
        if (set->ids[i]==id)
        {
            position=i;
            break;
        }
    }
    
    if (position==-1) return ERROR; /*If the id wasn't found, ERROR is returned*/
    /*The rest of the ids are moved forward to cover the empty space created by the deleted Id*/
    for (i = position; i < set->n_ids - 1; i++)
    {
        set->ids[i]=set->ids[i+1];
    }
    set->ids[set->n_ids] = NO_ID;
    set->n_ids--;

    return OK;
}

Status set_print (Set* set){

    int i=0;

    if (!set) return ERROR;

    for (i = 0; i < set->n_ids; i++)
    {
        fprintf(stdout, "Elemento %d: %ld\n", i+1, set->ids[i]);
    }
    
    return OK;
}

long set_get_nids(Set* set){
    if(!set) return POINT_ERROR;
    return set->n_ids;
}

Id* set_get_ids(Set* set){
    if(!set) return NULL;

    return set->ids;
}

Status set_id_is_there(Set* set, Id id){
    int i;

    if(!set || id == NO_ID) return ERROR;

    for(i=0;i<set->n_ids;i++){
        if(set->ids[i]==id){
            return OK;
        }
    }
    return ERROR;
}
