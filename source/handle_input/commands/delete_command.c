/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** delete_command
*/

#include "commands.h"
#include "client.h"

void dele_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    if (client_not_logged_in(client) == true)
        return;
    write(client->client_socket.fd, "DELE command\n", 14);
}
