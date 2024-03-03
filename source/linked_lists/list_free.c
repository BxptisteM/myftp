/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_free
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_free(list_t *list)
{
    list_t *tmp;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
    return NULL;
}
