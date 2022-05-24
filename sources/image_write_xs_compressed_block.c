/*
** EPITECH PROJECT, 2022
** antman
** File description:
** write extra compressed blocks
*/

#include "antman.h"
#include "my.h"

#include <unistd.h>

static void dump_xs_compressed_block(int count, char byte)
{
    my_putchar((char) 128);
    my_putchar(count);
    my_putchar(byte);
}

int write_xs_compressed_block(char *buf, int buf_size)
{
    int buf_progress = 0;
    int tmp_line_size = find_line_size(buf, buf_size);
    int count = 0;
    char byte;
    char tmp_byte;

    while (is_valid_number(buf + buf_progress, tmp_line_size) && count < 255) {
        tmp_byte = my_getnbr(buf + buf_progress);
        if (count > 0 && tmp_byte != byte)
            break;
        buf_progress += tmp_line_size + 1;
        tmp_line_size = find_line_size(buf + buf_progress,
            buf_size - buf_progress);
        byte = tmp_byte;
        count++;
    }
    if (count < 3)
        return 0;
    dump_xs_compressed_block(count, byte);
    return buf_progress;
}
