/*
** EPITECH PROJECT, 2018
** display_map.c
** File description:
** display the map of a sokoban in the middle of the screen
*/

#include <curses.h>

static int get_array_rows(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return (i);
}

static int get_max_cols(char **array)
{
    int i = 0;
    int rows = 0;
    int max_cols = 0;

    while (array[rows][i] != '\0') {
        if (i > max_cols)
            max_cols = i;
        if (array[rows][i] == '\n' || array[rows][i] == '\0') {
            rows++;
            i = 0;
        }
        i++;
    }
    return (max_cols);
}

void display_map(char **array)
{
    int i = 0;
    int j = 0;
    int y = 0;
    int x = 0;
    int rows = get_array_rows(array);
    int stop = rows;
    int max_cols = get_max_cols(array);

    getmaxyx(stdscr, y, x);
    while (i != stop) {
        for (int j = 0; array[i][j] != '\0'; j++)
            mvprintw((y/2) - rows, (x-max_cols)/2, "%s", array[i]);
        rows--;
        i++;
    }
}
