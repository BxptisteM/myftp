/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** noop_command
*/

#include "commands.h"

void noop_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "200\nCommand okay.\n", 19);
}
