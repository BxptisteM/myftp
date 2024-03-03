/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** delete_command
*/

#include "commands.h"

void dele_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "DELE command\n", strlen("DELE command\n"));
}
