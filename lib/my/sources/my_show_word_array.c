/*
** EPITECH PROJECT, 2021
** concat_params
** File description:
** Concat string array
*/

#include <stdlib.h>

int my_putstr(char const *src);
void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
