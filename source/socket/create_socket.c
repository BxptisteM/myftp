/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** create_socket
*/

#include "myftp.h"
#include <error.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void initialize_socket(int sockfd, struct sockaddr_in *addr, socklen_t size)
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

void accept_connections(int new_socket, int child_pid,
    struct sockaddr_in *peer_addr)
{
    if (child_pid == 0) {
        if (new_socket == -1) {
            perror(strerror(errno));
            exit(84);
        }
        printf("Connection from %s:%d\n",
            inet_ntoa(peer_addr->sin_addr),
            ntohs(peer_addr->sin_port));
    } else {
        waitpid(child_pid, NULL, 0);
        close(new_socket);
    }
}

int handle_connection(int sockfd)
{
    int new_socket = 0;
    int child_pid = 0;
    struct sockaddr_in peer_addr;
    socklen_t peer_size = sizeof(peer_addr);

    while (1) {
        new_socket = accept(sockfd, (struct sockaddr*)&peer_addr, &peer_size);
        child_pid = fork();
        accept_connections(new_socket, child_pid, &peer_addr);
    }
    close(sockfd);
    return 0;
}
