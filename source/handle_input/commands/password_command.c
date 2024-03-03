/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** password_command
*/

#include "commands.h"

void pass_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "PASS command\n", strlen("PASS command\n"));
}
