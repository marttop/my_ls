/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** print_flags
*/

#include "my_ls.h"

void second_print(node_t *node)
{
    my_putstr(node->mode);
    my_putchar(' ');
    my_put_nbr(node->link);
    my_putchar(' ');
    my_putstr(node->usr_name);
    my_putchar(' ');
    my_putstr(node->grp_name);
    my_putchar(' ');
    if (node->device != 0) {
        my_put_nbr(node->device);
        my_putstr(", ");
    }
    my_put_nbr(node->size);
    my_putchar(' ');
    my_putstr(node->date);
    my_putchar(' ');
    my_putstr(node->name);
}

void print_no_flags(char **filepath, files_t *fa)
{
    int j = my_ptrlen(filepath), i = 0;
    struct stat sb;
    for (; fa->head != NULL; i++) {
        if (filepath[1] != NULL || (filepath[1] == NULL && fa->nm == 1)) {
            my_putstr(fa->head->filepath);
            my_putstr(":\n");
        }
        for (int x = j; fa->head->head != NULL; x++) {
            my_putstr(fa->head->head->name);
            (x > i) ? my_putchar('\n') : my_putchar('\0');
            fa->head->head = fa->head->head->next;
        }
        if (j - 1 > i)
            my_putchar('\n');
        closedir(fa->head->__dirp);
        fa->head = fa->head->next;
    }
}

void print_l_flag(char **filepath, files_t *fa)
{
    int j = my_ptrlen(filepath), i = 0;
    for (; fa->head != NULL; i++) {
        if (filepath[1] != NULL || (filepath[1] == NULL && fa->nm == 1)) {
            my_putstr(fa->head->filepath);
            my_putstr(":\n");
        }
        my_putstr("total ");
        my_put_nbr(fa->head->total_blocks);
        my_putchar('\n');
        for (int x = j; fa->head->head != NULL; x++) {
            second_print(fa->head->head);
            (x > i) ? my_putchar('\n') : my_putchar('\0');
            fa->head->head = fa->head->head->next;
        }
        if (j - 1 > i)
            my_putchar('\n');
        closedir(fa->head->__dirp);
        fa->head = fa->head->next;
    }
}