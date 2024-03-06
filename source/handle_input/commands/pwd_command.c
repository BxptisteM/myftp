/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** pwd_command
*/

#include "commands.h"

void pwd_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    if (client->is_logged_in == false) {
        write(client->client_socket.fd, "530\n", 5);
        return;
    }
    write(client->client_socket.fd, "257\r\n", 6);
    write(client->client_socket.fd, client->current_path,
        strlen(client->current_path));
    write(client->client_socket.fd, "\r\n", 3);
}
