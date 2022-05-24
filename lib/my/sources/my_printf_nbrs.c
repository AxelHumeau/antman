/*
** EPITECH PROJECT, 2021
** printf
** File description:
** conversion specifiers
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

static long long sized_int(int long_count, va_list ap)
{
    switch (long_count) {
    case -2:
        return (signed char) va_arg(ap, int);
    case -1:
        return (short) va_arg(ap, int);
    case 0:
        return va_arg(ap, int);
    case 1:
        return va_arg(ap, long int);
    case 2:
        return va_arg(ap, long long int);
    case LONG_COUNT_INTMAX:
        return va_arg(ap, intmax_t);
    case LONG_COUNT_SIZE_T:
        return va_arg(ap, ssize_t);
    case LONG_COUNT_PTRDIFF:
        return va_arg(ap, ptrdiff_t);
    default:
        return 0;
    }
}

int real_precision(struct printf_format *state, int def, int width_prec_diff)
{
    if (state->number_destination == NUMBER_DEST_PRECISION) {
        if (state->padding_style == PADDING_ZEROS) {
            state->padding_style = PADDING_RIGHT_ALIGN;
        }
        return state->number_precision;
    } else if (state->padding_style == PADDING_ZEROS) {
        return state->number_width - width_prec_diff;
    } else {
        return def;
    }
}

int mpff_int(char format, va_list ap, struct printf_format *state)
{
    long long i = sized_int(state->long_count, ap);
    int size = 0;
    int pad_pos = i >= 0 && state->pad_positive != 0;
    int precision = real_precision(state, 1, pad_pos || i < 0);
    int nbrlen = my_putnbr_advanced(i, "0123456789", precision, false);

    size += pad(state, PADDING_RIGHT_ALIGN, pad_pos + nbrlen);
    if (pad_pos) {
        my_putchar(state->pad_positive);
        size++;
    }
    size += my_putnbr_advanced(i, "0123456789", precision, true);
    size += pad(state, PADDING_LEFT_ALIGN, size);
    state->terminated = true;
    return size;
}
