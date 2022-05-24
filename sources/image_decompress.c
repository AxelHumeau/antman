/*
** EPITECH PROJECT, 2022
** antman
** File description:
** decompress PPM images
*/

#include "giantman.h"
#include "my.h"

#include <stdbool.h>
#include <unistd.h>

static void handle_xs_compressed_block(unsigned char *buf, int *offset)
{
    buf += *offset;
    for (int i = buf[0]; i > 0; i--) {
        my_put_nbr(buf[1]);
        my_putchar('\n');
    }
    *offset += 2;
}

static void handle_compressed_block(unsigned char *buf, int size, int *offset)
{
    buf += *offset;
    for (int i = 0; i < size; i++) {
        my_put_nbr(buf[i]);
        my_putchar('\n');
    }
    *offset += size;
}

static void handle_uncompressed_block(unsigned char *buf, int size,
    int *offset)
{
    flush_buffer();
    write(1, buf + (*offset), size);
    *offset += size;
}

static void handle_block(unsigned char *buf, int *offset)
{
    unsigned char head = buf[*offset];
    bool compressed = head & 128;
    int size = head & 127;

    (*offset)++;
    if (compressed) {
        if (size == 0)
            handle_xs_compressed_block(buf, offset);
        else
            handle_compressed_block(buf, size, offset);
    } else {
        handle_uncompressed_block(buf, size, offset);
    }
}

void write_image_decompressed(char *buf, int len)
{
    int offset = 0;

    while (offset < len) {
        handle_block((unsigned char *) buf, &offset);
    }
}
