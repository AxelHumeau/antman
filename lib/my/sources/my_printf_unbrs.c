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

static unsigned long long sized_uint(int long_count, va_list ap)
{
    switch (long_count) {
    case -2:
        return (unsigned char) va_arg(ap, int);
    case -1:
        return (unsigned short) va_arg(ap, int);
    case 0:
        return va_arg(ap, unsigned int);
    case 1:
        return va_arg(ap, unsigned long int);
    case 2:
        return va_arg(ap, unsigned long long int);
    case LONG_COUNT_INTMAX:
        return va_arg(ap, uintmax_t);
    case LONG_COUNT_SIZE_T:
        return va_arg(ap, size_t);
    case LONG_COUNT_PTR:
        return (unsigned long long) va_arg(ap, void *);
    default:
        return 0;
    }
}

int mpff_uint(char format, va_list ap, struct printf_format *state)
{
    unsigned long long i = sized_uint(state->long_count, ap);
    int size = 0;
    int precision = real_precision(state, 1, 0);
    int nbrlen = my_putunbr_adv(i, "0123456789", precision, false);

    size += pad(state, PADDING_RIGHT_ALIGN, nbrlen);
    size += my_putunbr_adv(i, "0123456789", precision, true);
    size += pad(state, PADDING_LEFT_ALIGN, nbrlen);
    state->terminated = true;
    return size;
}

int mpff_oct(char format, va_list ap, struct printf_format *state)
{
    unsigned long long i = sized_uint(state->long_count, ap);
    int size = 0;
    int precision = real_precision(state, 1, 0) - state->alternate_form;
    int nbrlen = my_putunbr_adv(i, "01234567", precision, false);

    size += pad(state, PADDING_RIGHT_ALIGN, nbrlen + state->alternate_form);
    if (state->alternate_form) {
        my_putchar('0');
        size++;
    }
    size += my_putunbr_adv(i, "01234567", precision, true);
    size += pad(state, PADDING_LEFT_ALIGN, size);
    state->terminated = true;
    return size;
}

int mpff_hex(char format, va_list ap, struct printf_format *state)
{
    unsigned long long i = sized_uint(state->long_count, ap);
    char *base = format == 'b' ? "01" :
        format == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
    int size = 0;
    int precision = real_precision(state, 1, 0);
    int nbrlen = my_putunbr_adv(i, base, precision, false);
    bool alt = state->alternate_form && i != 0;

    size += pad(state, PADDING_RIGHT_ALIGN, nbrlen + 2 * alt);
    if (alt) {
        my_putchar('0');
        my_putchar(format);
        size += 2;
    }
    size += my_putunbr_adv(i, base, precision, true);
    size += pad(state, PADDING_LEFT_ALIGN, size);
    state->terminated = true;
    return size;
}
