/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Swaps two variables
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
