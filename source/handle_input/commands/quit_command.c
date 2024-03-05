/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** quit_command
*/

#include "commands.h"

void quit_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    write(client->client_socket.fd, "221\nDisconnected from host\n", 28);
    close(client->client_socket.fd);
    close(server->server_socket->fd);
}
