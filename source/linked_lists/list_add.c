/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_add
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static node_t *create_node(char *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
        return NULL;
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

node_t *find_position(node_t *list, int pos)
{
    node_t *prev_node = NULL;

    for (int i = 0; i < pos && list != NULL; i++) {
        prev_node = list;
        list = list->next;
    }
    return prev_node;
}

list_t *list_add(list_t *list, char *data, int pos)
{
    node_t *new_node = create_node(strdup(data));
    node_t *prev_node = NULL;

    if (new_node == NULL)
        return list;
    if (list == NULL || pos == 0) {
        new_node->next = list;
        return new_node;
    }
    prev_node = find_position(list, pos);
    if (prev_node != NULL) {
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
    return list;
}
