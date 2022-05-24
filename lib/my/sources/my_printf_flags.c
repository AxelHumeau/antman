/*
** EPITECH PROJECT, 2021
** printf
** File description:
** length specifiers
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

int mpff_alt(char format, va_list ap, struct printf_format *state)
{
    state->alternate_form = true;
    return 0;
}

int mpff_space(char format, va_list ap, struct printf_format *state)
{
    if (state->pad_positive == 0)
        state->pad_positive = ' ';
    return 0;
}

int mpff_plus(char format, va_list ap, struct printf_format *state)
{
    state->pad_positive = '+';
    return 0;
}
