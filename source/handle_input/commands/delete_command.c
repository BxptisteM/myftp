/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** delete_command
*/

#include "commands.h"
#include "client.h"
#include <sys/stat.h>

static bool file_is_reachable(char *filename, char *ftp_home)
{
    char *tmp_filename = malloc(sizeof(char) * (strlen(filename) + 1));
    char *tmp_ftp_home = malloc(sizeof(char) * (strlen(ftp_home) + 1));

    if (tmp_filename == NULL || tmp_ftp_home == NULL)
        return false;
    if (realpath(filename, tmp_filename) == NULL)
        return false;
    if (realpath(ftp_home, tmp_ftp_home) == NULL)
        return false;
    return true;
}

static bool check_perms(char *filename)
{
    if (access(filename, F_OK) == -1)
        return false;
    if (access(filename, R_OK) == -1)
        return false;
    return true;
}

static bool check_valid_file(char *filename, char *ftp_home, client_t *client)
{
    struct stat statbuffer;

    if (file_is_reachable(filename, ftp_home) == false) {
        write(client->client_socket.fd, "550\r\n", 5);
        return false;
    }
    if (check_perms(filename) == false) {
        write(client->client_socket.fd, "550\r\n", 5);
        return false;
    }
    if (stat(filename, &statbuffer) != 0) {
        write(client->client_socket.fd, "550\r\n", 5);
        return false;
    }
    if (S_ISDIR(statbuffer.st_mode)) {
        write(client->client_socket.fd, "550\r\n", 5);
        return false;
    }
    return true;
}

void dele_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    char *filename = NULL;
    char *extra = NULL;

    strtok(input, " \n");
    filename = strtok(NULL, " \n");
    extra = strtok(NULL, " \n");
    if (client_not_logged_in(client) == true)
        return;
    if (filename == NULL || strlen(filename) == 0 || extra != NULL) {
        write(client->client_socket.fd, "501\r\n", 5);
        return;
    }
    if (check_valid_file(filename, server->path, client) == false)
        return;
    if (remove(filename) == -1) {
        write(client->client_socket.fd, "550\r\n", 5);
        return;
    }
    write(client->client_socket.fd, "250\r\n", 5);
}
