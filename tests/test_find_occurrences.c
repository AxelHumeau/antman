/*
** EPITECH PROJECT, 2022
** antman
** File description:
** tests
*/

#include "antman.h"

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(find_occurrences, normal)
{
    char *dict = find_occurrences("AHA!", 4);
    char expect[] = "A!H";

    cr_assert_arr_eq(dict, expect, 3);
}

Test(find_occurrences, empty)
{
    find_occurrences("", 0);
}

Test(find_occurrences, unicode)
{
    char *dict = find_occurrences("\xff\xf8\x38\xa0\xff\xff\xff\x38", 8);

    cr_assert_arr_eq(dict, "\xff\x38\xa0\xf8", 4);
}
