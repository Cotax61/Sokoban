/*
** EPITECH PROJECT, 2018
** display_map.c
** File description:
** display the map of a sokoban in the middle of the screen
*/

#include <stdlib.h>
#include "my.h"

static void invalid_map_message(int *tab)
{
    if (!tab[2])
        my_put_error("The map doesn't have any player !\n");
    if (!tab[1])
        my_put_error("The map doesn't have any O to put crates in !\n");
    if (!tab[0])
        my_put_error("The map doesn't have any crates !\n");
    if (tab[1] < tab[0] && tab[1] && tab[0])
        my_put_error("The map have more boxes than storages !\n");
    if (tab[1] > tab[0] && tab[1] && tab[0])
        my_put_error("The map have more storages than boxes !\n");
    if (tab[2] > 1)
        my_put_error("The map contains more than one player !\n");
}

int check_map(char **map)
{
    int tab[] = {0, 0, 0};
    int line = 0;

    for (int i = 0; map[line] != NULL; i++) {
        if (map[line][i] == 'X')
            tab[0]++;
        if (map[line][i] == 'O')
            tab[1]++;
        if (map[line][i] == 'P')
            tab[2]++;
        if (map[line][i] == '\0' || map[line][i] == '\n') {
            i = -1;
            line++;
        }
    }
    if (tab[2] != 1 || tab[1] != tab[0] || tab[1] == 0 || tab[0] == 0) {
        invalid_map_message(tab);
        return (0);
    }
    return (1);
}