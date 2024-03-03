/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** commands
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef COMMANDS_H_
    #define COMMANDS_H_

/**
 * @brief Structure for the commands
*/
typedef struct commands_s {
    char *command;
    void (*func)(char *input, int client_fd);
} commands_t;

void parse_input(char *input, int client_fd);
void user_cmd(char *input, int client_fd);
void pass_cmd(char *input, int client_fd);
void cwd_cmd(char *input, int client_fd);
void cdup_cmd(char *input, int client_fd);
void quit_cmd(char *input, int client_fd);
void dele_cmd(char *input, int client_fd);
void pwd_cmd(char *input, int client_fd);
void pasv_cmd(char *input, int client_fd);
void port_cmd(char *input, int client_fd);
void help_cmd(char *input, int client_fd);
void noop_cmd(char *input, int client_fd);
void retr_cmd(char *input, int client_fd);
void stor_cmd(char *input, int client_fd);
void list_cmd(char *input, int client_fd);

#endif /* !COMMANDS_H_ */
