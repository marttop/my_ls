/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** main
*/

#include "my_ls.h"

int main(int ac, char **av)
{
    char *flags;
    char **filepath;
    files_t fa;
    char *test[2] = {".", NULL};
    infos_t *main_node = NULL;
    flags = parsor(av);
    filepath = filepath_parsor(av, flags, &fa);
    if (filepath[0] == NULL)
        no_arg(flags);
    if (ac > 1) {
        if (filepath[0] != NULL) {
            main_node = get_data(filepath);
            show_data(main_node, flags, filepath, &fa);
        }
        else if (filepath[0] == NULL && fa.but != 1) {
            main_node = get_data(test);
            show_data(main_node, flags, test, &fa);
        }
    }
    return (0);
}