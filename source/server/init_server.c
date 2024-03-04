/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** init
*/

#include "server.h"
#include "list.h"

static list_t *init_clients(void)
{
    list_t *clients = malloc(sizeof(list_t));

    clients->client = NULL;
    clients->next = NULL;
    return (clients);
}

static void initialize_socket(int sockfd, struct sockaddr_in *addr,
    socklen_t size)
{
    if (sockfd == -1) {
        perror(strerror(errno));
        exit(84);
    }
    if (bind(sockfd, (struct sockaddr*)addr, size) == -1) {
        perror(strerror(errno));
        exit(84);
    }
    if (listen(sockfd, 100) == -1) {
        perror(strerror(errno));
        exit(84);
    }
}

server_t init_server(int port)
{
    server_t server;

    server.server_socket = malloc(sizeof(socket_t));
    server.clients = init_clients();
    server.port = port;
    server.server_socket->addr.sin_family = AF_INET;
    server.server_socket->addr.sin_addr.s_addr = INADDR_ANY;
    server.server_socket->addr.sin_port = htons(server.port);
    server.server_socket->size = sizeof(server.server_socket->addr);
    server.server_socket->fd = socket(AF_INET, SOCK_STREAM, TCP);
    server.max_fd = server.server_socket->fd;
    initialize_socket(server.server_socket->fd, &server.server_socket->addr,
        server.server_socket->size);
    return (server);
}
