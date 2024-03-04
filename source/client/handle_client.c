/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** handle_client
*/

#include "client.h"

client_t *create_client(struct sockaddr_in client_addr, socklen_t *client_addr_len, int new_socket)
{
    client_t *client = malloc(sizeof(client_t));

    client->client_socket.addr = client_addr;
    client->client_socket.size = *client_addr_len;
    client->client_socket.fd = new_socket;
    client->username = NULL;
    client->password = NULL;
    return (client);
}

static void free_fd_slot(list_t *clients, int fd)
{
    for (list_t *tmp = clients; tmp; tmp = tmp->next) {
        if (tmp->client->client_socket.fd == fd) {
            close(fd);
            free(tmp->client);
            tmp->client = NULL;
            return;
        }
    }
}

static void handle_client_activity(int fd, list_t *clients)
{
    char buffer[1024];
    int valread = read(fd, buffer, 1024);

    if (valread == 0) {
        close(fd);
        free_fd_slot(clients, fd);
    } else {
        buffer[valread] = '\0';
        parse_input(buffer, fd);
    }
}

void process_client_activities(list_t *clients, fd_set *read_fds)
{
    for (list_t *tmp = clients; tmp; tmp = tmp->next) {
        if (tmp->client == NULL)
            continue;
        if (FD_ISSET(tmp->client->client_socket.fd, read_fds)) {
            handle_client_activity(tmp->client->client_socket.fd, clients);
        }
    }
}
