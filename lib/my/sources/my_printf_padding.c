/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Padding flags
*/

#include "my_printf.h"

int mpff_dot(char format, va_list ap, struct printf_format *state)
{
    state->number_destination = NUMBER_DEST_PRECISION;
    return 0;
}

int mpff_left(char format, va_list ap, struct printf_format *state)
{
    state->padding_style = PADDING_LEFT_ALIGN;
    return 0;
}

int mpff_zero(char format, va_list ap, struct printf_format *state)
{
    if (state->number_destination == NUMBER_DEST_UNKNOWN) {
        if (state->padding_style == PADDING_RIGHT_ALIGN)
            state->padding_style = PADDING_ZEROS;
    } else {
        mpff_digit(format, ap, state);
    }
    return 0;
}

int mpff_digit(char format, va_list ap, struct printf_format *state)
{
    int *dest;

    if (state->number_destination == NUMBER_DEST_PRECISION)
        dest = &state->number_precision;
    else
        dest = &state->number_width;
    *dest = (*dest * 10) + (format - '0');
    if (state->number_destination == NUMBER_DEST_UNKNOWN)
        state->number_destination = NUMBER_DEST_WIDTH;
    return 0;
}

int mpff_asterisk(char format, va_list ap, struct printf_format *state)
{
    int *dest;

    if (state->number_destination == NUMBER_DEST_PRECISION)
        dest = &state->number_precision;
    else
        dest = &state->number_width;
    *dest = va_arg(ap, int);
    if (state->number_destination == NUMBER_DEST_UNKNOWN)
        state->number_destination = NUMBER_DEST_WIDTH;
    if (*dest < 0) {
        if (state->number_destination == NUMBER_DEST_PRECISION) {
            *dest = 0;
            state->number_destination = NUMBER_DEST_WIDTH;
        } else {
            state->padding_style = PADDING_LEFT_ALIGN;
            *dest = -(*dest);
        }
    }
    return 0;
}
