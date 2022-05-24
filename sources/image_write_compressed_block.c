/*
** EPITECH PROJECT, 2022
** antman
** File description:
** write compressed blocks
*/

#include "antman.h"
#include "my.h"

#include <unistd.h>

static bool handle_byte(char *buf, unsigned char *arr,
    int *repeat_count)
{
    arr[0] = my_getnbr(buf);
    if (*repeat_count == -1 || arr[-1] != arr[0]) {
        *repeat_count = 0;
    } else if (*repeat_count >= 2) {
        return true;
    } else {
        (*repeat_count)++;
    }
    return false;
}

static void dump_compressed_block(unsigned char *arr, int size)
{
    my_putchar(size + 128);
    flush_buffer();
    write(1, arr, size);
}

int write_compressed_block(char *buf, int buf_size)
{
    int size = 0;
    int buf_progress = 0;
    unsigned char arr[127];
    unsigned char linelens[127];
    int repeat_count = -1;

    linelens[0] = find_line_size(buf, buf_size) + 1;
    while (is_valid_number(buf + buf_progress, linelens[size] - 1)
            && size < 127) {
        if (handle_byte(buf + buf_progress, arr + size, &repeat_count))
            break;
        buf_progress += linelens[size++];
        linelens[size] = find_line_size(buf + buf_progress,
            buf_size - buf_progress) + 1;
    }
    size -= repeat_count == 0 ? 0 : repeat_count + 1;
    if (size)
        dump_compressed_block(arr, size);
    for (buf_progress = 0; size > 0; buf_progress += linelens[--size]);
    return buf_progress;
}
