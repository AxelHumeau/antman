/*
** EPITECH PROJECT, 2022
** antman
** File description:
** main
*/

#include "my.h"
#include "giantman.h"

#include <unistd.h>
#include <stdlib.h>

static int check_file_type(int file_type, int size, char *content)
{
    switch (file_type) {
    case 1:
        write_decompressed(content, size);
        break;
    case 2:
        write_decompressed(content, size);
        break;
    case 3:
        write_image_decompressed(content, size);
        break;
    default:
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int size;
    char *content;

    if (argc != 3)
        return 84;
    size = file_size(argv[1]);
    if (size < 0)
        return 84;
    content = read_file(argv[1], size);
    if (content == NULL)
        return 84;
    if (check_file_type(my_getnbr(argv[2]), size, content))
        return 84;
    free(content);
    flush_buffer();
}
