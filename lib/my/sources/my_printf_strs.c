/*
** EPITECH PROJECT, 2021
** printf
** File description:
** conversion specifiers
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

int mpff_str(char format, va_list ap, struct printf_format *state)
{
    char *str = va_arg(ap, char *);
    int precision = real_precision(state, -1, 0);
    int i = 0;
    int size = 0;

    ignore_zero(state);
    if (state->padding_style == PADDING_RIGHT_ALIGN) {
        while ((precision == -1 || i < precision) && str[i] != 0) {
            i++;
        }
        size += pad(state, PADDING_RIGHT_ALIGN, i);
        i = 0;
    }
    while ((precision == -1 || i < precision) && str[i] != 0) {
        my_putchar(str[i]);
        i++;
    }
    size += pad(state, PADDING_LEFT_ALIGN, i);
    return size + i;
}

int mpff_char(char format, va_list ap, struct printf_format *state)
{
    char c = (char) va_arg(ap, int);
    int size = 1;

    ignore_zero(state);
    size += pad(state, PADDING_RIGHT_ALIGN, 1);
    my_putchar(c);
    size += pad(state, PADDING_LEFT_ALIGN, 1);
    return size;
}

static int do_dumpchar(unsigned char c, int max)
{
    if (c < 32 || c >= 127) {
        if (max >= 4) {
            my_putchar('\\');
            my_putnbr_advanced(c, "01234567", 3, true);
        }
        return 4;
    } else {
        my_putchar(c);
        return 1;
    }
}

int mpff_dumpstr(char format, va_list ap, struct printf_format *state)
{
    char *str = va_arg(ap, char *);
    int size = 0;
    int i = 0;
    int precision = real_precision(state, -1, 0);

    ignore_zero(state);
    if (state->padding_style == PADDING_RIGHT_ALIGN) {
        while ((precision == -1 || size < precision) && str[i] != 0) {
            size += (str[i] < 32 || str[i] >= 127) ? 4 : 1;
            i++;
        }
        size -= (precision >= 0 && size > precision ? 4 : 0);
        size = pad(state, PADDING_RIGHT_ALIGN, size);
    }
    for (i = 0; (precision == -1 || size < precision) && str[i] != 0; i++) {
        size += do_dumpchar(str[i], precision == -1 ? 4 : precision - size);
    }
    size -= (precision >= 0 && size > precision ? 4 : 0) ;
    size += pad(state, PADDING_LEFT_ALIGN, size);
    return size;
}
