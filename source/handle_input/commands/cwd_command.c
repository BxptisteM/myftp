/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** cwd_command
*/

#include "commands.h"

void cwd_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "CWD command\n", strlen("CWD command\n"));
}
