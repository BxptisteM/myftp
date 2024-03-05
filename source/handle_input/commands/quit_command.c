/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** quit_command
*/

#include "commands.h"

void quit_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "Disconnected from host\n221\n", 31);
    close(client_fd);
}
