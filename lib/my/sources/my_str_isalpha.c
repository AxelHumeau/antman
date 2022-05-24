/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** Check if string is alphabetic
*/

int my_char_is_upper(char c);
int my_char_is_lower(char c);

int my_str_isalpha(char const *str)
{
    if (*str == 0) {
        return (1);
    } else if (my_char_is_upper(*str) || my_char_is_lower(*str)) {
        return my_str_isalpha(str + 1);
    } else {
        return (0);
    }
}
