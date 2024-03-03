/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_add_begin
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_add_begin(list_t *list, char *data)
{
    list_t *begin = malloc(sizeof(list_t));

    if (begin == NULL)
        return (NULL);
    if (list == NULL) {
        begin->next = NULL;
        return (begin);
    }
    begin->next = list;
    return (begin);
}
