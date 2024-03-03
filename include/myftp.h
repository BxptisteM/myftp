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

#ifndef MYFTP_H_
    #define MYFTP_H_

    #define C220 "Connection Establishment...\n<- 220\n"

    /**
     * @brief Macro for the tcp protocol
     */
    #define TCP 6
    /**
     * @brief Macro for the max client number
     */
    #define MAX_CLIENTS 100

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
 * @brief handle the connection from the client
 * @param sockfd the socket file descriptor
 * @return int (exit(84))
 */
int handle_connection(int sockfd);

/**
 * @brief initialize the listening socket
 * @param socket_port the port number
 * @return int the socket file descriptor
 */
int initialize_listening_socket(int socket_port);

#endif /* !MYFTP_H_ */
