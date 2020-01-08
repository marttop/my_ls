/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** flag_parsor
*/

#include "my_ls.h"

int bis_counter(char *src, int counter)
{
    for (int i = 1; src[i] != '\0'; i++)
        counter++;
    return (counter);
}

char *bis_parsor(char *src, char *flags, int *w)
{
    for (int i = 1; src[i] != '\0'; i++, w[0]++)
        flags[w[0]] = src[i];
    return (flags);
}

int flag_counter(char **src)
{
    int counter = 0;
    for (int i = 0; src[i] != NULL; i++)
        if (src[i][0] == '-')
            counter = bis_counter(src[i], counter);
    return (counter);
}

char *parsor(char **src)
{
    int nb_flags = flag_counter(src);
    char *flags = malloc(sizeof(char) * nb_flags + 1);
    int w = 0;
    for (int i = 0; src[i] != NULL; i++) {
        if (src[i][0] == '-') {
            flags = bis_parsor(src[i], flags, &w);
        }
    }
    flags[w] = '\0';
    return (flags);
}