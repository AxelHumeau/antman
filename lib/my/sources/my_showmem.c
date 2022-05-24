/*
** EPITECH PROJECT, 2021
** my_showmem
** File description:
** Memory dump
*/

int my_putnbr_base(int nbr, char const *base);
void my_putchar(char c);

static void print_address(int line)
{
    int charcount = 1;
    int line_size = line;

    while (line_size > 0) {
        line_size /= 16;
        charcount++;
    }
    while (charcount < 8) {
        my_putchar('0');
        charcount++;
    }
    my_putnbr_base(line * 16, "0123456789abcdef");
}

static void show_ascii_dump(char const *str, int size)
{
    int i = 0;

    for (; i < size; i++) {
        if (str[i] < ' ') {
            my_putchar('.');
        } else {
            my_putchar(str[i]);
        }
    }
    my_putchar('\n');
}

static void my_showmem_line(char const *str, int line, int size)
{
    int i = 0;

    print_address(line);
    my_putchar(':');
    while (i < size) {
        if (i % 2 == 0)
            my_putchar(' ');
        if (str[i] < 16)
            my_putchar('0');
        my_putnbr_base(str[i], "0123456789abcdef");
        i++;
    }
    for (i = (i * 5 + 1) / 2; i <= 8 * 5; i++) {
        my_putchar(' ');
    }
    show_ascii_dump(str, size);
}

int my_showmem(char const *str, int size)
{
    int line = 0;

    while (line < size / 16) {
        my_showmem_line(str + line * 16, line, 16);
        line++;
    }
    if (size % 16 != 0) {
        my_showmem_line(str + line * 16, line, size % 16);
    }
    return (0);
}
