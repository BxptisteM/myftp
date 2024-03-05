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
    write(client_fd, "Command okay.\n<- 200\n", 22);
}
