/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** string display
*/

#include "my_ls.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    if (str == NULL) {
        my_putchar('\r');
        return (0);
    }
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}
