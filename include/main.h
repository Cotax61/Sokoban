/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#ifndef MAIN_H
#define MAIN_H

int game_loop(char **map, char **save, char *buffer);
int check_map(char **map);
char *read_file(char *file_path);
char **make_map_from_buffer(char *buffer);
int check_map_char(char **map);

#endif