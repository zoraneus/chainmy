/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** test_vector_push_back
*/

#include <criterion/criterion.h>
#include "my_vector.h"
#include <string.h>

Test(vector_push_back, to_empty_list)
{
    vector_t *vect = vector_create();

    vector_push_back(vect, strdup("phrase"));
    cr_assert_eq(vect->start, vect->end);
    cr_assert_str_eq((char*)vect->start->content, "phrase");
    cr_assert_eq(vect->start->next, NULL);
    cr_assert_eq(vect->start->prev, NULL);
    cr_assert_eq(vect->size, 1);
    free(vect->start->content);
    free(vect->start);
    free(vect);
}

Test(vector_push_back, to_non_empty_list)
{
    vector_t *vect = vector_create();

    vector_push_back(vect, strdup("phrase1"));
    vector_push_back(vect, strdup("phrase2"));
    cr_assert_eq(vect->size, 2);
    cr_assert_str_eq((char*)vect->start->content, "phrase1");
    cr_assert_str_eq((char*)vect->end->content, "phrase2");
    cr_assert_str_eq((char*)vect->start->next->content, "phrase2");
    cr_assert_str_eq((char*)vect->end->prev->content, "phrase1");
    cr_assert_eq(vect->start->prev, NULL);
    cr_assert_eq(vect->end->next, NULL);
    free(vect->end->content);
    free(vect->end);
    free(vect->start->content);
    free(vect->start);
    free(vect);
}
