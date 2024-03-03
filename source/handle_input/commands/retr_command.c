/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** retr_command
*/

#include "commands.h"

void retr_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "RETR command\n", strlen("RETR command\n"));
}
