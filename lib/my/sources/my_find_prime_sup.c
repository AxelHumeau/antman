/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** Find prime numbers
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    while (!my_is_prime(nb)) {
        nb++;
    }
    return nb;
}
