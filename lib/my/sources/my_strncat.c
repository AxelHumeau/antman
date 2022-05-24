/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** Concatenate strings
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != 0 && i < nb) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = 0;
    return dest;
}
