/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** stor_command
*/

#include "commands.h"

void stor_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "STOR command\n", strlen("STOR command\n"));
}
