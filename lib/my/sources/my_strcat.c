/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** Concatenate strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != 0) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = 0;
    return dest;
}
