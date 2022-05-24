/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-axel.humeau
** File description:
** unit_tests
*/

#include "antman_common.h"

#include <criterion/criterion.h>

Test(file_size, size)
{
    cr_assert_eq(file_size("tests/file.txt"), 27);
}

Test(read_file, invalid_file)
{
    cr_assert_eq(read_file("poney", 6), NULL);
}

Test(read_file, invalid_file2)
{
    cr_assert_eq(file_size("tests"), -1);
}

Test(read_file, invalid_file3)
{
    cr_assert_eq(file_size("poney"), -1);
}

Test(read_file, test_buffer)
{
    char file_contents[27] = "ORIGINAL UNCOMPRESSED DATA\n";

    cr_assert_arr_eq(read_file("tests/file.txt", 27), file_contents, 27);
}

Test(read_file, directory)
{
    cr_assert_null(read_file("tests", 3));
}
