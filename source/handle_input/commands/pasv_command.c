/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** pasv_command
*/

#include "commands.h"

void pasv_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, "PASV command\n", strlen("PASV command\n"));
}
