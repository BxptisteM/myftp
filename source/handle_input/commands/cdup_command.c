/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** cdup_command
*/

#include "commands.h"

void cdup_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "CDUP command\n", strlen("CDUP command\n"));
}
