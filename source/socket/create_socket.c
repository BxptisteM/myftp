/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** create_socket
*/

#include "myftp.h"
#include "commands.h"
#include <error.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/select.h>

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

static void update_max_fd(int current, int *max_fd)
{
    if (current > *max_fd)
        *max_fd = current;
}

static void setup_file_descriptors(int sockfd, fd_set *read_fds, int *max_fd,
    int clients_fds[])
{
    FD_ZERO(read_fds);
    FD_SET(sockfd, read_fds);
    *max_fd = sockfd;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients_fds[i] > 0) {
            FD_SET(clients_fds[i], read_fds);
            update_max_fd(clients_fds[i], max_fd);
        }
    }
}

static void handle_new_connection(int sockfd, int clients_fds[])
{
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int new_socket = accept(sockfd, (struct sockaddr *)&client_addr,
        &client_addr_len);

    if (new_socket < 0) {
        perror(strerror(errno));
        return;
    }
    printf("New connection: ip is: %s, port: %d\n",
        inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    write(new_socket, "220\n", 4);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients_fds[i] == 0) {
            clients_fds[i] = new_socket;
            break;
        }
    }
}

static void handle_client_activity(int fd)
{
    char buffer[1025];
    int valread = read(fd, buffer, 1024);

    if (valread == 0) {
        printf("Host disconnected, fd %d\n", fd);
        close(fd);
    } else {
        buffer[valread] = '\0';
        parse_input(buffer);
    }
}

static void process_client_activities(int *clients_fds, fd_set *read_fds)
{
    int fd = 0;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        fd = clients_fds[i];
        if (FD_ISSET(fd, read_fds)) {
            handle_client_activity(fd);
        }
    }
}

int initialize_listening_socket(int socket_port)
{
    int sockfd = 0;
    struct sockaddr_in socket_addr;
    socklen_t sock_size = sizeof(socket_addr);

    socket_addr.sin_family = AF_INET;
    socket_addr.sin_addr.s_addr = INADDR_ANY;
    socket_addr.sin_port = htons(socket_port);
    sockfd = socket(AF_INET, SOCK_STREAM, TCP);
    initialize_socket(sockfd, &socket_addr, sock_size);
    return sockfd;
}

int handle_connection(int sockfd)
{
    int clients_fds[MAX_CLIENTS] = {0};
    int max_fd = 0;
    int activity = 0;
    fd_set read_fds;

    while (1) {
        setup_file_descriptors(sockfd, &read_fds, &max_fd, clients_fds);
        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if ((activity < 0) && (errno != EINTR)) {
            perror(strerror(errno));
            continue;
        }
        if (FD_ISSET(sockfd, &read_fds)) {
            handle_new_connection(sockfd, clients_fds);
        }
        process_client_activities(clients_fds, &read_fds);
    }
    close(sockfd);
    return 0;
}
