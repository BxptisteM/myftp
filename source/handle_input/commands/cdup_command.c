/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** cdup_command
*/

#include "commands.h"
#include "client.h"

void cdup_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    char *extra = NULL;
    int directory = 0;

    if (client_not_logged_in(client) == true)
        return;
    strtok(input, " \n");
    extra = strtok(NULL, " \n");
    if (extra != NULL) {
        write(client->client_socket.fd, "501\r\n", 6);
        return;
    }
    directory = chdir(server->path);
    if (directory != 0) {
        write(client->client_socket.fd, "550\r\n", 6);
        return;
    }
    free(client->current_path);
    client->current_path = strdup(server->path);
    write(client->client_socket.fd, "250\r\n", 6);
    return;
}
