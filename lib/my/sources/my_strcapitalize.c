/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** Capitalize string
*/

int my_char_is_lower(char c);
int my_char_is_upper(char c);

static void one_char_strcap_upper(char *str, int *capitalize_next)
{
    if (my_char_is_upper(*str) || (*str >= '0' && *str <= '9')) {
        *capitalize_next = 0;
    } else if (my_char_is_lower(*str)) {
        *str = *str - 'a' + 'A';
        *capitalize_next = 0;
    }
}

static void one_char_strcap_lower(char *str, int *capitalize_next)
{
    if (my_char_is_upper(*str)) {
        *str = *str - 'A' + 'a';
    } else if (!my_char_is_lower(*str) && !(*str >= '0' && *str <= '9')) {
        *capitalize_next = 1;
    }
}

char *my_strcapitalize(char *str)
{
    int capitalize_next = 1;
    char *start = str;

    while (*str != 0) {
        if (capitalize_next) {
            one_char_strcap_upper(str, &capitalize_next);
        } else {
            one_char_strcap_lower(str, &capitalize_next);
        }
        str++;
    }
    return start;
}
