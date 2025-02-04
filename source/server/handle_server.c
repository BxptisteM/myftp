/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** create_socket
*/

#include "server.h"
#include "client.h"
#include "list.h"

static void update_max_fd(int current, int *max_fd)
{
    if (current > *max_fd)
        *max_fd = current;
}

static void setup_file_descriptors(int sockfd, fd_set *read_fds, int *max_fd,
    list_t *clients)
{
    FD_ZERO(read_fds);
    FD_SET(sockfd, read_fds);
    *max_fd = sockfd;
    for (list_t *tmp = clients; tmp; tmp = tmp->next) {
        if (tmp->client == NULL)
            continue;
        if (tmp->client->client_socket.fd > 0) {
            FD_SET(tmp->client->client_socket.fd, read_fds);
            update_max_fd(tmp->client->client_socket.fd, max_fd);
        }
    }
}

static void handle_new_connection(int sockfd, list_t *clients,
    server_t *server)
{
    client_t *client;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int new_socket = accept(sockfd, (struct sockaddr *)&client_addr,
        &client_addr_len);

    if (new_socket < 0) {
        perror(strerror(errno));
        return;
    }
    write(new_socket, C220, strlen(C220));
    client = create_client(&client_addr, &client_addr_len,
        new_socket, server);
    clients = list_add(clients, client);
}

void run_ftp(server_t *server)
{
    int activity = 0;

    while (1) {
        process_and_remove_disconnected_clients(&server->clients);
        setup_file_descriptors(server->server_socket->fd, &server->readfds,
            &server->max_fd, server->clients);
        activity = select(server->max_fd + 1, &server->readfds,
            NULL, NULL, NULL);
        if ((activity < 0) && (errno != EINTR)) {
            perror(strerror(errno));
            continue;
        }
        if (FD_ISSET(server->server_socket->fd, &server->readfds)) {
            handle_new_connection(server->server_socket->fd, server->clients,
                server);
        }
        process_client_activities(server, &server->readfds);
    }
    close(server->server_socket->fd);
}
