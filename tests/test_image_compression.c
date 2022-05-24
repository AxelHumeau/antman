/*
** EPITECH PROJECT, 2022
** antman
** File description:
** test image compression
*/

#include "antman.h"
#include "antman_common.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void flush_buffer()
{
}

Test(image_write_compressed_block, xs_able, .init = cr_redirect_stdout)
{
    char buf[] = "120\n120\n120\n120\n118\n";

    cr_assert_eq(write_compressed_block(buf, sizeof(buf) - 1), 0);
}

Test(image_write_compressed_block, not_compressible, .init = cr_redirect_stdout)
{
    char buf[] = "# this can't be compressed\n";

    cr_assert_eq(write_compressed_block(buf, sizeof(buf) - 1), 0);
}

/* Test(image_write_compressed_block, no_newline, .init = cr_redirect_stdout) */
/* { */
/*     char buf[] = "80"; */

/*     cr_assert_eq(write_compressed_block(buf, sizeof(buf) - 1), 0); */
/* } */

Test(image_write_compressed_block, too_big, .init = cr_redirect_stdout)
{
    char buf[] = "1024\n128\n";

    cr_assert_eq(write_compressed_block(buf, sizeof(buf) - 1), 0);
}

Test(image_write_compressed_block, little_too_big, .init = cr_redirect_stdout)
{
    char buf[] = "256\n128\n";

    cr_assert_eq(write_compressed_block(buf, sizeof(buf) - 1), 0);
}

Test(image_write_compressed_block, negative, .init = cr_redirect_stdout)
{
    char buf[] = "-1\n128\n";

    cr_assert_eq(write_compressed_block(buf, sizeof(buf) - 1), 0);
}

Test(image_write_compressed_block, empty_line, .init = cr_redirect_stdout)
{
    char buf[] = "\n128\n";

    cr_assert_eq(write_compressed_block(buf, sizeof(buf) - 1), 0);
}

Test(image_write_compressed_block, normal, .init = cr_redirect_stdout)
{
    char buf[] = "200\n128\n255\n69\n42\n10\n";
    char expect[] = { 0x86, 200, 128, 255, 69, 42, 10 };

    cr_assert_eq(write_compressed_block(buf, sizeof(buf) - 1), sizeof(buf) - 1);
    cr_assert_stdout_eq_str(expect);
}

Test(image_write_compressed_block, would_overflow, .init = cr_redirect_stdout)
{
    char buf[3 * 128];
    char expect[129];

    expect[0] = (char) 255;
    for (int i = 0; i < 128; i++) {
        buf[3 * i + 0] = i % 2 ? '1' : '2';
        buf[3 * i + 1] = '5';
        buf[3 * i + 2] = '\n';
        expect[i + 1] = i % 2 ? 15 : 25;
    }
    expect[128] = '\0';
    cr_assert_eq(write_compressed_block(buf, 3 * 128), 3 * 127);
    cr_assert_stdout_eq_str(expect);
}

Test(image_write_uncompressed_block, comment, .init = cr_redirect_stdout)
{
    char buf[] = "# this can't be compressed\n";

    cr_assert_eq(write_uncompressed_block(buf, sizeof(buf) - 1), sizeof(buf) - 1);
    cr_assert_stdout_eq_str("\x1B# this can't be compressed\n");
}

Test(image_write_uncompressed_block, compressible, .init = cr_redirect_stdout)
{
    char buf[] = "128\n80\n";

    cr_assert_eq(write_uncompressed_block(buf, sizeof(buf) - 1), 0);
}

Test(image_write_uncompressed_block, would_overflow, .init = cr_redirect_stdout)
{
    char buf[129];
    char expect[129];

    expect[0] = (char) 127;
    for (int i = 0; i < 128; i++) {
        buf[i] = 'a';
        expect[i + 1] = 'a';
    }
    expect[128] = '\0';
    cr_assert_eq(write_uncompressed_block(buf, 128), 127);
    cr_assert_stdout_eq_str(expect);
}

Test(image_write_xs_compressed_block, happiness, .init = cr_redirect_stdout)
{
    char buf[] = "120\n120\n120\n120\n118\n";
    char expect[] = { 128, 4, 120, 0 };

    cr_assert_eq(write_xs_compressed_block(buf, sizeof(buf) - 1), 16);
    cr_assert_stdout_eq_str(expect);
}

Test(image_write_xs_compressed_block, not_enough, .init = cr_redirect_stdout)
{
    char buf[] = "200\n128\n255\n69\n42\n10\n";

    cr_assert_eq(write_xs_compressed_block(buf, sizeof(buf) - 1), 0);
}

Test(image_write_xs_compressed_block, not_compressible, .init = cr_redirect_stdout)
{
    char buf[] = "# this can't be compressed\n";

    cr_assert_eq(write_xs_compressed_block(buf, sizeof(buf) - 1), 0);
}

Test(image_write_xs_compressed_block, would_overflow, .init = cr_redirect_stdout)
{
    char buf[3 * 257];
    char expect[] = {128, 255, 25, 0};

    for (int i = 0; i < 257; i++) {
        buf[3 * i + 0] = '2';
        buf[3 * i + 1] = '5';
        buf[3 * i + 2] = '\n';
    }
    cr_assert_eq(write_xs_compressed_block(buf, 3 * 257), 3 * 255);
    cr_assert_stdout_eq_str(expect);
}

Test(write_image_compressed, synthetic, .init = cr_redirect_stdout)
{
    char buf[] = "#comment\n1\n1\n1\n1\n1\n255\n";

    write_image_compressed(buf, sizeof(buf) - 1);
}

Test(write_image_compressed, synthetic_all_same, .init = cr_redirect_stdout)
{
    char buf[] = "#comment\n1\n1\n1\n1\n1\n";

    write_image_compressed(buf, sizeof(buf) - 1);
}

Test(write_image_compressed, synthetic_not_compressible, .init = cr_redirect_stdout)
{
    char buf[] = "#comment\n#another one\n";

    write_image_compressed(buf, sizeof(buf) - 1);
}
