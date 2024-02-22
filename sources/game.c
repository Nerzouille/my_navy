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

void fill(data_t *data, int x, int y, int touch)
{
    x++;
    y = y * 2;
    if (touch == 100)
        data->adv_map[x][y] = 'x';
    else
        data->adv_map[x][y] = 'o';
}

static int attackack(data_t *data, int x, int y, char *snipe)
{
    int touch;

    send_attack(data, x, y);
    touch = res_attack(data, snipe[0], snipe[1]);
    fill(data, x, y, touch);
}

void play(data_t *data)
{
    char *snipe = NULL;
    size_t len = 0;
    int corr_fill = 0;
    int x;
    int y;
    int touch;

    my_printf("\nattack: ");
    while (corr_fill == 0) {
        getline(&snipe, &len, stdin);
        if (len != 0) {
            x = snipe[1] - 48;
            y = snipe[0] - 64;
            corr_fill = valid_datas(data, x, y, snipe);
        }
    }
    if (corr_fill == 1)
        attackack(data, x, y, snipe);
}

void wait(data_t *data)
{
    int x;
    int y;

    data->attack = 0;
    my_printf("\nwaiting for enemy's attack...");
    prep_oct(data);
    while (data->attack == 0);
    if (data->attack >= 111) {
        data->attack -= 100;
        y = data->attack % 10;
        x = data->attack / 10 % 10;
        my_printf("\n\nresult: %c%c:missed\n", y + 64, x + 48);
    } else {
        retransciptor(data, &x, &y);
        my_printf("\n\nresult: %c%c:%s\n", y + 64, x + 48, sos(data, x, y));
    }
}

void init_round(data_t *data, int player)
{
    printer_maps(data);
    data->usr == player;
}

int game(data_t *data)
{
    int prec = 0;
    int win = 0;

    while (win == 0) {
        if (data->usr == -4 || (data->usr == 1 && prec != 1)) {
            init_round(data, 1);
            prec = 1;
            play(data);
            wait(data);
        }
        if (data->usr == 2 || (data->usr == -1 && prec != -1)) {
            init_round(data, -1);
            prec = -1;
            wait(data);
            play(data);
        }
        data->usr *= -1;
        win = is_finish(data);
    }
    return win;
}
