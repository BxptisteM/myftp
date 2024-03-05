/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** delete_command
*/

#include "commands.h"

void dele_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "DELE command\n", strlen("DELE command\n"));
}
