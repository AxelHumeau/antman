/*
** EPITECH PROJECT, 2022
** antman
** File description:
** decompress
*/

#include "giantman.h"
#include "my.h"

#include <stdbool.h>

static void consume_char(unsigned int current, int *shift, bool not_at_end,
    char *dict)
{
    int index;
    char category;
    int read_count;

    while (*shift >= 5 + 5 * not_at_end) {
        *shift -= 2;
        category = (current >> *shift) & 0b11;
        read_count = category == 0b11 ? 8 : 3 + category;
        *shift -= read_count;
        index = (current >> *shift) & ((1 << read_count) - 1);
        if (*shift < 0)
            return;
        if (category == 0b11) {
            my_putchar(index);
        } else {
            index += (category == 2 ? 3 : category) * 8;
            my_putchar(dict[index]);
        }
    }
}

void write_decompressed(char *buf, int len)
{
    unsigned int current = 0;
    int shift = 0;

    for (int i = 56; i < len; i++) {
        current = (current << 8) | (unsigned char) (buf[i]);
        shift += 8;
        consume_char(current, &shift, true, buf);
    }
    consume_char(current, &shift, false, buf);
}
