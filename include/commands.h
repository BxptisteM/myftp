/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** commands
*/

#include <stdio.h>

#ifndef COMMANDS_H_
    #define COMMANDS_H_

/**
 * @brief Structure for the commands
*/
typedef struct commands_s {
    char *command;
    void (*func)(char *input);
} commands_t;

void parse_input(char *input);
void user_cmd(char *input);
void pass_cmd(char *input);
void cwd_cmd(char *input);
void cdup_cmd(char *input);
void quit_cmd(char *input);
void dele_cmd(char *input);
void pwd_cmd(char *input);
void pasv_cmd(char *input);
void port_cmd(char *input);
void help_cmd(char *input);
void noop_cmd(char *input);
void retr_cmd(char *input);
void stor_cmd(char *input);
void list_cmd(char *input);

#endif /* !COMMANDS_H_ */
