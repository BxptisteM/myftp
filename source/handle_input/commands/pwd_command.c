/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** pwd_command
*/

#include "commands.h"
#include "client.h"

void pwd_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    char *extra = NULL;

    if (client_not_logged_in(client) == true)
        return;
    strtok(input, " ");
    extra = strtok(NULL, " ");
    if (extra != NULL) {
        write(client->client_socket.fd, "501\r\n", 5);
        return;
    }
    write(client->client_socket.fd, "257\r\n", 5);
    write(client->client_socket.fd, client->current_path,
        strlen(client->current_path));
    write(client->client_socket.fd, "\r\n", 3);
}
