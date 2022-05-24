/*
** EPITECH PROJECT, 2021
** Task 18 - my_putnbr_base
** File description:
** Prints a number in given base
*/

#include <stdbool.h>
#include "my.h"

static int uint_nbrlen(unsigned long long n, int base)
{
    unsigned long long prev = 0;
    unsigned long long magnitude = 1;
    int len = 0;

    while (n >= magnitude && magnitude > prev) {
        prev = magnitude;
        magnitude *= base;
        len++;
    }
    return len;
}

int my_putunbr_adv(unsigned long long nbr, char const *base,
                    int precision, bool print)
{
    int nbrlen = uint_nbrlen(nbr, my_strlen(base));
    int size = 0;

    if (print)
        my_putnchar('0', precision - nbrlen);
    size += precision - nbrlen < 0 ? 0 : precision - nbrlen;
    if (nbr != 0) {
        size += nbrlen;
        if (print)
            my_putnbr_base_unsigned(nbr, base);
    }
    return size;
}

int my_putnbr_advanced(long long nbr, char const *base,
                        int precision, bool print)
{
    unsigned long long uint;
    int nbrlen;
    int size = 0;

    if (nbr < 0) {
        if (print)
            my_putchar('-');
        size++;
        uint = -((unsigned long long) nbr);
    } else
        uint = nbr;
    nbrlen = uint_nbrlen(uint, my_strlen(base));
    my_putnchar('0', print ? precision - nbrlen : 0);
    size += precision - nbrlen < 0 ? 0 : precision - nbrlen;
    if (nbr != 0) {
        size += nbrlen;
        if (print)
            my_putnbr_base_unsigned(uint, base);
    }
    return size;
}
