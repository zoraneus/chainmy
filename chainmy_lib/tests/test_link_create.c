/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** test_link_create
*/

#include <criterion/criterion.h>
#include "my_link.h"
#include <string.h>

Test(link_create, basic)
{
    link_t *link = link_create(strdup("phrase"));

    cr_assert_eq(link->next, NULL);
    cr_assert_eq(link->prev, NULL);
    cr_assert_str_eq((char*)link->content, "phrase");
    free(link->content);
    free(link);
}