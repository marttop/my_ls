/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** error
*/

#include "my_ls.h"

void error(char *msg)
{
    int len = my_strlen(msg);
    write(2, msg, len);
    exit(84);
}