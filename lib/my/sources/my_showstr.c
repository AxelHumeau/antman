/*
** EPITECH PROJECT, 2021
** my_showstr
** File description:
** Show a string, using hex values for non printable chars
*/

void my_putchar(char c);
int my_putnbr_base(int nbr , char const *base);

static void put_padded_hex(char c)
{
    if (c < 16) {
        my_putchar('0');
    }
    my_putnbr_base(c, "0123456789abcdef");
}

int my_showstr(char const *str)
{
    if (*str == 0) {
        return (0);
    } else if (*str < ' ') {
        my_putchar('\\');
        put_padded_hex(*str);
    } else {
        my_putchar(*str);
    }
    my_showstr(str + 1);
    return (0);
}
