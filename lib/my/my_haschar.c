/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

int my_haschar(const char c, const char *char_list)
{
    if (c == '\0')
        return (1);
    for (int i = 0; char_list[i] != '\0'; i++) {
        if (char_list[i] == c)
            return (1);
    }
    return (0);
}