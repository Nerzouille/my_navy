/*
** EPITECH PROJECT, 2024
** settings
** File description:
** settings my_navy
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stddef.h>
#include "../include/my.h"
#include "../include/navy.h"

void prep_oct(data_t *data)
{
    if (data->trans == 0) {
        data->trans = 1;
        data->oct[8] = '\0';
        for (int i = 0; i < 8; i++) {
            data->oct[i] = '5';
        }
    }
    return;
}

void init_oct(data_t *data)
{
    data->oct = malloc(sizeof(char) * 9);
    data->oct[8] = '\0';
}

void received_datas(data_t *data, int sig)
{
    static int i = 7;

    if (i == -1)
        i = 7;
    if (sig == 10)
        data->oct[i] = '0';
    if (sig == 12)
        data->oct[i] = '1';
    i--;
}

void interpretor(data_t *data, char *oct)
{
    int code = my_binto_dec(my_getnbr(oct));

    if (code >= 11 && code <= 88 || code == 100)
        data->attack = code;
    if (code >= 111)
        data->attack = code;
}

int is_full(data_t *data, char *oct)
{
    for (int i = 0; oct[i] != '\0'; i++) {
        if (oct[i] == '5')
            return 0;
    }
    data->trans = 0;
    interpretor(data, oct);
    return 1;
}
