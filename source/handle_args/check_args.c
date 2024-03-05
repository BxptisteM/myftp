/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** check_args
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "server.h"

static int check_path(char *path)
{
    if (opendir(path) == NULL)
        return 84;
    return 0;
}

void check_args(int ac, char **av)
{
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
    if (check_path(av[2]) == 84) {
        fprintf(stderr, "Error: invalid path.\n");
        exit(84);
    }
}
