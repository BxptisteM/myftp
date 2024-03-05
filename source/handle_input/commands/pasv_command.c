/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** pasv_command
*/

#include "commands.h"

void pasv_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "PASV command\n", 14);
}
