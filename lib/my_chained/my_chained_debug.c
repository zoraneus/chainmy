/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_chained_debug
*/

#include "my_chained.h"

void d_show_simple_chain(simple_chained_t *start)
{
    do {
        my_putstr((char *)start->content);
        my_putchar('\n');
        start = start->next;
    } while (start != 0);
}