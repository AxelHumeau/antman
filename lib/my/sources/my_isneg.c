/*
** EPITECH PROJECT, 2021
** Task 04 - my_isneg
** File description:
** Displays P for positive numbers, N for negative
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    my_putchar('\n');
    return (0);
}
