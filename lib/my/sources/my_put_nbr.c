/*
** EPITECH PROJECT, 2021
** Task 07 - my_put_nbr
** File description:
** Prints a decimal number
*/

void my_putchar(char c);

static void my_put_nbr_unsigned(unsigned int n)
{
    int print_zeros = 0;
    int magnitude = 1000000000;
    int digit;

    while (magnitude >= 1) {
        digit = (n / magnitude) % 10;
        if (digit != 0 || print_zeros) {
            my_putchar('0' + digit);
            print_zeros = 1;
        }
        magnitude /= 10;
    }
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr_unsigned(-((unsigned int) nb));
    } else if (nb == 0) {
        my_putchar('0');
    } else {
        my_put_nbr_unsigned(nb);
    }
    return (0);
}
