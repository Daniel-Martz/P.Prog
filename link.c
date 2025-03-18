/**
 * @brief It implements the link module
 *
 * @file link.c
 * @author Jorge Martin
 *
 * @version 0.1
 * @date 2025-03-18
 *
 * @copyright Copyright (c) 2025
 */
#include "link.h"

struct _Link
{
    Id id;
    char name[MAX_NAME];
    Id origin;
    Id destination;
    Direction direction;
    Bool open;
};

Link *link_create(Id id)
{
    Link *link = NULL;

    if (id == NO_ID)
    {
        return NULL;
    }

    link = (Link *)malloc(sizeof(Link));
    if (!link)
    {
        return NULL;
    }

    link->id = id;
    link->name[0] = '\0';
    link->origin = NO_ID;
    link->destination = NO_ID;
    link->direction = N;
    link->open = FALSE;

    return link;
}

Status link_destroy(Link *link)
{
    if (link == NULL)
    {
        return ERROR;
    }

    free(link);
    return OK;
}

char *link_get_name(Link *link)
{
    if (!link)
    {
        return NULL;
    }

    return link->name;
}

Status link_set_name(Link *link, char *name)
{
    if (!link || !name)
    {
        return ERROR;
    }

    strcpy(link->name, name);
    return OK;
}

Id link_get_origin(Link *link)
{
    if (!link)
    {
        return NULL;
    }

    return link->origin;
}

Status link_set_origin(Link *link, Id origin)
{
    if (!link || origin == NO_ID)
    {
        return ERROR;
    }

    link->origin = origin;
    return OK;
}

Id link_get_destination(Link *link)
{
    if (!link)
    {
        return NULL;
    }

    return link->destination;
}

Status link_set_destination(Link *link, Id destination)
{
    if (!link || destination == NO_ID)
    {
        return ERROR;
    }

    link->destination = destination;
    return OK;
}

Direction link_get_direction(Link *link)
{
    return link->direction;
}

Status link_set_direction(Link *link, Direction direction)
{
    if (!link)
    {
        return ERROR;
    }

    link->direction = direction;
    return OK;
}

Bool link_get_open(Link *link)
{
    if (!link)
    {
        return FALSE;
    }

    return link->open;
}

Status link_set_open(Link *link, Bool status)
{
    if (!link)
    {
        return ERROR;
    }

    link->open = status;
    return OK;
}

Status link_print(Link *link) {
    if (!link)
    {
        return ERROR;
    }

    fprintf(stdout, "Link id: %ld\n", link->id);
    fprintf(stdout, "Link name: %s\n", link->name);
    fprintf(stdout, "Link origin id: %ld\n", link->origin);
    fprintf(stdout, "Link destination id: %ld\n", link->destination);
    if (link->direction==N) {
        fprintf(stdout, "Link direction: North\n");
    }
    else if (link->direction==E) {
        fprintf(stdout, "Link direction: East\n");
    }
    else if (link->direction==S) {
        fprintf(stdout, "Link direction: South\n");
    }
    else {
        fprintf(stdout, "Link direction: West\n");
    }
    if (link->open==FALSE) {
        fprintf(stdout, "Link open statues: False\n");
    }
    else {
        fprintf(stdout, "Link open statues: True\n");
    }

    return OK;
}