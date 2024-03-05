/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** client
*/

#include "server.h"
#include "list.h"

#ifndef CLIENT_H_
    #define CLIENT_H_

/**
 * @brief Create a client object
 * @param client_addr
 * @param client_addr_len
 * @param new_socket
 * @return client_t*
 */
client_t *create_client(struct sockaddr_in *client_addr, socklen_t
    *client_addr_len, int new_socket);

/**
 * @brief redirect client acitivites to the corresponding functions
 * @param clients
 * @param read_fds
 */
void process_client_activities(server_t *server, fd_set *read_fds);

#endif /* !CLIENT_H_ */
