/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_strlen
*/

#include "my_ls.h"

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}