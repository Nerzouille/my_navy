/*
** EPITECH PROJECT, 2024
** map generator
** File description:
** generator of maps for my_navy
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

int map_opener(char **map, char *pwd)
{
    int file = open(pwd, O_RDONLY);
    int len_v = 179;

    if (file < 0)
        return 84;
    *map = malloc(sizeof(char *) * (len_v + 1));
    read(file, *map, len_v);
    (*map)[len_v] = '\0';
    close(file);
    return 0;
}

int my_operator(data_t *data, char *map_base)
{
    int k = 0;

    data->my_map = malloc(sizeof(char *) * (10 + 1));
    for (int i = 0; i < 10; i++) {
        data->my_map[i] = malloc(sizeof(char) * (18 + 1));
        data->my_map[i][18] = '\0';
    }
    data->my_map[10] = NULL;
    for (int i = 0; data->my_map[i] != NULL; i++) {
        for (int j = 0; j < 18; j++) {
            data->my_map[i][j] = map_base[k];
            k++;
        }
    }
}

int adv_operator(data_t *data, char *map_base)
{
    int k = 0;

    data->adv_map = malloc(sizeof(char *) * (10 + 1));
    for (int i = 0; i < 10; i++) {
        data->adv_map[i] = malloc(sizeof(char) * (18 + 1));
        data->adv_map[i][18] = '\0';
    }
    data->adv_map[10] = NULL;
    for (int i = 0; data->adv_map[i] != NULL; i++) {
        for (int j = 0; j < 18; j++) {
            data->adv_map[i][j] = map_base[k];
            k++;
        }
    }
}

int map_generator(data_t *data, char *pwd)
{
    char *map_base;
    char *pos;

    if (map_opener(&map_base, "./assets/table.txt") == 84
        || map_opener(&pos, pwd) == 84)
        return 84;
    my_operator(data, map_base);
    adv_operator(data, map_base);
    return assign(data, pos);
}
