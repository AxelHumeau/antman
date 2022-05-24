/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** Check if string is uppercase
*/

int my_char_is_upper(char c);

int my_str_isupper(char const *str)
{
    if (*str == 0) {
        return (1);
    } else if (my_char_is_upper(*str)) {
        return my_str_isupper(str + 1);
    } else {
        return (0);
    }
}
