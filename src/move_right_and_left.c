/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#include "struct.h"

void move_left_2(char **map, pos_t *pos)
{
    if (map[pos->y][pos->x - 1] == 'X' && (map[pos->y][pos->x - 2] == ' '
    || map[pos->y][pos->x - 2] == 'O')) {
        map[pos->y][pos->x] = ' ';
        map[pos->y][pos->x - 1] = 'P';
        map[pos->y][pos->x - 2] = 'X';
        pos->x -= 1;
    } else if (map[pos->y][pos->x - 1] == 'O') {
        map[pos->y][pos->x] = ' ';
        map[pos->y][pos->x - 1] = 'P';
        pos->x -= 1;
    }
}

void move_left(char **map, pos_t *pos)
{
    if (map[pos->y][pos->x - 1] == ' ') {
        map[pos->y][pos->x] = ' ';
        map[pos->y][pos->x - 1] = 'P';
        pos->x -= 1;
    } else
        move_left_2(map, pos);
}

void move_right_2(char **map, pos_t *pos)
{
    if (map[pos->y][pos->x + 1] == 'X' && (map[pos->y][pos->x + 2] == ' '
    || map[pos->y][pos->x + 2] == 'O')) {
        map[pos->y][pos->x] = ' ';
        map[pos->y][pos->x + 1] = 'P';
        map[pos->y][pos->x + 2] = 'X';
        pos->x += 1;
    } else if (map[pos->y][pos->x + 1] == 'O') {
        map[pos->y][pos->x] = ' ';
        map[pos->y][pos->x + 1] = 'P';
        pos->x += 1;
    }
}

void move_right(char **map, pos_t *pos)
{
    if (map[pos->y][pos->x + 1] == ' ') {
        map[pos->y][pos->x] = ' ';
        map[pos->y][pos->x + 1] = 'P';
        pos->x += 1;
    } else
        move_right_2(map, pos);
}
