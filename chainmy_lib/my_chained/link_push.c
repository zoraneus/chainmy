/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** link
*/

#include "my_link.h"

link_t *link_create(void *content)
{
    link_t *link = malloc(sizeof(link_t));

    if (!link)
        return (NULL);
    link->content = content;
    link->prev = 0;
    link->next = 0;
    return (link);
}

void link_push_back(link_t *link, void *content)
{
    link_t *current = link;
    link_t *new = link_create(content);

    if (!new)
        return;
    while (current->next != 0)
        current = current->next;
    current->next = new;
    new->prev = current;
}

void link_push_top(link_t **link, void *content)
{
    link_t *node = *link;

    while (node->prev != 0)
        node = node->prev;
    link_push_before(node, content);
    *link = node->prev;
}

void link_push_after(link_t *link, void *content)
{
    link_t *new = link_create(content);

    if (!new)
        return;
    if (link->next != 0)
        link->next->prev = new;
    new->prev = link;
    new->next = link->next;
    link->next = new;
}

void link_push_before(link_t *link, void *content)
{
    link_t *new = link_create(content);

    if (!new)
        return;
    if (link->prev != 0)
        link->prev->next = new;
    new->prev = link->prev;
    new->next = link;
    link->prev = new;
}