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

void check_files(char **files)
{
    int i = 0;
    struct stat sb;
    while (files[i] != NULL) {
        if (stat(files[i], &sb) == -1) {
            my_putstr("my_ls: cannot access '");
            my_putstr(files[i]);
            error("': No such file or directory\n");
        }
        if ((my_strcmp(files[i], "/root") == 0) ||
        (my_strcmp(files[i], "/root/") == 0)) {
            my_putstr("my_ls: cannot access '");
            my_putstr(files[i]);
            error("': No such file or directory\n");
        }
        i++;
    }
}