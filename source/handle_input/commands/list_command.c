/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_command
*/

#include "commands.h"

void list_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "LIST command\n", 14);
}
