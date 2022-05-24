/*
** EPITECH PROJECT, 2021
** printf
** File description:
** conversion specifiers
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

int mpff_percent(char format, va_list ap, struct printf_format *state)
{
    my_putchar('%');
    state->terminated = true;
    return 1;
}

int mpff_pointer(char format, va_list ap, struct printf_format *state)
{
    state->alternate_form = true;
    state->long_count = LONG_COUNT_PTR;
    return mpff_hex('x', ap, state);
}
