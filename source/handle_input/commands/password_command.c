/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** password_command
*/

#include "commands.h"

void pass_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "PASS command\n", 14);
}
