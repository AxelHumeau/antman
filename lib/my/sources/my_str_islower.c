/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** Check if string is lowercase
*/

int my_char_is_lower(char c);

int my_str_islower(char const *str)
{
    if (*str == 0) {
        return (1);
    } else if (my_char_is_lower(*str)) {
        return my_str_islower(str + 1);
    } else {
        return (0);
    }
}
