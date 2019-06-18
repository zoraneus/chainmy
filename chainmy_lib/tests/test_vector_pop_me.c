/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** test_vector_pop_me
*/

#include <criterion/criterion.h>
#include <string.h>
#include "my_vector.h"

Test(vector_pop_me, size_1_to_empty)
{
    vector_t *vect = vector_create();

    vector_push_back(vect, strdup("phrase"));
    free(vect->start->content);
    vector_pop_me(vect, vect->start);
    cr_assert_eq(vect->size, 0);
    cr_assert_eq(vect->start, NULL);
    cr_assert_eq(vect->end, NULL);
    free(vect);
}

Test(vector_pop_me, size_2_remove_end)
{
    vector_t *vect = vector_create();

    vector_push_back(vect, strdup("to keep"));
    vector_push_back(vect, strdup("to remove"));
    free(vect->end->content);
    vector_pop_me(vect, vect->end);
    cr_assert_eq(vect->size, 1);
    cr_assert_eq(vect->start, vect->end);
    cr_assert_str_eq((char*)vect->start->content, "to keep");
    cr_assert_eq(vect->start->next, NULL);
    cr_assert_eq(vect->start->prev, NULL);
    free(vect->start->content);
    free(vect->start);
    free(vect);
}

Test(vector_popo_me, size_2_remove_start)
{
    vector_t *vect = vector_create();

    vector_push_back(vect, strdup("to remove"));
    vector_push_back(vect, strdup("to keep"));
    free(vect->start->content);
    vector_pop_me(vect, vect->start);
    cr_assert_eq(vect->size, 1);
    cr_assert_eq(vect->start, vect->end);
    cr_assert_str_eq((char*)vect->start->content, "to keep");
    cr_assert_eq(vect->start->next, NULL);
    cr_assert_eq(vect->start->prev, NULL);
    free(vect->start->content);
    free(vect->start);
    free(vect);
}