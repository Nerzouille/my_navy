/*
** EPITECH PROJECT, 2024
** print map
** File description:
** print map my_navy
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

void print_map(char **map, char *str)
{
    my_printf("\n%s\n", str);
    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            my_printf("%c", map[i][j]);
    my_putchar('\n');
}

void printer_maps(data_t *data)
{
    data->attack = 0;
    print_map(data->my_map, "my navy:");
    print_map(data->adv_map, "enemy navy:");
}
