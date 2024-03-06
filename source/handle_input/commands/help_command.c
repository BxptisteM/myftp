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
    if (client->is_logged_in == false) {
        write(client->client_socket.fd, "530\r\n", 5);
        return;
    }
    write(client->client_socket.fd, C214, strlen(C214));
}
