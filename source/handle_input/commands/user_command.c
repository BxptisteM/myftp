/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** user_command
*/

#include "list.h"
#include "commands.h"

static int check_username(client_t *client, char *username)
{
    if (strcmp(username, "Anonymous") != 0) {
        write(client->client_socket.fd, "331\r\n", 5);
        return 1;
    }
    return 0;
}

static int check_anonymous_login(client_t *client, char *username)
{
    if (strcmp(username, "Anonymous") == 0) {
        client->username = strdup(username);
        client->need_password = true;
        write(client->client_socket.fd, "331\r\n", 5);
        return 1;
    }
    return 0;
}

void user_cmd(char *input, server_t *server UNUSED, client_t *client)
{
    char *username = NULL;
    char *extra = NULL;

    strtok(input, " \n");
    username = strtok(NULL, " \n");
    extra = strtok(NULL, " \n");
    if (username == NULL || strlen(username) == 0 || extra != NULL) {
        write(client->client_socket.fd, "530\r\n", 5);
        return;
    }
    if (check_anonymous_login(client, username) == 1)
        return;
    if (check_username(client, username) == 1)
        return;
    write(client->client_socket.fd, "331\r\n", 5);
    client->username = strdup(username);
    client->need_password = true;
}
