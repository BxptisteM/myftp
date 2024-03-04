/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** main
*/

#include "myftp.h"
#include <stdlib.h>

// list_t *list = NULL;
int main(int ac, char **av)
{
    check_args(ac, av);
    handle_connection(initialize_listening_socket(atoi(av[1])));
    return (0);
}
