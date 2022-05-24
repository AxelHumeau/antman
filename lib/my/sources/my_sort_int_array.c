/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** Sort an integer array
*/

void my_swap(int *a, int *b);

static int array_min_index(int *array, int size)
{
    int i = 1;
    int minimum = 0;

    while (i < size) {
        if (array[i] < array[minimum]) {
            minimum = i;
        }
        i++;
    }
    return minimum;
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;

    while (i < size - 1) {
        my_swap(array + i, array + i + array_min_index(array + i, size - i));
        i++;
    }
}
