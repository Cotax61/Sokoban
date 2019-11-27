/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#include "struct.h"
#include <stdlib.h>
#include "my.h"

#include <stdio.h>

pos_t *create_new_player(char **map)
{
    pos_t *new = malloc(sizeof(pos_t));
    int i = 0;
    int line = 0;
    new->max_x = 0;

    for (; map[line] != NULL; i++) {
        if (map[line][i] == 'P') {
            new->x = i;
            new->y = line;
        }
        if (map[line][i] == '\0' || map[line][i] == '\n') {
            new->max_x = (i > new->max_x) ? i : new->max_x;
            i = -1;
            line++;
        }
    }
    new->max_y = line - 2;
    return (new);
}