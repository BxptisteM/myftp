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
