/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Copy n chars to string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    if (n > i) {
        dest[i] = 0;
    }
    return dest;
}
