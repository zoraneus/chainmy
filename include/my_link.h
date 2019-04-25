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

link_t *link_create(void *content);
void link_push_back(link_t *link, void *content);
void link_push_top(link_t **link, void *content);
void link_push_after(link_t *link, void *content);
void link_push_before(link_t *link, void *content);
void link_pop_me(link_t *link);
void link_pop_back(link_t *link);
void link_pop_top(link_t *link);

//debug
void link_debug_desc(link_t *link);
void link_debug_asc(link_t *link);

#endif /* !MY_CHAINED_H_ */