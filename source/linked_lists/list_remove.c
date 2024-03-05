/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_remove
*/

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

list_t list_pop(list_t *list)
{
    list_t *tmp = list;
    list_t *prev = NULL;

    if (list == NULL)
        return (list_t){NULL, NULL};
    while (tmp->next) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (prev == NULL) {
        free(tmp);
        return (list_t){NULL, NULL};
    }
    prev->next = NULL;
    free(tmp);
    return *list;
}

list_t *list_remove(list_t *list, list_t *node)
{
    list_t *tmp = list;
    list_t *prev = NULL;

    if (list == NULL)
        return NULL;
    if (list == node) {
        list = list->next;
        free(tmp);
        return list;
    }
    while (tmp) {
        if (tmp == node) {
            prev->next = tmp->next;
            free(tmp);
            return list;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return list;
}