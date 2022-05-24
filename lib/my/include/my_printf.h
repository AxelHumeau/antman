/*
** EPITECH PROJECT, 2021
** printf
** File description:
** printf header
*/

#pragma once

#include <stdbool.h>
#include <stdarg.h>

#define LONG_COUNT_INTMAX 1000
#define LONG_COUNT_SIZE_T 2000
#define LONG_COUNT_PTRDIFF 3000
#define LONG_COUNT_PTR 4000

#define NUMBER_DEST_UNKNOWN 0
#define NUMBER_DEST_WIDTH 1
#define NUMBER_DEST_PRECISION 2

#define PADDING_RIGHT_ALIGN 0
#define PADDING_LEFT_ALIGN 1
#define PADDING_ZEROS 2

struct printf_format {
    /** true if the % sequence is terminated */
    bool terminated;
    /** number of l flags (negative for h flags) */
    int long_count;
    /** true for # flag (prepend 0x or 0) */
    bool alternate_form;
    /** the character to add before positive numbers (\0 for none) */
    char pad_positive;
    /** Where we're writing numbers: NUMBER_DEST_* macros */
    int number_destination;
    /** The minimum width of the output */
    int number_width;
    /** The precision of the output */
    int number_precision;
    /** One of the PADDING_* macros */
    int padding_style;
};

/** Returns the precision from a struct, or def by default
* width_prec_diff: the difference between width and precision (1 for neg) */
int real_precision(struct printf_format *state, int def, int width_prec_diff);
int pad(struct printf_format *state, int style, int size);
void ignore_zero(struct printf_format *state);

typedef int (*mpff_t)(char, va_list, struct printf_format *);

int mpff_str(char format, va_list ap, struct printf_format *state);
int mpff_char(char format, va_list ap, struct printf_format *state);
int mpff_pointer(char format, va_list ap, struct printf_format *state);
int mpff_dumpstr(char format, va_list ap, struct printf_format *state);

int mpff_percent(char format, va_list ap, struct printf_format *state);

int mpff_int(char format, va_list ap, struct printf_format *state);
int mpff_uint(char format, va_list ap, struct printf_format *state);
int mpff_oct(char format, va_list ap, struct printf_format *state);
int mpff_hex(char format, va_list ap, struct printf_format *state);

int mpff_half(char format, va_list ap, struct printf_format *state);
int mpff_long(char format, va_list ap, struct printf_format *state);
int mpff_intmax(char format, va_list ap, struct printf_format *state);
int mpff_size(char format, va_list ap, struct printf_format *state);
int mpff_ptrdiff(char format, va_list ap, struct printf_format *state);

int mpff_alt(char format, va_list ap, struct printf_format *state);
int mpff_left(char format, va_list ap, struct printf_format *state);
int mpff_space(char format, va_list ap, struct printf_format *state);
int mpff_plus(char format, va_list ap, struct printf_format *state);

int mpff_dot(char format, va_list ap, struct printf_format *state);
int mpff_zero(char format, va_list ap, struct printf_format *state);
int mpff_digit(char format, va_list ap, struct printf_format *state);
int mpff_asterisk(char format, va_list ap, struct printf_format *state);

/** Starts at 040 (SPACE) */
static const mpff_t MPFF_TABLE[] = {
    /* 040 */ &mpff_space, 0, 0, &mpff_alt, 0, &mpff_percent, 0, 0,
    /* 050 */ 0, 0, &mpff_asterisk, &mpff_plus, 0, &mpff_left, &mpff_dot, 0,
    /* 060 */ &mpff_zero, &mpff_digit, &mpff_digit, &mpff_digit,
            &mpff_digit, &mpff_digit, &mpff_digit, &mpff_digit,
    /* 070 */ &mpff_digit, &mpff_digit, 0, 0, 0, 0, 0, 0,
    /* 100 */ 0, 0, 0, 0, 0, 0, 0, 0,
    /* 110 */ 0, 0, 0, 0, 0, 0, 0, 0,
    /* 120 */ 0, 0, 0, &mpff_dumpstr, 0, 0, 0, 0,
    /* 130 */ &mpff_hex, 0, &mpff_size, 0, 0, 0, 0, 0,
    /* 140 */ 0, 0, &mpff_hex, &mpff_char, &mpff_int, 0, 0, 0,
    /* 150 */ &mpff_half, &mpff_int, &mpff_intmax, 0,
            &mpff_long, 0, 0, &mpff_oct,
    /* 160 */ &mpff_pointer, 0, 0, &mpff_str, &mpff_ptrdiff, &mpff_uint, 0, 0,
    /* 170 */ &mpff_hex, 0, &mpff_size, 0, 0, 0, 0, 0
};
