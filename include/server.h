/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** myftp
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <error.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdbool.h>

#ifndef MYFTP_H_
    #define MYFTP_H_

    #define C220 "220\nConnection Establishment...\n"

    /**
     * @brief Macro for the tcp protocol
     */
    #define TCP 6
    /**
     * @brief Macro for the max client number
     */
    #define MAX_CLIENTS 100

typedef struct list_s list_t;

typedef struct socket_s {
    int fd;
    struct sockaddr_in addr;
    socklen_t size;
} socket_t;

typedef struct client_s {
    socket_t client_socket;
    char *username;
    char *password;
    bool is_logged_in;
} client_t;


typedef struct server_s {
    int port;
    int max_fd;
    char *path;
    fd_set readfds;
    list_t *clients;
    socket_t *server_socket;
} server_t;

/**
 * @brief check if the args are valid
 * @param ac
 * @param av
 * @return void (exit(84))
 */
void check_args(int ac, char **av);

/**
 * @brief display the -help flag
 * @param ac
 * @param av
 * @return void (exit(0))
 */
void display_help(int ac, char **av);

/**
 * @brief initialize the server structure
 * @return server_t
 */
server_t init_server(int port, char *path);

/**
 * @brief run the ftp server
 * @param server_t server structure
 * @return int (exit(84))
 */
void run_ftp(server_t *server);

/**
 * @brief parse the input from the client
 * @param input
 * @param client_fd
 */
void parse_input(char *input, server_t *server, client_t *client);


#endif /* !MYFTP_H_ */
