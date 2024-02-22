/*
** EPITECH PROJECT, 2024
** bin to dec
** File description:
** convert bin to dec
*/

int my_binto_dec(int bin)
{
    int dec = 0;
    int base = 1;
    int remain;

    while (bin > 0) {
        remain = bin % 10;
        dec += remain * base;
        bin /= 10;
        base *= 2;
    }
    return dec;
}
