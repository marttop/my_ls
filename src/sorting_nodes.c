/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** sorting_nodes
*/

#include "my_ls.h"

void s_ra(files_t *fa)
{
    infos_t *temp_node;
    if (fa->head != NULL && fa->head->next != NULL) {
        temp_node = fa->head->next;
        fa->head->next = fa->bottom->next;
        fa->bottom->next = fa->head;
        fa->bottom = fa->head;
        fa->head = temp_node;
    }
}

void s_pb(files_t *fa)
{
    infos_t *tmp_node = fa->head;
    if (fa->head != NULL) {
        fa->head = fa->head->next;
        tmp_node->next = fa->temp;
        fa->temp = tmp_node;
    }
}

void s_pb_sub(infos_t *infos)
{
    node_t *tmp_node = infos->head;
    if (infos->head != NULL) {
        infos->head = infos->head->next;
        tmp_node->next = infos->temp;
        infos->temp = tmp_node;
    }
}

void reverse(files_t *fa)
{
    int i = count_nodes(fa->head), j = 0;
    fa->temp = NULL;
    get_end(fa);
    for (int a = 0; a < i; a++) {
        fa->head->temp = NULL;
        j = count_sub_nodes(fa->head->head);
        for (int k = 0; k < j; k++) {
            s_pb_sub(fa->head);
        }
        fa->head->head = fa->head->temp;
        s_pb(fa);
    }
    fa->head = fa->temp;
}
