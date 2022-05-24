/*
** EPITECH PROJECT, 2022
** antman
** File description:
** buffering
*/

#include "my.h"
#include "buffering.h"

#include <unistd.h>

static struct buffer *get_buffer_loc(void)
{
    static struct buffer buffer;

    return &buffer;
}

void flush_buffer(void)
{
    struct buffer *buf = get_buffer_loc();

    write(1, buf->buffer, buf->pos);
    buf->pos = 0;
}

void my_putchar(char c)
{
    struct buffer *buf = get_buffer_loc();

    buf->buffer[buf->pos++] = c;
    if (buf->pos == 8192)
        flush_buffer();
}
