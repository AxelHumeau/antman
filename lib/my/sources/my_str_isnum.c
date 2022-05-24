/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** Check if string is numeric
*/

int my_str_isnum(char const *str)
{
    if (*str == 0) {
        return (1);
    } else if (*str >= '0' && *str <= '9') {
        return my_str_isnum(str + 1);
    } else {
        return (0);
    }
}
