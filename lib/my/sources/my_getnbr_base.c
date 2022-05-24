/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** Parse integer
*/

char *my_strstr(char const *str, char const *to_find);
int my_strlen(char const *str);

static int my_getnbr_base_single_digit(char c, char const *base)
{
    char needle[] = {c, 0};
    char *result = my_strstr(base, needle);

    if (c == 0 || result == 0) {
        return -1;
    }
    return (result - base);
}

static int will_overflow_base(int compose, int base, int digit)
{
    int result = compose * base + digit;
    long long bigger = ((long long) compose) * base + digit;

    return result != bigger;
}

int my_getnbr_base(char const *str, char const *base)
{
    int baselen = my_strlen(base);
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
        if (will_overflow_base(compose, baselen, digit * multiplier)) {
            return (0);
        }
        compose = compose * baselen + digit * multiplier;
        digit = my_getnbr_base_single_digit(*str, base);
        str++;
    }
    return compose;
}
