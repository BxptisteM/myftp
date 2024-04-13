/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** retr_command
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

void retr_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    if (client_not_logged_in(client) == true)
        return;
    if (data_connection_not_build(client) == 1)
        return;
    write(client->client_socket.fd, "550\r\n", 5);
}
