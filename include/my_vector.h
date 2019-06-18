/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_vector
*/

#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include "my_link.h"

struct vector {
    link_t *start;
    link_t *end;
    int size;
};
typedef struct vector vector_t;

/* vector_push.c:
create a chained list and init prev/next to null and size to 0*/
vector_t *vector_create(void);

/* vector_push.c:
add an link with "content" at the end of "vect" chained list */
void vector_push_back(vector_t *vect, void *content);

/*  vector_push.c:
add an link with "content" at the top of "vect" chained list*/
void vector_push_top(vector_t *vect, void *content);

/* vector_pop.c:
destroy the link "node" in the list "vect" and update size */
void vector_pop_me(vector_t *vect, link_t *node);

/* vector_pop.c:
destroy the link at the end of list "vect" and update size */
void vector_pop_back(vector_t *vect);

/* vector_pop.c:
destroy the link at the top of list "vect" and update size */
void vector_pop_top(vector_t *vect);

#endif /* !MY_VECTOR_H_ */
