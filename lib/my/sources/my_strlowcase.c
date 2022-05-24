/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** String to uppercase
*/

int my_char_is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

char *my_strlowcase(char *str)
{
    if (my_char_is_upper(*str)) {
        *str = *str - 'A' + 'a';
    }
    if (*str != 0) {
        my_strlowcase(str + 1);
    }
    return (str);
}
