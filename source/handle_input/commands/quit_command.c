/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** quit_command
*/

#include "commands.h"

void quit_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    write(client->client_socket.fd, "221\r\n", 5);
    client->is_logged_in = false;
    client->quit_server = true;
}
