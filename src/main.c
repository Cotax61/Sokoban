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

void show_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map  file representing the warehouse map, ");
    my_putstr("containing '#' for walls,\n         'P' for player, 'X'");
    my_putstr(" for boxes and 'O' for storage location.\n");
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

void display_end_msg(int msg_id)
{
    if (msg_id == -1)
        my_putstr("Game Over (crates got stuck)\n");
    else if (msg_id == 0)
        my_putstr("You did it ! All crates are correctly sorted !\n");
    else
        my_put_error("Something went wrong.\n");
}

void init_game(char **map, char **save, char *buffer)
{
    if (!check_map(map)) {
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

    if (ac < 1)
        return (84);
    else if (my_strcmp(av[1], "-h") == 0) {
        show_help();
        return (0);
    }
    buffer = read_file(av[1]);
    map = make_map_from_buffer(buffer);
    init_game(map, save, buffer);
    save = make_map_from_buffer(buffer);
    ret = game_loop(map, save);
    endwin();
    display_end_msg(ret);
    return (ret == -1) ? 1 : 0;
}