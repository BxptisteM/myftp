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

void initialize_socket(int sockfd, struct sockaddr_in socket_addr, socklen_t sock_size)
{
    if (sockfd == -1) {
        perror(strerror(errno));
        exit(84);
    }
    if (bind(sockfd, (struct sockaddr*)&socket_addr, sock_size) == -1) {
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

    initialize_socket(sockfd, socket_addr, sock_size);

    return sockfd;
}

int handle_connection(int sockfd)
{
    int new_socket = 0;
    struct sockaddr_in peer_addr;
    socklen_t peer_size = sizeof(peer_addr);

    new_socket = accept(sockfd, (struct sockaddr*)&peer_addr, &peer_size);
    if (new_socket == -1) {
        perror(strerror(errno));
        exit(84);
    }
    printf("Connection from %s:%d\n",
            inet_ntoa(peer_addr.sin_addr),
            ntohs(peer_addr.sin_port));

    close(sockfd);
    close(new_socket);

    return 0;
}
