/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** help_command
*/

#include "commands.h"

void help_cmd(char *input, int client_fd)
{
    (void)input;
    write(client_fd, C214, strlen(C214));
    write(client_fd, "USER: Specify user for authentication\n", 39);
    write(client_fd, "PASS: Specify password for authentication\n\n", 44);
    write(client_fd, "CWD: Change working directory\n", 31);
    write(client_fd,
        "CDUP: Change working directory to parent directory\n\n", 53);
    write(client_fd, "QUIT: Disconnection\n\n", 22);
    write(client_fd, "DELE: Delete file on the server\n\n", 34);
    write(client_fd, "PWD: Print working directory\n\n", 31);
    write(client_fd, "PASV: Enable passive mode\n\n", 28);
    write(client_fd, "PORT: Enable active mode\n\n", 27);
    write(client_fd, "HELP: List available commands\n\n", 32);
    write(client_fd, "NOOP: Do nothing\n\n", 19);
    write(client_fd, "RETR: Download file from server to client\n\n", 44);
    write(client_fd, "STOR: Upload file from client to server\n\n", 42);
    write(client_fd,
        "LIST: List files in the current working directory\n\n", 52);
}
