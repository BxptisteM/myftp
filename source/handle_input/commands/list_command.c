/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** list_command
*/

#include "commands.h"

void list_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "LIST command\n", strlen("LIST command\n"));
}
