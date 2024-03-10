/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_command
*/

#include "commands.h"
#include "client.h"
#include <sys/wait.h>

static int data_connection_not_build(client_t *client)
{
    if (client->client_data.fd == -1) {
        write(client->client_socket.fd, "425\r\n", 5);
        return 1;
    }
    return 0;
}

static void display_current_files(client_t *client)
{
    if (chdir(client->current_path) == -1)
        return;
    dup2(client->client_socket.fd, STDOUT_FILENO);
    execlp("ls", "ls", "-l", NULL);
}

void list_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    int status = 0;
    pid_t pid = 0;

    if (client_not_logged_in(client) == true)
        return;
    if (data_connection_not_build(client) == 1)
        return;
    pid = fork();
    if (pid == -1)
        return;
    else if (pid == 0) {
        display_current_files(client);
    } else {
        waitpid(pid, &status, 0);
        write(client->client_socket.fd, "226\r\n", 5);
    }
}
