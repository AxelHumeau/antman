/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** Parse integer
*/

static int my_getnbr_single_digit(char c)
{
    if (c >= '0' && c <= '9') {
        return (c - '0');
    } else {
        return (-1);
    }
}

static int will_overflow(int compose, int digit)
{
    if (compose == 214748364) {
        return (digit > 7);
    } else if (compose == -214748364) {
        return (digit > 8);
    }
    return (compose > 214748364 || compose < -214748364);
}

int my_getnbr(char const *str)
{
    int compose = 0;
    int multiplier = 1;
    int digit = 0;

    while (*str == '-' || *str == '+') {
        if (*str == '-') {
            multiplier *= -1;
        }
        str++;
    }
    while (digit >= 0) {
        if (will_overflow(compose, digit)) {
            return (0);
        }
        compose = compose * 10 + digit * multiplier;
        digit = my_getnbr_single_digit(*str);
        str++;
    }
    return compose;
}
