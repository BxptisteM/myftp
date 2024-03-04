/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_print
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_list(list_t *list)
{
    for (node_t *node = list; node != NULL; node = node->next)
        printf("%d\n", node->fd);
}
