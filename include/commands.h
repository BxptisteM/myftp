/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** commands
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

#ifndef COMMANDS_H_
    #define COMMANDS_H_

    #define C214 "214\nCommands:\n"

/**
 * @brief Structure for the commands
*/
typedef struct commands_s {
    char *command;
    void (*func)(char *input, server_t *server, client_t *client);
} commands_t;

/**
 * @brief handle the USER command
 * @param input
 * @param client_fd
 */
void user_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the PASS commnad
 * @param input
 * @param client_fd
 */
void pass_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the CWD command
 * @param input
 * @param client_fd
 */
void cwd_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the CDUP command
 * @param input
 * @param client_fd
 */
void cdup_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the QUIT command
 * @param input
 * @param client_fd
 */
void quit_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the DELE command
 * @param input
 * @param client_fd
 */
void dele_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the PWD command
 * @param input
 * @param client_fd
 */
void pwd_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the PASV command
 * @param input
 * @param client_fd
 */
void pasv_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the PORT command
 * @param input
 * @param client_fd
 */
void port_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the HELP command
 * @param input
 * @param client_fd
 */
void help_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the NOOP command
 * @param input
 * @param client_fd
 */
void noop_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the RETR command
 * @param input
 * @param client_fd
 */
void retr_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the STOR command
 * @param input
 * @param client_fd
 */
void stor_cmd(char *input, server_t *server, client_t *client);

/**
 * @brief handle the LIST command
 * @param input
 * @param client_fd
 */
void list_cmd(char *input, server_t *server, client_t *client);

#endif /* !COMMANDS_H_ */
