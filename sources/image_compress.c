/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-axel.humeau
** File description:
** image_compress
*/

#include "antman.h"
#include "my.h"

#include <unistd.h>

bool is_valid_number(char *buf, int line_size)
{
    int nbr;

    if (line_size <= 0)
        return 0;
    for (int i = 0; i < line_size; i++) {
        if (!(buf[i] >= '0' && buf[i] <= '9'))
            return 0;
    }
    nbr = my_getnbr(buf);
    if (nbr <= 255)
        return 1;
    else
        return 0;
}

int find_line_size(char *buf, int buf_size)
{
    int line_size = 0;

    while (line_size < buf_size && buf[line_size] != '\n')
        line_size++;
    return line_size;
}

void write_image_compressed(char *buf, int size)
{
    int offset = 0;

    while (offset < size) {
        offset += write_uncompressed_block(buf + offset, size - offset);
        if (offset < size)
            offset += write_compressed_block(buf + offset, size - offset);
        if (offset < size)
            offset += write_xs_compressed_block(buf + offset, size - offset);
    }
}
