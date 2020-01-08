/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_ptrlen
*/

#include "my_ls.h"

int my_ptrlen(char **str)
{
    int i = 0;
    if (str[i] == NULL)
        return (0);
    for (; str[i] != NULL; i++);
    return (i);
}