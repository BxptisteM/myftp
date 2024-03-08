/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** pasv_command
*/

#include "commands.h"
#include "client.h"

void pasv_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    char *extra = NULL;

    strtok(input, " \n");
    extra = strtok(NULL, " \n");
    if (client_not_logged_in(client) == true)
        return;
    if (extra != NULL) {
        write(client->client_socket.fd, "501\r\n", 5);
        return;
    }
}
