// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_LINKED_LIST_H
#define MANDA_LINKED_LIST_H

#include "memory.h"

typedef struct manda_linked_node
{
    struct manda_linked_node *next;
    void *value;
} manda_linked_node_t;

typedef struct
{
    MandaAllocator allocator;
    MandaDeallocator deallocator;
    int length;
    manda_linked_node_t *head;
} manda_linked_list_t;

manda_linked_list_t *manda_new_linked_list_with_allocator(MandaAllocator allocator, MandaDeallocator deallocator);

manda_linked_list_t *manda_new_linked_list();

void manda_destroy_linked_list(manda_linked_list_t *list);

void *manda_linked_list_get(manda_linked_list_t *list, int index);

void manda_linked_list_push_back(manda_linked_list_t *list, void *value);

manda_linked_list_t *manda_linked_list_reverse(manda_linked_list_t *list);

#endif //MANDA_LINKED_LIST_H
