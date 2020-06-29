/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** main
*/

#include "my_ls.h"

int main(int ac, char **av)
{
    files_t fa = {0};
    char *flags = parsor(av);
    char **filepath = filepath_parsor(av, flags, &fa);
    check_files(filepath);
    char *test[2] = {".", NULL};
    infos_t *main_node = NULL;
    if (ac >= 1) {
        if (filepath[0] != NULL) {
            main_node = get_data(filepath);
            show_data(main_node, flags, filepath, &fa);
        }
        else if (filepath[0] == NULL) {
            main_node = get_data(test);
            show_data(main_node, flags, test, &fa);
        }
    }
    return (0);
}