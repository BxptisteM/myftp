/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_add_begin
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_add_begin(list_t *list, int fd)
{
    list_t *begin = malloc(sizeof(list_t));

    if (begin == NULL)
        return (NULL);
    begin->fd = fd;
    begin->username = NULL;
    begin->password = NULL;
    begin->next = list;
    return (begin);
}
