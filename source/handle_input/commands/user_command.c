/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** user_command
*/

#include "commands.h"

void user_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "USER command\n", strlen("USER command\n"));
}
