/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** Find substrings
*/

int my_starts_with(char *str, char const *to_find)
{
    while (*to_find != 0) {
        if (*str != *to_find) {
            return (0);
        }
        str++;
        to_find++;
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    char *substr = str;

    while (*substr != 0) {
        if (my_starts_with(substr, to_find)) {
            return (substr);
        }
        substr++;
    }
    return (0);
}
