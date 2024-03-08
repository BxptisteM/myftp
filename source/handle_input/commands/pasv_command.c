/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** pasv_command
*/

#include "commands.h"
#include "client.h"

static void run_passive_mode(client_t *client, int data_socket)
{
    struct sockaddr_in data_addr;
    socklen_t len = sizeof(data_addr);

    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    data_addr.sin_port = 0;
    if (bind(data_socket, (struct sockaddr *)&data_addr,
        sizeof(data_addr)) == -1) {
        close(data_socket);
        return;
    }
    if (getsockname(data_socket, (struct sockaddr *)&data_addr, &len) == -1) {
        close(data_socket);
        return;
    }
    client->client_data.fd = data_socket;
    client->client_data.addr = data_addr;
    client->client_data.size = len;
    client->is_passive = true;
}

void pasv_cmd(char *input UNUSED, server_t *server UNUSED, client_t *client)
{
    char *extra = NULL;
    int data_socket = 0;

    strtok(input, " \n");
    extra = strtok(NULL, " \n");
    if (client_not_logged_in(client) == true)
        return;
    if (extra != NULL) {
        write(client->client_socket.fd, "501\r\n", 5);
        return;
    }
    data_socket = socket(AF_INET, SOCK_STREAM, TCP);
    if (data_socket == -1)
        return;
    run_passive_mode(client, data_socket);
    write(client->client_socket.fd, "227\r\n", 5);
}
