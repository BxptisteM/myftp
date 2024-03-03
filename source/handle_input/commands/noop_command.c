/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** noop_command
*/

#include "commands.h"

void noop_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "NOOP command\n", strlen("NOOP command\n"));
}
