/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** Split a string into words
*/

#include <stdlib.h>

char *my_strdup(char const *src);
int my_strlen(char const *str);

static int char_is_alphanum(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    }
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

static int overwrite_non_alphanum(int len, char *str)
{
    int i = 0;
    int separated = 1;
    int words = 0;

    while (i < len) {
        if (separated && char_is_alphanum(str[i])) {
            separated = 0;
            words++;
        } else if (!char_is_alphanum(str[i])) {
            separated = 1;
            str[i] = 0;
        }
        i++;
    }
    return words;
}

static char **split_on_zero_byte(int len, char *str, int words)
{
    char **split = malloc((words + 1) * sizeof(char *));
    int i = 0;
    int separated = 1;
    int word = 0;

    if (split == 0)
        return 0;
    while (i < len) {
        if (separated && str[i] != 0) {
            separated = 0;
            split[word] = str + i;
            word++;
        } else if (str[i] == 0) {
            separated = 1;
        }
        i++;
    }
    split[word] = 0;
    return split;
}

char **my_str_to_word_array(char const *str)
{
    int len;
    char *copy;
    char **result;
    int i = 0;

    if (str == NULL)
        return 0;
    len = my_strlen(str);
    copy = my_strdup(str);
    result = split_on_zero_byte(len, copy, overwrite_non_alphanum(len, copy));
    while (result[i] != 0) {
        result[i] = my_strdup(result[i]);
        i++;
    }
    free(copy);
    return result;
}
