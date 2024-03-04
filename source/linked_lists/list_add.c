/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_add
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *create_node(int fd)
{
    list_t *new = malloc(sizeof(list_t));

    if (new == NULL)
        return NULL;
    new->fd = fd;
    new->username = NULL;
    new->password = NULL;
    new->next = NULL;
    return new;
}

list_t *list_add(list_t *list, int fd, int pos)
{
    list_t *new = create_node(fd);
    list_t *pre = NULL;
    list_t *cur = list;
    int i = 0;

    if (new == NULL)
        return list;
    if (list == NULL || pos == 0) {
        new->next = list;
        return new;
    }
    while (cur != NULL && i < pos) {
        i++;
        pre = cur;
        cur = cur->next;
    }
    pre->next = new;
    new->next = cur;
    return list;
}
