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

vector_t *vector_create(void);
void vector_push_back(vector_t *vect, void *content);
void vector_push_top(vector_t *vect, void *content);
void vector_pop_me(vector_t *vect, link_t *node);
void vector_pop_back(vector_t *vect);
void vector_pop_top(vector_t *vect);

#endif /* !MY_VECTOR_H_ */
