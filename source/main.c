/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** main
*/

#include "server.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    server_t server;

    check_args(ac, av);
    server = init_server(atoi(av[1]));
    run_ftp(&server);
    return (0);
}
