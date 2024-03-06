/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** help_command
*/

#include "commands.h"
#include "client.h"

void help_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    if (client_not_logged_in(client) == true)
        return;
    write(client->client_socket.fd, C214, strlen(C214));
}
