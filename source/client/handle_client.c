/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** handle_client
*/

#include "client.h"

client_t *create_client(struct sockaddr_in *client_addr,
    socklen_t *client_addr_len, int new_socket)
{
    client_t *client = malloc(sizeof(client_t));

    client->client_socket.addr = *client_addr;
    client->client_socket.size = *client_addr_len;
    client->client_socket.fd = new_socket;
    client->username = NULL;
    client->password = NULL;
    client->is_logged_in = false;
    client->quit_server = false;
    client->need_password = false;
    return (client);
}

static void handle_client_activity(int fd, server_t *server, client_t *client)
{
    char buffer[1024];
    int valread = read(fd, buffer, 1024);

    if (valread == 0 || valread == -1 || (valread == 2 && buffer[0] == '\r')) {
        return;
    } else {
        buffer[valread] = '\0';
        parse_input(buffer, server, client);
    }
}

void process_client_activities(server_t *server, fd_set *read_fds)
{
    for (list_t *tmp = server->clients; tmp; tmp = tmp->next) {
        if (tmp->client == NULL)
            continue;
        if (FD_ISSET(tmp->client->client_socket.fd, read_fds)) {
            handle_client_activity(tmp->client->client_socket.fd, server,
                tmp->client);
        }
    }
}

void remove_and_close_client_connection(list_t **clients, list_t *current,
    list_t **prev)
{
    close(current->client->client_socket.fd);
    free(current->client);
    if (*prev == NULL)
        *clients = current->next;
    else
        (*prev)->next = current->next;
    free(current);
}

void process_and_remove_disconnected_clients(list_t **clients)
{
    list_t *current = *clients;
    list_t *prev = NULL;
    list_t *next = NULL;

    while (current != NULL) {
        if (current->client != NULL && current->client->quit_server) {
            next = current->next;
            remove_and_close_client_connection(clients, current, &prev);
            current = next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}
