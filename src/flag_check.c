/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** flag_check
*/

#include "my_ls.h"

void print_l_flag_file(char *str)
{
    struct stat sb;
    if (stat(str, &sb) != -1) {
        my_putstr(get_mode(&sb));
        my_putchar(' ');
        my_put_nbr(sb.st_nlink);
        my_putchar(' ');
        my_putstr(getpwuid(sb.st_uid)->pw_name);
        my_putchar(' ');
        my_putstr(getgrgid(sb.st_gid)->gr_name);
        my_putchar(' ');
        my_put_nbr(sb.st_size);
        my_putchar(' ');
        my_putstr(get_date(&sb));
        my_putchar(' ');
        my_putstr(str);
        my_putchar('\n');
    }
}

int flagcheck(char c, char *flags)
{
    for (int i = 0; flags[i] != '\0'; i++) {
        if (flags[i] == c)
            return (1);
    }
    return (0);
}

void show_data(infos_t *node, char *flags, char **filepath, files_t *fa)
{
    int done = 0;
    fa->head = node;
    reverse(fa);
    if (flagcheck('t', flags))
        swap_n(fa);
    if (flagcheck('r', flags))
        reverse(fa);
    if (flagcheck('l', flags) && done == 0) {
        print_l_flag(filepath, fa);
        done = 1;
    }
    if (done == 0)
        print_no_flags(filepath, fa);
}