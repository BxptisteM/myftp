/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_is_empty
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

bool list_is_empty(list_t *list)
{
    if (list == NULL)
        return (true);
    return (false);
}
