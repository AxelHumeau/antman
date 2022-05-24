/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** Compute pow
*/

static int will_mul_overflow(int a, int b)
{
    if (b > 0 && a > 2147483647 / b) {
        return 1;
    } else if (b < 0 && a < -2147483648 / -b) {
        return 1;
    } else {
        return 0;
    }
}

int my_compute_power_rec(int nb, int p)
{
    int prev;

    if (p < 0) {
        return (0);
    } else if (p == 0) {
        return (1);
    }
    prev = my_compute_power_rec(nb, p - 1);
    if (will_mul_overflow(nb, prev)) {
        return (0);
    }
    return nb * prev;
}
