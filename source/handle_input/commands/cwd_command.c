/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** cwd_command
*/

#include "commands.h"
#include "client.h"

void cwd_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    if (client_not_logged_in(client) == true)
        return;
    write(client->client_socket.fd, "CWD command\n", strlen("CWD command\n"));
}
