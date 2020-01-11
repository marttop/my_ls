/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** s_ra
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

void s_ra_sub(infos_t *infos)
{
    node_t *temp_node;
    if (infos->head != NULL && infos->head->next != NULL) {
        temp_node = infos->head->next;
        infos->head->next = infos->bottom->next;
        infos->bottom->next = infos->head;
        infos->bottom = infos->head;
        infos->head = temp_node;
    }
}