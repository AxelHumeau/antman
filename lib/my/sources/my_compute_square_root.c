/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** Compute integer square root
*/

int my_compute_square_root(int nb)
{
    int i;

    for (i = 0; i <= nb; i++) {
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}
