/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** help_flag
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void display_help(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        printf("USAGE: ./myftp port path\n");
        printf("\t");
        printf("port is the port number on which the server socket listens\n");
        printf("\tpath is the path to the home directory for the user\n");
        exit(0);
    }
}
