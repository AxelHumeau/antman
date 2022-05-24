/*
** EPITECH PROJECT, 2022
** Solo Stumper 1
** File description:
** find_occurrences
*/

#include "my.h"
#include "antman.h"

#include <stdlib.h>

char *find_occurrences(char *str, int size)
{
    int *dict = malloc(sizeof(int) * 256);

    my_memset((char *) dict, 0, sizeof(int) * 256);
    for (int i = 0; i < size; i++)
        dict[(int) (unsigned char) str[i]] += 1;
    return sort_dict(dict);
}
