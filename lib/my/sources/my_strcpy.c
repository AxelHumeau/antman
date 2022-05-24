/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** Copy a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}
