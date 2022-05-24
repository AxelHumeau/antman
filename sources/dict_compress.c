/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress
*/

#include "antman_common.h"
#include "antman.h"
#include "my.h"

#include <stdlib.h>
#include <unistd.h>

static int find_index_in_dict(char c, char *dict)
{
    for (int i = 0; i < 56; i++) {
        if (dict[i] == c)
            return i;
    }
    return -1;
}

static int append_byte(unsigned int *current, unsigned char c, int index)
{
    switch (index) {
    case 0 ... 7:
        *current = (*current << 5) | index;
        return 5;
    case 8 ... 23:
        *current = (*current << 6) | ((index - 8) | (0b01 << 4));
        return 6;
    case 24 ... 55:
        *current = (*current << 7) | ((index - 24) | (0b10 << 5));
        return 7;
    default:
        *current = (*current << 10) | (c | (0b11 << 8));
        return 10;
    }
}

void write_compressed(char *buf, int len)
{
    int index;
    unsigned int current = 0;
    int shift = 0;
    char *dict = find_occurrences(buf, len);

    write(1, dict, 56);
    for (int i = 0; i < len; i++) {
        index = find_index_in_dict(buf[i], dict);
        shift += append_byte(&current, buf[i], index);
        while (shift >= 8) {
            shift -= 8;
            my_putchar(current >> shift);
        }
    }
    free(dict);
    if (shift >= 0)
        my_putchar((current << (8 - shift)) | ((1 << (8 - shift)) - 1));
}
