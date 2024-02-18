/*
** EPITECH PROJECT, 2024
** myftp [WSL: Ubuntu]
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_

/**
 * @brief check if the args are valid
 * @param ac
 * @param av
 * @return void (exit(84))
 */
void check_args(int ac, char **av);

/**
 * @brief display the -help flag
 * @param ac
 * @param av
 * @return void (exit(0))
 */
void display_help(int ac, char **av);

#endif /* !MYFTP_H_ */
