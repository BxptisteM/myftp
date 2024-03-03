/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** pwd_command
*/

#include "commands.h"

void pwd_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "PWD command\n", strlen("PWD command\n"));
}
