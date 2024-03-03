/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** port_command
*/

#include "commands.h"

void port_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "200 PORT command successful.\n", 28);
}
