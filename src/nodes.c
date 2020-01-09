/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** nodes
*/

#include "my_ls.h"

void get_end(files_t *fa)
{
    infos_t *temp_node = fa->head;
    for (; temp_node->next != NULL;)
        temp_node = temp_node->next;
    fa->bottom = temp_node;
}

int count_nodes(infos_t *node)
{
    infos_t *temp = node;
    int counter = 0;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return (counter);
}

int count_sub_nodes(node_t *node)
{
    node_t *temp = node;
    int counter = 0;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return (counter);
}