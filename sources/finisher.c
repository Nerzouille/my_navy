/*
** EPITECH PROJECT, 2024
** is finish ?
** File description:
** return if game finish or not my_navy
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stddef.h>
#include "../include/my.h"
#include "../include/navy.h"

static int occu_boat(data_t *data, int count, int i)
{
    for (int j = 0; data->adv_map[i][j] != '\0'; j++)
        if (data->adv_map[i][j] == 'x')
            count++;
    return count;
}

int is_finish(data_t *data)
{
    int count = 0;

    for (int i = 0; data->adv_map[i] != NULL; i++)
        count = occu_boat(data, count, i);
    if (count == 14) {
        send_attack(data, 9, 9);
        printer_maps(data);
        my_printf("\nI won\n");
        return 4;
    }
    usleep(1250);
    if (data->win != 0) {
        printer_maps(data);
        my_printf("\nEnemy won\n");
        return 1;
    }
    return 0;
}
