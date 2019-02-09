/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_vector_debug
*/

#include "my_vector.h"

void d_simple_vector_show(simple_vector_t *vect)
{
    simple_chained_t *link = vect->start;

    while (link != 0) {
        my_putstr((char *)link->content);
        my_putchar('\n');
        link = link->next;
    }
}