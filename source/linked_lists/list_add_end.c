/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_add_end
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_add_end(list_t *list, char *data)
{
    list_t *end = malloc(sizeof(list_t));
    list_t *tmp = NULL;

    if (end == NULL)
        return (NULL);
    end->next = NULL;
    if (list == NULL)
        return (end);
    tmp = list;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = end;
    return (list);
}
