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
    if (client->is_logged_in == false) {
        write(client->client_socket.fd, "530\n", 5);
        return;
    }
    write(client->client_socket.fd, "PASS command\n", 14);
}
