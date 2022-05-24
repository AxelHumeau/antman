/*
** EPITECH PROJECT, 2022
** antman
** File description:
** write uncompressed image blocks
*/

#include "antman.h"
#include "my.h"

#include <unistd.h>

int write_uncompressed_block(char *buf, int buf_size)
{
    int size = 0;
    int tmp_line_size = find_line_size(buf, buf_size);

    while (!is_valid_number(buf + size, tmp_line_size) && size < buf_size) {
        size += tmp_line_size + 1;
        tmp_line_size = find_line_size(buf + size, buf_size - size);
        if (size > 127) {
            size = 127;
            break;
        }
    }
    if (size >= buf_size)
        size = buf_size;
    if (size) {
        my_putchar(size);
        flush_buffer();
        write(1, buf, size);
    }
    return size;
}
