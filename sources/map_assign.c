/*
** EPITECH PROJECT, 2024
** map assign
** File description:
** map assign for each navy my_navy
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stddef.h>
#include <fcntl.h>
#include "../include/my.h"
#include "../include/navy.h"

static int assign_y(data_t *data, mapping_t *temp)
{
    int x = temp->x1 + 1;
    int y;

    for (int j = 1; j < (temp->y2 - temp->y1) * 2 + 2; j += 2) {
        y = temp->y1 * 2 + 1 + j;
        if (data->my_map[x][y] == '.')
            data->my_map[x][y] = temp->k + 48;
        else
            return 84;
    }
    return 0;
}

static int assign_x(data_t *data, mapping_t *temp)
{
    int x;
    int y = 2 + temp->y1 * 2;

    for (int j = 1; j < (temp->x2 - temp->x1) + 2; j++) {
        x = temp->x1 + j;
        if (data->my_map[x][y] == '.')
            data->my_map[x][y] = temp->k + 48;
        else
            return 84;
    }
    return 0;
}

int struct_massign(mapping_t *temp, char *pos, int i)
{
    int k = pos[i - 2] - 49;

    temp->nb++;
    temp->y1 = pos[i] - 65;
    temp->x1 = pos[i + 1] - 48;
    temp->y2 = pos[i + 3] - 65;
    temp->x2 = pos[i + 4] - 48;
    if (temp->k != k) {
        my_printf("\nTwo boats of same length");
        return 84;
    }
    temp->k = k;
    return 0;
}

static int enough_boats(mapping_t *temp)
{
    if (temp->nb != 4) {
        my_printf("Not enough boats.\n");
        return 84;
    }
    return 0;
}

int assign(data_t *data, char *pos)
{
    mapping_t temp = (mapping_t){0, 0, 0, 0, 0, 1};
    int err = 84;

    for (int i = 2; pos[i] != '\0'; i++) {
        err = struct_massign(&temp, pos, i);
        if (((temp.y2 - temp.y1) != temp.k && (temp.x2 - temp.x1) != temp.k)
            || (temp.y2 - temp.y1) == (temp.x2 - temp.x1) || err == 84) {
            my_printf("\nWRONG BOAT: %d\n", temp.k + 1);
            return 84;
        }
        i += 7;
        temp.k++;
        if ((temp.y2 - temp.y1) != 0)
            err = assign_y(data, &temp);
        else
            err = assign_x(data, &temp);
    }
    if (enough_boats(&temp) == 84)
        return 84;
    return err;
}
