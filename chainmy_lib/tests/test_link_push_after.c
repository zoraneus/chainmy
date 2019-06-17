/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** test_link_push_after
*/

#include <criterion/criterion.h>
#include "my_link.h"
#include <string.h>

Test(link_push_after, basic_next_at_end)
{
    link_t *first = link_create(strdup("phrase1"));

    link_push_after(first, strdup("phrase2"));
    cr_assert_str_eq((char*)first->content, "phrase1");
    cr_assert_str_eq((char*)first->next->content, "phrase2");
    cr_assert_eq(first->next->next, NULL);
    free(first->next->content);
    free(first->next);
    free(first->content);
    free(first);
}

Test(link_push_after, basic_prev_at_end)
{
    link_t *first = link_create(strdup("phrase1"));

    link_push_after(first, strdup("phrase2"));
    cr_assert_str_eq((char*)first->next->prev->content, "phrase1");
    cr_assert_eq(first->prev, NULL);
    free(first->next->content);
    free(first->next);
    free(first->content);
    free(first);
}

Test(link_push_after, push_to_middle_test_next)
{
    link_t *first = link_create(strdup("test1"));

    link_push_after(first, strdup("test3"));
    link_push_after(first, strdup("test2"));
    cr_assert_str_eq((char*)first->next->content, "test2");
    cr_assert_str_eq((char*)first->next->next->content, "test3");
    cr_assert_eq(first->next->next->next, NULL);
    free(first->next->next);
    free(first->next->content);
    free(first->next);
    free(first->content);
    free(first);
}