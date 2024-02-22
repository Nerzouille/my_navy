/*
** EPITECH PROJECT, 2024
** game
** File description:
** game loop my_navy
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stddef.h>
#include "../include/my.h"
#include "../include/navy.h"

int data_choice(data_t *data, int bin)
{
    if (bin == 0) {
        kill(data->adv_id, 10);
    } else {
        kill(data->adv_id, 12);
    }
    return 0;
}

int valid_datas(data_t *data, int x, int y, char *snipe)
{
    int missed = 0;

    if (x > 8 || x < 1 || y > 8 || y < 1 || snipe[2] != '\n') {
        my_printf("\nwrong position\n\nattack: ");
        return 0;
    }
    if (data->adv_map[x + 1][y * 2] != '.') {
        missed = x * 10 + y + 100;
        send_res_attack(data, missed);
        my_printf("\nresult: %c%c:missed\n", y + 64, x + 48);
        return 4;
    }
    return 1;
}

int send_attack(data_t *data, int x, int y)
{
    int attack_bin = my_decto_bin(x * 10 + y);
    int attack = attack_bin;

    data->attack = 0;
    for (int i = 0; i < 8; i++) {
        usleep(500);
        data_choice(data, attack % 10);
        attack /= 10;
    }
}

int res_attack(data_t *data, int x, int y)
{
    int res;

    prep_oct(data);
    while (data->attack == 0);
    res = data->attack;
    if (res == 100)
        my_printf("\nresult: %c%c:hit\n", x, y);
    else
        my_printf("\nresult: %c%c:missed\n", x, y);
    return res;
}
