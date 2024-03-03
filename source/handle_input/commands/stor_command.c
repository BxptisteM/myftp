/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** stor_command
*/

#include "commands.h"

void stor_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "STOR command\n", strlen("STOR command\n"));
}
