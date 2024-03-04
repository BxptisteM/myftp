/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_add
*/

#include "server.h"
#include "list.h"

list_t *list_add(list_t *list, client_t *client)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *tmp = list;

    new->client = client;
    new->next = NULL;
    if (list == NULL)
        return (new);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return (list);
}
