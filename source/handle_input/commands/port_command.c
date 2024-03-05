/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** port_command
*/

#include "commands.h"

void port_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "200 PORT command successful.\n", 28);
}
