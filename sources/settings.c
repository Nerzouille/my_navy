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

data_t data;

static void my_handler(int sig, siginfo_t *siginfo, void *ctx)
{
    if (sig == 10 && data.p2_id == 0) {
        data.p2_id = siginfo->si_pid;
        data.adv_id = data.p2_id;
        return;
    }
    if (sig == 12 && data.p1_id == 0) {
        data.p1_id = siginfo->si_pid;
        data.adv_id = data.p1_id;
        return;
    }
    if (data.trans == 1) {
        received_datas(&data, sig);
        is_full(&data, data.oct);
    } else
        data.win = 42;
    return;
}

int set_p1(data_t *data, char *argv[])
{
    int win = 0;

    if (map_generator(data, argv[1]) == 84)
        return 84;
    data->usr = -4;
    data->p1_id = getpid();
    my_printf("my_pid: %d\n\nwaiting for ennemy connection...\n",
        (data->p1_id));
    while (data->p2_id == 0);
    kill(data->p2_id, 12);
    my_printf("\nenemy connected\n");
    return win;
}

int set_p2(data_t *data, char *argv[])
{
    int p1_id = my_getnbr(argv[1]);
    int win = 0;

    if (map_generator(data, argv[2]) == 84)
        return 84;
    data->usr = 2;
    data->p2_id = getpid();
    if (my_str_isnum(argv[1]) != 1) {
        my_printf("\nThis ID is'nt valid.\n\n");
        return 84;
    }
    my_printf("my_pid: %d %d\n", data->p2_id, p1_id);
    kill(p1_id, 10);
    while (data->p1_id == 0);
    my_printf("\nsuccessfully connected\n");
    return win;
}

int settings(int argc, char *argv[])
{
    struct sigaction event;
    int err;

    data = (data_t){.p1_id = 0, .p2_id = 0, .trans = 0,
    .oct = malloc(sizeof(char *) * 9), .win = 0};
    event.sa_sigaction = &my_handler;
    event.sa_flags = SA_SIGINFO;
    sigaction(10, &event, NULL);
    sigaction(12, &event, NULL);
    if (argc == 2)
        err = set_p1(&data, argv);
    else
        err = set_p2(&data, argv);
    if (err == 84) {
        my_printf("ERROR\n");
        return 84;
    }
    if (game(&data) == 1)
        return 1;
    return 0;
}
