/*
** EPITECH PROJECT, 2021
** printf
** File description:
** length specifiers
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

int mpff_long(char format, va_list ap, struct printf_format *state)
{
    state->long_count++;
    return 0;
}

int mpff_half(char format, va_list ap, struct printf_format *state)
{
    state->long_count--;
    return 0;
}

int mpff_intmax(char format, va_list ap, struct printf_format *state)
{
    state->long_count = LONG_COUNT_INTMAX;
    return 0;
}

int mpff_size(char format, va_list ap, struct printf_format *state)
{
    state->long_count = LONG_COUNT_SIZE_T;
    return 0;
}

int mpff_ptrdiff(char format, va_list ap, struct printf_format *state)
{
    state->long_count = LONG_COUNT_PTRDIFF;
    return 0;
}
