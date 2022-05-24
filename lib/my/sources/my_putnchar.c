/*
** EPITECH PROJECT, 2021
** my_put_nchar.c
** File description:
** Put one char n times
*/

#include "my.h"

void my_putnchar(char c, int n)
{
    while (n > 0) {
        my_putchar(c);
        n--;
    }
}
