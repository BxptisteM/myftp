/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** user_command
*/

#include "commands.h"

void user_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "USER command\n", strlen("USER command\n"));
}
