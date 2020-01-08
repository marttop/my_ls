/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** filepath_parsor
*/

#include "my_ls.h"

int get_nb_files(char **src)
{
    int counter = 0;
    for (int i = 0; src[i] != NULL; i++)
        if (src[i][0] != '-')
            counter++;
    return (counter);
}

char *fill_str(char *res, char *src)
{
    int i = 0;
    for (; src[i] != '\0'; i++)
        res[i] = src[i];
    res[i] = '\0';
    return (res);
}

char **external_fill(int i, int *j, char **filepath, char **src)
{
    if (src[i][0] != '-') {
        filepath[j[0]] = malloc(sizeof(char) * my_strlen(src[i]) + 1);
        filepath[j[0]] = fill_str(filepath[j[0]], src[i]);
        j[0]++;
    }
    return (filepath);
}

void print_files(char *flags, char **files, char **filepath, files_t *fa)
{
    int done = 0;
    for (int i = 0; files[i] != NULL; i++) {
        if (flagcheck('l', flags)) {
            print_l_flag_file(files[i]);
        }
        else {
            my_putstr(files[i]);
            my_putchar('\n');
        }
        fa->nm = 1;
        done = 1;
    }
    if (done == 1 && filepath[0] != NULL)
        my_putchar('\n');
}

char **filepath_parsor(char **src, char *flags, files_t *fa)
{
    int nb_files = get_nb_files(src), i = 1, j = 0, k = 0;
    char **filepath = malloc(sizeof(char *) * (nb_files + 1));
    char **files = malloc(sizeof(char *) * (nb_files + 1));
    DIR *__dirp;
    for (; src[i] != NULL; i++) {
        __dirp = opendir(src[i]);
        if (__dirp != NULL)
            filepath = external_fill(i, &j, filepath, src);
        else if (__dirp == NULL && src[i][0] != '-') {
            files[k] = malloc(sizeof(char) * my_strlen(src[i]) + 1);
            files[k] = fill_str(files[k], src[i]), k++;
        }
        closedir(__dirp);
    }
    files[k] = NULL;
    filepath[j] = NULL;
    fa->but = filepath[0] == NULL ? 1 : 0;
    fa->files = files;
    print_files(flags, files, filepath, fa);
    return (filepath);
}