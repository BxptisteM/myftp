/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** cwd_command
*/

#include "commands.h"

void cwd_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "CWD command\n", strlen("CWD command\n"));
}
