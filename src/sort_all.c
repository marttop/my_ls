/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** sort_all
*/

#include "my_ls.h"

long long get_biggest(files_t *fa)
{
    long long biggest = -214748364700000000;
    infos_t *temp_node = fa->head;
    for (; temp_node != NULL;) {
        if (temp_node->time > biggest)
            biggest = temp_node->time;
        temp_node = temp_node->next;
    }
    return (biggest);
}

long long get_biggest_sub(infos_t *infos)
{
    long long biggest = -214748364700000000;
    node_t *temp_node = infos->head;
    for (; temp_node != NULL;) {
        if (temp_node->time > biggest)
            biggest = temp_node->time;
        temp_node = temp_node->next;
    }
    return (biggest);
}

void sort_sort(infos_t *infos)
{
    long long biggest = get_biggest_sub(infos);
    while (infos->head->time != biggest)
        s_ra_sub(infos);
    s_pb_sub(infos);
}

void swap_n_sub(files_t *fa)
{
    int i = 0;
    infos_t *temp = fa->head;
    while (temp != NULL) {
        i = count_sub_nodes(temp->head);
        temp->temp = NULL;
        get_end_sub(temp);
        for (; i > 0; i--) {
            sort_sort(temp);
        }
        temp->head = temp->temp;
        temp = temp->next;
    }
}

void swap_n(files_t *fa)
{
    int i = count_nodes(fa->head);
    long long biggest;
    fa->temp = NULL;
    for (; i > 0; i--) {
        biggest = get_biggest(fa);
        while (fa->head->time != biggest)
            s_ra(fa);
        s_pb(fa);
    }
    fa->head = fa->temp;
    swap_n_sub(fa);
    reverse(fa);
}