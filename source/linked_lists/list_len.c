/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_len
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int list_get_len(list_t *list)
{
    int count = 0;
    node_t *current = list;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return (count);
}
