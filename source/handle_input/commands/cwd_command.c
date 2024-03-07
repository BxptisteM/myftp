/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** cwd_command
*/

#include "commands.h"
#include "client.h"
#include <unistd.h>
#include <limits.h>

static int invalid_dest(char *dest, char *extra, client_t *client)
{
    if (dest == NULL || extra != NULL) {
        write(client->client_socket.fd, "550\r\n", 6);
        return 1;
    }
    return 0;
}

static int check_beyond_root(char *absolute_path, char *dest,
    server_t *server, client_t *client)
{
    if (strncmp(absolute_path, server->path, strlen(server->path)) != 0 ||
        strcmp(dest, "/") == 0) {
        write(client->client_socket.fd, "550\r\n", 6);
        free(absolute_path);
        return 1;
    }
    return 0;
}

static int validate_destination(char *dest)
{
    if (dest == NULL) {
        return -1;
    }
    return 0;
}

static void change_directory(char *absolute_path, client_t *client)
{
    int directory;

    if (validate_destination(absolute_path) != 0) {
        write(client->client_socket.fd, "550\r\n", 6);
        return;
    }
    directory = chdir(absolute_path);
    if (directory != 0) {
        write(client->client_socket.fd, "550\r\n", 6);
        return;
    }
    free(client->current_path);
    client->current_path = strdup(absolute_path);
    write(client->client_socket.fd, "250\r\n", 6);
    return;
}

static char *get_absolute_path(char *dest, client_t *client)
{
    char tentative_path[PATH_MAX];
    char *resolved_path = NULL;

    snprintf(tentative_path, PATH_MAX, "%s/%s", client->current_path, dest);
    resolved_path = realpath(tentative_path, NULL);
    return resolved_path;
}

void cwd_cmd(char *input, server_t *server, client_t *client)
{
    char *dest = NULL;
    char *extra = NULL;
    char *absolute_path = NULL;

    if (client_not_logged_in(client) == 1)
        return;
    strtok(input, " \n");
    dest = strtok(NULL, " \n\r");
    extra = strtok(NULL, " \n");
    if (invalid_dest(dest, extra, client) == 1)
        return;
    absolute_path = get_absolute_path(dest, client);
    if (absolute_path == NULL) {
        write(client->client_socket.fd, "550\r\n", 6);
        return;
    }
    if (check_beyond_root(absolute_path, dest, server, client) == 1)
        return;
    change_directory(absolute_path, client);
    free(absolute_path);
}
