/*
** EPITECH PROJECT, 2024
** include
** File description:
** include clean_str
*/

#ifndef CLEAN_H_
    #define CLEAN_H_
    #include <unistd.h>

typedef struct data_s {
    int win;
    char **my_map;
    char **adv_map;
    int trans;
    int usr;
    int adv_id;
    int p1_id;
    int p2_id;
    int attack;
    char *oct;
} data_t;

typedef struct mapping_s {
    int nb;
    int y1;
    int y2;
    int x1;
    int x2;
    int k;
} mapping_t;

int data_choice(data_t *data, int bin);
void prep_oct(data_t *data);
void init_oct(data_t *data);
void received_datas(data_t *data, int sig);
int is_full(data_t *data, char *oct);


void send_res_attack(data_t *data, int touch);


int settings(int argc, char *argv[]);
int map_generator(data_t *data, char *pwd);
int send_attack(data_t *data, int x, int y);
int res_attack(data_t *data, int x, int y);
void retransciptor(data_t *data, int *x, int *y);
char *sos(data_t *data, int x, int y);
int assign(data_t *data, char *pos);


void print_map(char **map, char *str);
void printer_maps(data_t *data);


int is_finish(data_t *data);
int valid_datas(data_t *data, int x, int y, char *snipe);
int game(data_t *data);

#endif /* !CLEAN_H_ */
