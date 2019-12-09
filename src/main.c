/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include "my.h"
#include "main.h"
#include <ncurses.h>
#include <stdlib.h>

void show_help(int ac, char **av)
{
    if (my_strcmp(av[1], "-h") == 0)
        return;
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map  file representing the warehouse map, ");
    my_putstr("containing '#' for walls,\n         'P' for player, 'X'");
    my_putstr(" for boxes and 'O' for storage locations.\n");
}

void init_ncurse(void)
{
    WINDOW *win;

    win = initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    nodelay(win, false);
}

void init_game(char **map, char **save, char *buffer)
{
    if (!check_map(map) || !check_map_char(map)) {
        my_free_array(map);
        free(buffer);
        exit (84);
    }
    init_ncurse();
}

int main(int ac, char **av)
{
    char **map;
    char **save;
    char *buffer;
    int ret;

    if (ac <= 1)
        return (84);
    if (my_strcmp(av[1], "-h") == 0)
        show_help(ac, av);
    buffer = read_file(av[1]);
    map = make_map_from_buffer(buffer);
    init_game(map, save, buffer);
    save = make_map_from_buffer(buffer);
    ret = game_loop(map, save, buffer);
    endwin();
    my_free_array(map);
    my_free_array(save);
    return (ret == -1) ? 1 : 0;
}