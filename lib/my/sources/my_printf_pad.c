/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** pad
*/

#include "my.h"
#include "my_printf.h"

void ignore_zero(struct printf_format *state)
{
    state->terminated = true;
    if (state->padding_style == PADDING_ZEROS)
        state->padding_style = PADDING_RIGHT_ALIGN;
}

int pad(struct printf_format *state, int style, int size)
{
    int n = state->number_width - size;

    if (style != state->padding_style || n < 0)
        return 0;
    my_putnchar(' ', n);
    return n;
}
