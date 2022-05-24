/*
** EPITECH PROJECT, 2021
** my_memset
** File description:
** Copy a char n times into a string
*/

void my_memset(char *into, char c, int n)
{
    int i = 0;

    while (i < n) {
        into[i] = c;
        i++;
    }
}
