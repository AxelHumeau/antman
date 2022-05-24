/*
** EPITECH PROJECT, 2021
** my_evil_str
** File description:
** Swaps characters in a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int i = len / 2;
    char temp;

    while (i > 0) {
        i--;
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return (str);
}
