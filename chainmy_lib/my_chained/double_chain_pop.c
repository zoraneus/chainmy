/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** double_chain_pop
*/

#include "my_chained.h"

void double_chain_pop_me(double_chained_t *link)
{
    if (link->prev != 0)
        link->prev->next = link->next;
    if (link->next != 0)
        link->next->prev = link->prev;
    free(link);
}