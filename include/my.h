/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** Header for libmy
*/

#pragma once

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putnchar(char c, int n);

int my_strlen(char const *str);
int my_isneg(int nb);

int my_starts_with(char *str, char const *to_find);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);

void my_memset(char *into, char c, int n);

char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);

void my_swap(int *a, int *b);

char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);

int my_getnbr(char const *str);

int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);

int my_showstr(char const *str);
int my_showmem(char const *str, int size);

char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);

int my_getnbr_base(char const *str, char const *base);
int my_putnbr_base(long long nbr, char const *base);
int my_putnbr_base_unsigned(unsigned long long nbr, char const *base);
int my_putnbr_advanced(long long nbr, char const *base,
                        int precision, _Bool print);
int my_putunbr_adv(unsigned long long nbr, char const *base,
                    int precision, _Bool print);

int my_char_is_lower(char c);
int my_char_is_upper(char c);

/** Increase capacity of `buf` (of initial size `count`) by 1024,
*   removing `offset` chars */
void increase_buffer_capacity(char **buf, int offset, int count);

/** Reads from `fd`, calling `f` for each line (\n not included) */
void my_readlines(int fd, void *data, void (*f)(void *data, char *line));

int my_printf(char const *format, ...) __attribute__ ((format(printf, 1, 2)));
