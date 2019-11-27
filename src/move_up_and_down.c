/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#include "struct.h"

static void move_down_2(char **map, pos_t *pos)
{
    if (map[pos->y + 1][pos->x] == 'X' && (map[pos->y + 2][pos->x] == ' '
    || map[pos->y + 2][pos->x] == 'O')) {
        map[pos->y][pos->x] = ' ';
        map[pos->y + 1][pos->x] = 'P';
        map[pos->y + 2][pos->x] = 'X';
        pos->y += 1;
    } else if (map[pos->y + 1][pos->x] == 'O') {
        map[pos->y][pos->x] = ' ';
        map[pos->y + 1][pos->x] = 'P';
        pos->y += 1;
    }
}

void move_down(char **map, pos_t *pos)
{
    if (map[pos->y + 1][pos->x] == ' ') {
        map[pos->y][pos->x] = ' ';
        map[pos->y + 1][pos->x] = 'P';
        pos->y += 1;
    } else
        move_down_2(map, pos);
}

static void move_up_2(char **map, pos_t *pos)
{
    if (map[pos->y - 1][pos->x] == 'X' && (map[pos->y - 2][pos->x] == ' '
    || map[pos->y - 2][pos->x] == 'O')) {
        map[pos->y][pos->x] = ' ';
        map[pos->y - 1][pos->x] = 'P';
        map[pos->y - 2][pos->x] = 'X';
        pos->y -= 1;
    } else if (map[pos->y-1][pos->x] == 'O') {
        map[pos->y][pos->x] = ' ';
        map[pos->y-1][pos->x] = 'P';
        pos->y -= 1;
    }
}

void move_up(char **map, pos_t *pos)
{
    if (map[pos->y-1][pos->x] == ' ') {
        map[pos->y][pos->x] = ' ';
        map[pos->y - 1][pos->x] = 'P';
        pos->y -= 1;
    } else
        move_up_2(map, pos);
}