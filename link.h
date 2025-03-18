/**
 * @brief It defines the link module
 * @file link.h
 * @author Jorge Martin
 *
 * @version 0.1
 * @date 2025-03-18
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Link Link;

Link *link_create(Id id);

Status link_destroy(Link *link);

char *link_get_name(Link *link);

Status link_set_name(Link *link, char *name);

Id link_get_origin(Link *link);

Status link_set_origin(Link *link, Id origin);

Id link_get_destination(Link *link);

Status link_set_destination(Link *link, Id destination);

Direction link_get_direction(Link *link);

Status link_set_direction(Link *link, Direction direction);

Bool link_get_open(Link *link);

Status link_set_open(Link *link, Bool status);

Status link_print(Link *link);

#endif