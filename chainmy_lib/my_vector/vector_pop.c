/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** vector_pop
*/

#include "my_vector.h"

void vector_pop_me(vector_t *vect, link_t *node)
{
    if (vect->start == vect->end) {
        vect->size = 0;
        free(vect->start);
        vect->start = 0;
        vect->end = 0;
        return;
    }
    if (node == vect->start)
        vect->start = node->next;
    if (node == vect->end)
        vect->end = node->prev;
    link_pop_me(node);
    vect->size--;
}

void vector_pop_back(vector_t *vect)
{
    vector_pop_me(vect, vect->end);
}

void vector_pop_top(vector_t *vect)
{
    vector_pop_me(vect, vect->start);
}