/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** user_command
*/

#include "list.h"
#include "commands.h"

static void check_taken_usernames(server_t *server, client_t *client,
    char *username)
{
    for (list_t *tmp = server->clients; tmp; tmp = tmp->next) {
        if (tmp->client == NULL)
            continue;
        if (tmp->client->username == NULL)
            continue;
        if (strcmp(tmp->client->username, username) == 0) {
            write(client->client_socket.fd, "530\r\n", 5);
            return;
        }
    }
}

void user_cmd(char *input, server_t *server, client_t *client)
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
    if (strcmp(username, "Anonymous\r") == 0) {
        client->username = strdup(username);
        write(client->client_socket.fd, "331\r\n", 6);
        return;
    }
    check_taken_usernames(server, client, username);
    client->username = strdup(username);
}
