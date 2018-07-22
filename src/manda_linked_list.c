// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <manda/linked_list.h>
#include <stdlib.h>

manda_linked_list_t *manda_new_linked_list_with_allocator(MandaAllocator allocator, MandaDeallocator deallocator) {
    manda_linked_list_t *list = (manda_linked_list_t *) malloc(sizeof(manda_linked_list_t));

    if (list != NULL) {
        list->allocator = allocator;
        list->deallocator = deallocator;
        list->length = 0;
        list->head = NULL;
    }

    return list;
}

manda_linked_list_t *manda_new_linked_list() {
    return manda_new_linked_list_with_allocator(malloc, free);
}

void manda_destroy_node(manda_linked_node_t *node, MandaDeallocator deallocator) {
    if (node != NULL) {
        manda_destroy_node(node->next, deallocator);
        deallocator(node);
    }
}

void manda_destroy_linked_list(manda_linked_list_t *list) {
    if (list != NULL) {
        manda_destroy_node(list->head, list->deallocator);
        list->deallocator(list);
    }
}

void *manda_linked_list_get(manda_linked_list_t *list, int index) {
    if (list == NULL || index >= list->length) {
        return NULL;
    } else {
        manda_linked_node_t *current = list->head;

        for (int i = 1; i < index; i++) {
            current = current->next;
        }

        return current->value;
    }
}

void manda_linked_list_push_back(manda_linked_list_t *list, void *value) {
    if (list != NULL) {
        manda_linked_node_t *node = (manda_linked_node_t *) list->allocator(sizeof(manda_linked_node_t));

        if (node != NULL) {
            node->next = NULL;
            node->value = value;

            if (list->length++ == 0) {
                list->head = node;
            } else {
                manda_linked_node_t *current = list->head;

                while (current->next != NULL) {
                    current = current->next;
                }

                current->next = node;
            }
        }
    }
}

manda_linked_list_t *manda_linked_list_reverse(manda_linked_list_t *list) {
    if (list == NULL) {
        return NULL;
    } else {
        manda_linked_list_t *new_list = manda_new_linked_list();

        if (new_list != NULL) {
            for (int i = list->length - 1; i >= 0; i--) {
                manda_linked_list_push_back(new_list, manda_linked_list_get(list, i));
            }
        }

        return new_list;
    }
}