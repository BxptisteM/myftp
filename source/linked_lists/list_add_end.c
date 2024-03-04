/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_add_end
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_add_end(list_t *list, int fd)
{
    list_t *end = malloc(sizeof(list_t));
    list_t *tmp = list;

    if (end == NULL)
        return (NULL);
    end->fd = fd;
    end->username = NULL;
    end->password = NULL;
    end->next = NULL;
    if (list == NULL)
        return (end);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = end;
    return (list);
}
