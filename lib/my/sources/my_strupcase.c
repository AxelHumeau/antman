/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** String to uppercase
*/

int my_char_is_lower(char c)
{
    return c >= 'a' && c <= 'z';
}

char *my_strupcase(char *str)
{
    if (my_char_is_lower(*str)) {
        *str = *str - 'a' + 'A';
    }
    if (*str != 0) {
        my_strupcase(str + 1);
    }
    return (str);
}
