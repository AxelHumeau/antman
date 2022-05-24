/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** String compare
*/

int my_strcmp(char const *s1, char const *s2)
{
    if (*s1 < *s2) {
        return (-1);
    } else if (*s1 > *s2) {
        return (1);
    }
    if (*s1 == 0) {
        return (0);
    } else {
        return (my_strcmp(s1 + 1, s2 + 1));
    }
}
