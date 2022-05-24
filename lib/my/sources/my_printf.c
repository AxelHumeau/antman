/*
** EPITECH PROJECT, 2021
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int consume_format(char const **format, va_list ap)
{
    struct printf_format state = {0};
    int size = 0;
    mpff_t f;

    if (**format < 32) {
        return 0;
    }
    while (!state.terminated) {
        f = MPFF_TABLE[**format - 0x20];
        if (f != 0) {
            size += f(**format, ap, &state);
        } else {
            my_putchar('%');
            size++;
            break;
        }
        (*format)++;
    }
    return size;
}

int my_printf(char const *format, ...)
{
    va_list ap;
    int size = 0;

    va_start(ap, format);
    while (*format != 0) {
        if (*format++ == '%') {
            size += consume_format(&format, ap);
        } else {
            my_putchar(format[-1]);
            size++;
        }
    }
    va_end(ap);
    return size;
}
