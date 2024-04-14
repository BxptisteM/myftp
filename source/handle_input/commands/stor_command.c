/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** stor_command
*/

#include "commands.h"
#include "client.h"

static int data_connection_not_build(client_t *client)
{
    if (client->client_data.fd == -1) {
        write(client->client_socket.fd, "425\r\n", 5);
        return 1;
    }
    return 0;
}

void stor_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    char *filename = NULL;
    char *extra = NULL;

    strtok(input, " \n");
    filename = strtok(NULL, " \n");
    extra = strtok(NULL, " \n");
    if (filename == NULL || strlen(filename) == 0 || extra != NULL) {
        write(client->client_socket.fd, "530\r\n", 5);
        return;
    }
    if (client_not_logged_in(client) == true)
        return;
    if (data_connection_not_build(client) == 1)
        return;
    write(client->client_socket.fd, "226\r\n", 5);
}
