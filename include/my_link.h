/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_chained
*/

#ifndef MY_CHAINED_H_
#define MY_CHAINED_H_

#include "stdlib.h"

// double chained  //
struct link {
    struct link *next;
    struct link *prev;
    void *content;
};
typedef struct link link_t;

/* link_push.c:
create a node of a double chained list */
link_t *link_create(void *content);

/* link_push.c:
create a node and push it at the end of the chained list */
void link_push_back(link_t *link, void *content);

/* link_push.c:
create a node and push it at the begining of the chained list*/
void link_push_top(link_t **link, void *content);

/* link_push.c:
create a node and push it after the "link" node */
void link_push_after(link_t *link, void *content);

/* link_push.c:
create a node and push it before the "link" node */
void link_push_before(link_t *link, void *content);

/* link_pop.c:
destroy the node (link) and plumb in his prev and next
(no free of content) */
void link_pop_me(link_t *link);

/* link_pop.c:
destroy the node at the end of list and plumb in his prev and next
(no free content)*/
void link_pop_back(link_t *link);

/* link_pop.c:
destroy the node at the top of list and plumb in his prev and next
(no free content) */
void link_pop_top(link_t *link);

#endif /* !MY_CHAINED_H_ */