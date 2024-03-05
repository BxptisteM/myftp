/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** password_command
*/

#include "commands.h"

static bool anonymous_logging(client_t *client, char *input)
{
    if ((strcmp(client->username, "Anonymous\r") == 0 &&
        strcmp(input, "PASS\r\n") == 0)) {
        write(client->client_socket.fd, "230\n", 5);
        client->is_logged_in = true;
        return true;
    }
    return false;
}

void pass_cmd(char *input, server_t *server UNUSED, client_t *client)
{
    char *password = NULL;
    char *extra = NULL;

    if (client->need_password == false) {
        write(client->client_socket.fd, "530\n", 5);
        return;
    }
    if (anonymous_logging(client, input) == true)
        return;
    strtok(input, " \n");
    password = strtok(NULL, " \n");
    extra = strtok(NULL, " \n");
    if (password == NULL || extra != NULL) {
        write(client->client_socket.fd, "530\n", 5);
        return;
    }
    client->password = strdup(password);
    client->is_logged_in = true;
    write(client->client_socket.fd, "230\r\n", 6);
}
