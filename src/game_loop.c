/*
** EPITECH PROJECT, 2019
** get_map.c
** File description:
** get and check the map
*/

#include <ncurses.h>
#include "struct.h"
#include "game_loop.h"
#include "my.h"
#include <stdlib.h>

void reset_map(char *buffer, char **map, pos_t *pos)
{
    my_free_array(map);
    map = NULL;
    map = make_map_from_buffer(buffer);
    free(pos);
    pos = create_new_player(map);
}

void key_read(char **map, char **save, char *buffer, pos_t *pos)
{
    int c = ERR;

    c = getch();
    if (c == KEY_UP && pos->y != 1)
        move_up(map, pos);
    if (c == KEY_DOWN && pos->y != pos->max_y)
        move_down(map, pos);
    if (c == KEY_RIGHT && pos->x != pos->max_x)
        move_right(map, pos);
    if (c == KEY_LEFT && pos->x != 1)
        move_left(map, pos);
    if (c == 32)
        reset_map(buffer, map, pos);
}

int game_loop(char **map, char **save, char *buffer)
{
    pos_t *p_pos = create_new_player(map);
    int status = 1;

    while (status > 0) {
        display_map(map);
        refresh();
        key_read(map, save, buffer, p_pos);
        status = check_game_status(map, save);
        refresh();
    }
    return (status);
}