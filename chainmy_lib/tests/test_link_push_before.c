/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** test_link_push_before
*/

#include <criterion/criterion.h>
#include "my_link.h"
#include <string.h>

Test(link_push_before, basic_at_top)
{
    link_t *second = link_create(strdup("phrase2"));

    link_push_before(second, strdup("phrase1"));
    cr_assert_eq(second->next, NULL);
    cr_assert_eq(second->prev->next, second);
    cr_assert_str_eq((char*)second->content, "phrase2");
    cr_assert_str_eq((char*)second->prev->content, "phrase1");
    cr_assert_eq(second->prev->prev, NULL);
    cr_assert_str_eq((char*)second->prev->next->content, "phrase2");
    free(second->prev->content);
    free(second->prev);
    free(second->content);
    free(second);
}

Test(link_push_before, push_to_middle)
{
    link_t *third = link_create(strdup("phrase3"));

    link_push_before(third, strdup("phrase2"));
    link_push_before(third->prev, strdup("phrase1"));
    cr_assert_eq(third->next, NULL);
    cr_assert_eq(third->prev->next, third);
    cr_assert_eq(third->prev->prev->next->next, third);
    cr_assert_eq(third->prev->prev->prev, NULL);
    cr_assert_str_eq((char*)third->content, "phrase3");
    cr_assert_str_eq((char*)third->prev->content, "phrase2");
    cr_assert_str_eq((char*)third->prev->prev->content, "phrase1");
    free(third->prev->prev->content);
    free(third->prev->prev);
    free(third->prev->content);
    free(third->prev);
    free(third->content);
    free(third);
}