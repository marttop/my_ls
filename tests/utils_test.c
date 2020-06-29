/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** utils_test
*/

#include <criterion/criterion.h>
#include "my_ls.h"

Test(the_strlen_test, first_test)
{
    int i = my_strlen("Test");
    cr_assert_eq(i, 4);
    cr_assert_eq(my_strlen(NULL), 0);
}

Test(my_strdup_test, seccond_test)
{
    char *str = my_strdup("try this");
    cr_assert_arr_eq(str, "try this", 0);
    free(str);
}

Test(my_strcmp_test, third_test)
{
    int i = my_strcmp("Test", "Test");
    cr_assert_eq(i, 0);
    i = my_strcmp("aba", "abb");
    cr_assert_eq(i, -1);
    i = my_strcmp("aba", "abab");
    cr_assert_eq(i, -1);
    i = my_strcmp("zzz", "aaa");
    cr_assert_eq(i, 1);
}

Test(my_strcat_test, fourth_test)
{
    char *str = malloc(sizeof(char) * 20);
    my_strcat(str, "Hello");
    my_putstr(NULL), my_putstr("Hello");
    my_put_nbr(55), my_put_nbr(-55);
    cr_assert_arr_eq(str, "Hello", 0 );
    free(str);
}

Test(my_ptrlen_test, last_test)
{
    char *str[3] = {"test", "test", NULL};
    char *str2[3] = {NULL, NULL, NULL};
    int i = my_ptrlen(str);
    cr_assert_eq(i, 2);
    i = my_ptrlen(str2);
    cr_assert_eq(i, 0);
}