/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** node_print
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_node(list_t *list, int position)
{
    node_t *node = list;

    for (int i = 0; i != position; i++) {
        node = node->next;
    }
    printf("%s", node->data);
}
