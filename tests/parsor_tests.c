/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** parsor_tests
*/

#include <criterion/criterion.h>
#include "my_ls.h"

Test(flag_parsor_test, first_test)
{
    char *src[6] = {"-ll", "-t", "sddfs", "-u", "aaaa", NULL};
    char *flags = parsor(src);
    cr_assert_arr_eq(flags, "lltu", 0);
}