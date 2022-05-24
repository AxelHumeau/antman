/*
** EPITECH PROJECT, 2021
** Task 18 - my_putnbr_base
** File description:
** Prints a number in given base
*/

#include "my.h"

static unsigned long long find_magnitude(unsigned long long n, int base)
{
    unsigned long long magnitude = 1;
    unsigned long long prev = 0;

    while (n >= magnitude && magnitude > prev) {
        prev = magnitude;
        magnitude *= base;
    }
    return prev;
}

int my_putnbr_base_unsigned(unsigned long long n, char const *base)
{
    int baselen = my_strlen(base);
    unsigned long long magnitude = find_magnitude(n, baselen);
    int digit;
    int size = 0;

    if (n == 0) {
        my_putchar(base[0]);
        return 1;
    }
    while (magnitude >= 1) {
        digit = (n / magnitude) % baselen;
        my_putchar(base[digit]);
        size++;
        magnitude /= baselen;
    }
    return size;
}

int my_putnbr_base(long long nbr, char const *base)
{
    if (nbr < 0) {
        my_putchar('-');
        return 1 + my_putnbr_base_unsigned(-((unsigned long long) nbr), base);
    } else {
        return my_putnbr_base_unsigned(nbr, base);
    }
}
