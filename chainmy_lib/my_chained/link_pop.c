/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** link_pop
*/

#include "my_link.h"

void link_pop_me(link_t *link)
{
    if (link->prev != 0)
        link->prev->next = link->next;
    if (link->next != 0)
        link->next->prev = link->prev;
    free(link);
}

void link_pop_back(link_t *link)
{
    link_t *current = link;

    while (current->next != 0)
        current = current->next;
    link_pop_me(current);
}