/*
** EPITECH PROJECT, 2019
** it put
** File description:
** a string on ur terminal.
*/

#include <unistd.h>

void my_putstr(char *str);

void my_putarray(char **array, int carry_ret)
{
    int i = 0;

    while (array[i] != NULL) {
        my_putstr(array[i]);
        if (carry_ret == 1)
            write(1, "\n", 1);
        i++;
    }
}