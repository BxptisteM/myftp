/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** help_command
*/

#include "commands.h"

void help_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, C214, strlen(C214));
    write(client->client_socket.fd, "Ask chat gpt\n", 14);
}
