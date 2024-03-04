/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list
*/

#include <stdbool.h>

#ifndef LIST_H_
    #define LIST_H_

typedef struct list_s {
    int fd;
    char *password;
    char *username;
    struct list_s *next;
} list_t, node_t;

/**
 * @brief Add a node at the begin of the list
 * @param list
 * @param data
 * @return list_t*
 */
list_t *list_add_begin(list_t *list, int fd);

/**
 * @brief Add a node at the end of the list
 * @param list
 * @param data
 * @return list_t*
 */
list_t *list_add_end(list_t *list, int fd);

/**
 * @brief Add a node at a specific position
 * @param list
 * @param data
 * @param pos
 * @return list_t*
 */
list_t *list_add(list_t *list, int fd, int pos);

/**
 * @brief Free the list
 * @param list
 * @return list_t*
 */
list_t *list_free(list_t *list);

/**
 * @brief Check if a list is empty
 * @param list
 * @return true
 * @return false
 */
bool list_is_empty(list_t *list);

/**
 * @brief Get the size of the list
 * @param list
 * @return int
 */
int list_get_len(list_t *list);

/**
 * @brief Print the content of a list
 * @param list
 */
void print_list(list_t *list);

/**
 * @brief print a specific node of a list
 * @param list
 * @param position
 */
void print_node(list_t *list, int position);

#endif /* !LIST_H_ */
