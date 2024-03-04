/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** check_args
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

void check_args(int ac, char **av)
{
    (void)av;
    if (ac > 3) {
        fprintf(stderr, "Error: too many arguments.\n");
        exit(84);
    }
    if (ac < 3) {
        display_help(ac, av);
        fprintf(stderr, "Error: not enough arguments.\n");
        exit(84);
    }
    if (atoi(av[1]) == 0 || atoi(av[1]) < 0) {
        fprintf(stderr, "Error: invalid port number.\n");
        exit(84);
    }
}
