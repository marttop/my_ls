/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** no_arg
*/

#include "my_ls.h"

void no_arg(void)
{
    DIR *__dirp = opendir(".");
    struct dirent *my_dirent = readdir(__dirp);

    while (my_dirent != NULL) {
        if (my_dirent->d_name[0] != '.') {
            my_putstr(my_dirent->d_name);
            my_putchar('\n');
        }
        my_dirent = readdir(__dirp);
    }
    closedir(__dirp);
}