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

    #define C214 "Commands:\n214\n"

/**
 * @brief Structure for the commands
*/
typedef struct commands_s {
    char *command;
    void (*func)(char *input, int client_fd);
} commands_t;

/**
 * @brief parse the input from the client
 * @param input
 * @param client_fd
 */
void parse_input(char *input, int client_fd);

/**
 * @brief handle the USER command
 * @param input
 * @param client_fd
 */
void user_cmd(char *input, int client_fd);

/**
 * @brief handle the PASS commnad
 * @param input
 * @param client_fd
 */
void pass_cmd(char *input, int client_fd);

/**
 * @brief handle the CWD command
 * @param input
 * @param client_fd
 */
void cwd_cmd(char *input, int client_fd);

/**
 * @brief handle the CDUP command
 * @param input
 * @param client_fd
 */
void cdup_cmd(char *input, int client_fd);

/**
 * @brief handle the QUIT command
 * @param input
 * @param client_fd
 */
void quit_cmd(char *input, int client_fd);

/**
 * @brief handle the DELE command
 * @param input
 * @param client_fd
 */
void dele_cmd(char *input, int client_fd);

/**
 * @brief handle the PWD command
 * @param input
 * @param client_fd
 */
void pwd_cmd(char *input, int client_fd);

/**
 * @brief handle the PASV command
 * @param input
 * @param client_fd
 */
void pasv_cmd(char *input, int client_fd);

/**
 * @brief handle the PORT command
 * @param input
 * @param client_fd
 */
void port_cmd(char *input, int client_fd);

/**
 * @brief handle the HELP command
 * @param input
 * @param client_fd
 */
void help_cmd(char *input, int client_fd);

/**
 * @brief handle the NOOP command
 * @param input
 * @param client_fd
 */
void noop_cmd(char *input, int client_fd);

/**
 * @brief handle the RETR command
 * @param input
 * @param client_fd
 */
void retr_cmd(char *input, int client_fd);

/**
 * @brief handle the STOR command
 * @param input
 * @param client_fd
 */
void stor_cmd(char *input, int client_fd);

/**
 * @brief handle the LIST command
 * @param input
 * @param client_fd
 */
void list_cmd(char *input, int client_fd);

#endif /* !COMMANDS_H_ */
