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

list_t *create_node(client_t *client)
{
    list_t *new = malloc(sizeof(list_t));

    new->client = client;
    new->next = NULL;
    return (new);
}

list_t *list_add_position(list_t *list, client_t *client, int pos)
{
    list_t *new = create_node(client);
    list_t *tmp = list;
    list_t *prev = NULL;
    int i = 0;

    if (pos == 0) {
        new->next = list;
        return (new);
    }
    while (tmp && i < pos) {
        prev = tmp;
        tmp = tmp->next;
        i++;
    }
    if (i != pos)
        return (list);
    prev->next = new;
    new->next = tmp;
    return (list);
}

list_t *list_add_end(list_t *list, client_t *client)
{
    list_t *new = create_node(client);
    list_t *tmp = list;

    if (list == NULL)
        return (new);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return (list);
}

list_t *list_add_begin(list_t *list, client_t *client)
{
    list_t *new = create_node(client);

    new->next = list;
    return (new);
}
