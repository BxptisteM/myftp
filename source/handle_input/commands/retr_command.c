/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** retr_command
*/

#include "commands.h"

void retr_cmd(char *input, server_t *server, client_t *client)
{
    (void)input;
    (void)server;
    write(client->client_socket.fd, "RETR command\n", strlen("RETR command\n"));
}
