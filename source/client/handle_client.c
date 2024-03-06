/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** handle_client
*/

#include "client.h"

client_t *create_client(struct sockaddr_in *client_addr,
    socklen_t *client_addr_len, int new_socket, server_t *server)
{
    client_t *client = malloc(sizeof(client_t));

    client->valread = 0;
    client->client_socket.addr = *client_addr;
    client->client_socket.size = *client_addr_len;
    client->client_socket.fd = new_socket;
    client->read_buffer = malloc(1024);
    client->username = NULL;
    client->password = NULL;
    client->is_logged_in = false;
    client->quit_server = false;
    client->need_password = false;
    client->current_path = strdup(server->path);
    return (client);
}

static void check_read_completed(server_t *server, client_t *client)
{
    if (client->read_buffer[strlen(client->read_buffer) - 1] == '\n' &&
        client->read_buffer[strlen(client->read_buffer) - 2] == '\r') {
        client->read_buffer[strlen(client->read_buffer) - 2] = '\0';
        parse_input(client->read_buffer, server, client);
        memset(client->read_buffer, 0, 1024);
        client->valread = 0;
    }
}

static void handle_client_activity(int fd, server_t *server, client_t *client)
{
    char buffer[1024] = {0};

    client->valread = read(fd, buffer, 1024);
    if (client->valread == 0 || client->valread == -1) {
        return;
    } else {
        buffer[client->valread] = '\0';
        client->read_buffer = strcat(client->read_buffer, buffer);
        check_read_completed(server, client);
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
