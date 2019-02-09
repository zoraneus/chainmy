/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_chained
*/

#ifndef MY_CHAINED_H_
#define MY_CHAINED_H_

#include "my_display.h"

//  simple chained list  //
struct simple_chained {
    struct simple_chained *next;
    void *content;
};
typedef struct simple_chained simple_chained_t;

simple_chained_t *simple_chain_create(void *content); //ok
void simple_chain_push_back(simple_chained_t *link, void *content); //ok
void simple_chain_push_top(simple_chained_t **link, void *content); //ok
void simple_chain_push_after(simple_chained_t *link, void *content);
void simple_chain_pop_after(simple_chained_t *link); //ok

// double chained  //
struct double_chained {
    struct double_chained *next;
    struct double_chained *prev;
    void *content;
};
typedef struct double_chained double_chained_t;

double_chained_t *double_chain_create(void *content);
void double_chain_push(double_chained_t *link, void *content);

//  debug show str functions for chained lists //
void d_show_simple_chain(simple_chained_t *start);

#endif /* !MY_CHAINED_H_ */