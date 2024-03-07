/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** parse_input
*/

#include "commands.h"
#include <stdlib.h>

static void invalid_command(int i, int array_size, client_t *client)
{
    if (i == array_size)
        write(client->client_socket.fd, "500\r\n", 6);
}

static char *get_command(char *input)
{
    char *command = NULL;
    char *tmp = strdup(input);

    command = strtok(tmp, " ");
    if (command == NULL) {
        free(tmp);
        return (strdup("NOCOMMAND\r\n"));
    }
    return command;
}

void parse_input(char *input, server_t *server, client_t *client)
{
    char *command = NULL;
    int i = 0;
    int array_size = 0;
    commands_t commands_array[] = {{"USER", &user_cmd}, {"PASS", &pass_cmd},
        {"CWD", &cwd_cmd}, {"CDUP", &cdup_cmd}, {"QUIT", &quit_cmd},
        {"DELE", &dele_cmd}, {"PWD", &pwd_cmd}, {"PASV", &pasv_cmd},
        {"PORT", &port_cmd}, {"HELP", &help_cmd}, {"NOOP", &noop_cmd},
        {"RETR", &retr_cmd}, {"STOR", &stor_cmd}, {"LIST", &list_cmd}};

    if (input == NULL || input[0] == '\0')
        return;
    array_size = sizeof(commands_array) / sizeof(commands_array[0]);
    command = get_command(input);
    for (i = 0; i < array_size; ++i) {
        if (strcmp(command, commands_array[i].command) == 0) {
            commands_array[i].func(input, server, client);
            break;
        }
    }
    invalid_command(i, array_size, client);
}
