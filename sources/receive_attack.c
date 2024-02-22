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

void retransciptor(data_t *data, int *x, int *y)
{
    *y = data->attack % 10;
    data->attack / 10;
    *x = data->attack / 10;
    data->attack = 0;
    return;
}

void send_res_attack(data_t *data, int touch)
{
    int bin = my_decto_bin(touch);
    int temp = bin;

    usleep(500);
    for (int i = 0; i < 8; i++) {
        if (temp % 10 == 0) {
            kill(data->adv_id, 10);
        } else {
            kill(data->adv_id, 12);
        }
        temp /= 10;
        usleep(500);
    }
}

char *sos(data_t *data, int x, int y)
{
    int touch = 50;

    x++;
    y = y * 2;
    if (data->my_map[x][y] != '.') {
        touch = 100;
    }
    send_res_attack(data, touch);
    if (touch == 100)
        return "hit";
    return "missed";
}
