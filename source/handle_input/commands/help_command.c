/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** help_command
*/

#include "commands.h"

void help_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "HELP command\n", strlen("HELP command\n"));
}
