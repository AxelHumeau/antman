/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-axel.humeau
** File description:
** sort_dict
*/

#include "my.h"
#include "antman.h"

#include <stdlib.h>

static int index_of_max(int *dict)
{
    int index_of_max = 0;

    for (int i = 0; i < 256; i++) {
        if (dict[index_of_max] < dict[i])
            index_of_max = i;
    }
    return index_of_max;
}

char *sort_dict(int *dict)
{
    char *dict_result = malloc(sizeof(char) * 56);
    int i;

    for (int n = 0; n < 56; n++) {
        i = index_of_max(dict);
        dict[i] = 0;
        dict_result[n] = (unsigned char) i;
    }
    free(dict);
    return dict_result;
}
