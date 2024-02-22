/*
** EPITECH PROJECT, 2024
** dec to bin
** File description:
** convert dec to bin
*/

int my_decto_bin(int n)
{
    int bin = 0;
    int base = 1;

    if (n == 0) {
        return 0;
    }
    while (n > 0) {
        bin += (n % 2) * base;
        n /= 2;
        base *= 10;
    }
    return bin;
}
