/*
** EPITECH PROJECT, 2024
** process info main
** File description:
** process info main my navy
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../include/my.h"
#include "../include/navy.h"

int help_txt(void)
{
    char *help_t = "USAGE\n\t./navy [first_player_id] navy_positions\n"
    "DESCRIPTION\n\tfirst_player_pid: only for the 2nd player. pid of the fir"
    "st player.\n\t"
    "navy_positions: file representing the positions of the ships.\n";

    my_putstr(help_t);
    return 0;
}

int handling(int argc, char **argv)
{
    if (argc == 1 || argc > 3) {
        return 84;
    }
    if (my_strcmp("-h", argv[1]) == 0) {
        help_txt();
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int win = 1;
    int err_hand = handling(argc, argv);

    if (err_hand != 0)
        return err_hand;
    win = settings(argc, argv);
    return win;
}
