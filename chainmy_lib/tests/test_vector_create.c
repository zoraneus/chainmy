/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** test_vector_create
*/

#include <criterion/criterion.h>
#include "my_vector.h"

Test(vector_create, basic)
{
    vector_t *list = vector_create();

    cr_assert_eq(list->start, NULL);
    cr_assert_eq(list->end, NULL);
    cr_assert_eq(list->size, 0);
    free(list);    
}