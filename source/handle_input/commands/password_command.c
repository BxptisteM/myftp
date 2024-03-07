/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** password_command
*/

#include "commands.h"

static bool anonymous_logging(client_t *client, char *password)
{
    if ((strcmp(client->username, "Anonymous") == 0 &&
        password == NULL)) {
        write(client->client_socket.fd, "230\r\n", 5);
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
        write(client->client_socket.fd, "332\r\n", 5);
        return;
    }
    strtok(input, " \n");
    password = strtok(NULL, " \n");
    extra = strtok(NULL, " \n");
    if (anonymous_logging(client, password) == true)
        return;
    if (password == NULL || extra != NULL) {
        printf("Empty password\n");
        write(client->client_socket.fd, "530\r\n", 5);
        return;
    }
    client->password = strdup(password);
    client->is_logged_in = true;
    write(client->client_socket.fd, "230\r\n", 6);
}
