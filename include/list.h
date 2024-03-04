/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "server.h"

#ifndef LIST_H_
    #define LIST_H_

typedef struct list_s {
    struct client_s *client;
    struct list_s *next;
} list_t, node_t;

/**
 * @brief add a client to the list
 * @param list
 * @param client
 * @return list_t*
 */
list_t *list_add(list_t *list, client_t *client);

/**
 * @brief create a node
 * @param client
 * @return list_t*
 */
list_t *create_node(client_t *client);

/**
 * @brief add a client to the list at a specific position
 * @param client
 * @param pos
 * @return list_t*
 */
list_t *list_add_position(client_t *client, int pos);

/**
 * @brief add a client to the list at the end
 * @param client
 * @return list_t*
 */
list_t *list_add_end(client_t *client);

/**
 * @brief add a client to the list at the beginning
 * @param client
 * @return list_t*
 */
list_t *list_add_begin(client_t *client);

/**
 * @brief remove a client from the list
 * @param list
 * @param pos
 * @return list_t*
 */
list_t *list_pop(list_t *list, int pos);

/**
 * @brief get the size of the list
 * @param list
 * @return int
 */
list_t *get_elem(list_t *list, int pos);

/**
 * @brief free a list
 * @param list
 */
list_t *list_free(list_t *list);


#endif /* !LIST_H_ */
