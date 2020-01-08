/*
** EPITECH PROJECT, 2019
** nbr
** File description:
** oui
*/

#include "my_ls.h"

void my_put_nbr(long n)
{
    long modulo;
    long a = 10;

    if (n < 0) {
        n *= -1;
        my_putchar('-');
    }
    if (n < 10)
        my_putchar(48 + n % 10);
    else {
        modulo = (n % a);
        n = (n - modulo) / a;
        my_put_nbr(n);
        my_putchar(48 + modulo);
    }
}
