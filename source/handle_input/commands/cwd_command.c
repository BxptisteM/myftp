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
    if (client->is_logged_in == false) {
        write(client->client_socket.fd, "530\n", 5);
        return;
    }
    write(client->client_socket.fd, "CWD command\n", strlen("CWD command\n"));
}
