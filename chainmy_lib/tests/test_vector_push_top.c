/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** test_vector_push_top
*/

#include <criterion/criterion.h>
#include "my_vector.h"
#include <string.h>

Test(vector_push_top, to_empty_list)
{
    vector_t *vect = vector_create();

    vector_push_top(vect, strdup("phrase1"));
    cr_assert_eq(vect->size, 1);
    cr_assert_eq(vect->start, vect->end);
    cr_assert_eq(vect->start->next, NULL);
    cr_assert_eq(vect->start->prev, NULL);
    cr_assert_str_eq((char*)vect->start->content, "phrase1");
    free(vect->start->content);
    free(vect->start);
    free(vect);
}

Test(vector_push_top, non_empty_list)
{
    vector_t *vect = vector_create();

    vector_push_top(vect, strdup("phrase2"));
    vector_push_top(vect, strdup("phrase1"));
    cr_assert_eq(vect->size, 2);
    cr_assert_str_eq((char*)vect->start->content, "phrase1");
    cr_assert_str_eq((char*)vect->end->content, "phrase2");
    cr_assert_eq(vect->start->next, vect->end);
    cr_assert_eq(vect->end->prev, vect->start);
    cr_assert_eq(vect->start->prev, NULL);
    cr_assert_eq(vect->end->next, NULL);
    free(vect->end->content);
    free(vect->end);
    free(vect->start->content);
    free(vect->start);
    free(vect);
}