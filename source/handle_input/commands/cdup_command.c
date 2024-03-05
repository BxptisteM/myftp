/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** cdup_command
*/

#include "commands.h"

void cdup_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "CDUP command\n", 14);
}
