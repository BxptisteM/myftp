/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_utils
*/

#include "list.h"

int list_len(list_t *list)
{
    int len = 0;

    while (list) {
        len++;
        list = list->next;
    }
    return len;
}

list_t *list_get_node(list_t *list, int pos)
{
    int i = 0;

    while (list && i < pos) {
        list = list->next;
        i++;
    }
    return list;
}
