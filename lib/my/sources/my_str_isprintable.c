/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** Check if string is lowercase
*/

int my_str_isprintable(char const *str)
{
    if (*str == 0) {
        return (1);
    } else if ((unsigned char) *str >= ' ') {
        return my_str_isprintable(str + 1);
    } else {
        return (0);
    }
}
