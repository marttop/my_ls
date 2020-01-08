/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** no_arg
*/

#include "my_ls.h"

void no_arg_print_l(struct dirent *my_dirent, DIR *__dirp)
{
    struct stat sb;
    int blocks = 0;
    while (my_dirent != NULL) {
        stat(my_dirent->d_name, &sb);
        if (my_dirent->d_name[0] != '.')
            blocks += sb.st_blocks/2;
        my_dirent = readdir(__dirp);
    }
    closedir(__dirp);
    __dirp = opendir(".");
    my_dirent = readdir(__dirp);
    my_putstr("total ");
    my_put_nbr(blocks);
    my_putchar('\n');
    while (my_dirent != NULL) {
        if (my_dirent->d_name[0] != '.')
            print_l_flag_file(my_dirent->d_name);
        my_dirent = readdir(__dirp);
    }
    closedir(__dirp);
}

void no_arg_print(struct dirent *my_dirent, DIR *__dirp)
{
    while (my_dirent != NULL) {
        if (my_dirent->d_name[0] != '.') {
            my_putstr(my_dirent->d_name);
            my_putchar('\n');
        }
        my_dirent = readdir(__dirp);
    }
    closedir(__dirp);
}

void no_arg(char *flags)
{
    DIR *__dirp = opendir(".");
    struct dirent *my_dirent = readdir(__dirp);
    int done = 0;
    if (flagcheck('l', flags) && done == 0) {
        no_arg_print_l(my_dirent, __dirp);
        done = 1;
    }
    else
        no_arg_print(my_dirent, __dirp);
}