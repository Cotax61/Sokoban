/*
** EPITECH PROJECT, 2019
** get_map.c
** File description:
** get and check the map
*/

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "struct.h"

pos_t *create_new_player(char **map);
void move_down(char **map, pos_t *pos);
void move_up(char **map, pos_t *pos);
void move_right(char **map, pos_t *pos);
void move_left(char **map, pos_t *pos);
int check_game_status(char **map, char **save);
char **make_map_from_buffer(char *buffer);
void display_map(char **array);

#endif