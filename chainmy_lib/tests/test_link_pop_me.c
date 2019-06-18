/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** test_pop_me
*/

#include <criterion/criterion.h>
#include "my_link.h"
#include <string.h>

Test(link_pop_me, pop_at_start)
{
    link_t *first = link_create(strdup("phrase1"));
    link_t *second;

    link_push_after(first, strdup("phrase2"));
    second = first->next;
    free(first->content);
    link_pop_me(first);
    cr_assert_str_eq((char*)second->content, "phrase2");
    cr_assert_eq(second->prev, NULL);
    cr_assert_eq(second->next, NULL);
    free(second->content);
    free(second);
}

Test(link_pop_me, pop_at_end)
{
    link_t *first = link_create(strdup("phrase1"));

    link_push_after(first, strdup("phrase2"));
    free(first->next->content);
    link_pop_me(first->next);
    cr_assert_str_eq((char*)first->content, "phrase1");
    cr_assert_eq(first->next, NULL);
    cr_assert_eq(first->prev, NULL);
    free(first->content);
    free(first);
}

Test(link_pop_me, pop_in_middle)
{
    link_t *first = link_create(strdup("phrase1"));

    link_push_after(first, strdup("phrase2"));
    link_push_after(first->next, strdup("phrase3"));
    free(first->next->content);
    link_pop_me(first->next);
    cr_assert_str_eq(first->content, "phrase1");
    cr_assert_str_eq(first->next->content, "phrase3");
    cr_assert_eq(first->next->prev, first);
    free(first->next->content);
    free(first->next);
    free(first->content);
    free(first);
}