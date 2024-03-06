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
client_t *create_client(struct sockaddr_in *client_addr,
    socklen_t *client_addr_len, int new_socket, server_t *server);

/**
 * @brief redirect client acitivites to the corresponding functions
 * @param clients
 * @param read_fds
 */
void process_client_activities(server_t *server, fd_set *read_fds);

/**
 * @brief remove and close client connection
 * @param clients
 * @param current
 * @param prev
 */
void remove_and_close_client_connection(list_t **clients, list_t *current,
    list_t **prev);

/**
 * @brief remove and close client connection
 * @param clients
 */
void process_and_remove_disconnected_clients(list_t **clients);

/**
 * @brief check if the client is logged in or not
 * @param client
 * @return true
 * @return false
 */
bool client_not_logged_in(client_t *client);

#endif /* !CLIENT_H_ */
