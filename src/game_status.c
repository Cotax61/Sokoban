/*
** EPITECH PROJECT, 2019
** get_map.c
** File description:
** get and check the map
*/

int check_unmovable_crates(char **map, int lines, int cols)
{
    if ((map[lines - 1][cols] == '#' || map[lines - 1][cols] == 'X') &&
    (map[lines][cols + 1] == '#' || map[lines][cols + 1] == 'X'))
        return (1);
    if ((map[lines][cols + 1] == '#' || map[lines][cols + 1] == 'X') &&
    (map[lines + 1][cols] == '#' || map[lines + 1][cols] == '#'))
        return (1);
    if ((map[lines + 1][cols] == '#' || map[lines + 1][cols] == 'X') &&
    (map[lines][cols - 1] == '#' || map[lines][cols - 1] == 'X'))
        return (1);
    if ((map[lines][cols - 1] == '#' || map[lines][cols - 1] == 'X') &&
    (map[lines - 1][cols] == '#' || map[lines - 1][cols] == 'X'))
        return (1);
    return (0);
}

int check_game_status(char **map, char **save)
{
    int cols = 0;
    int lines = 0;
    int crates = 0;
    int unmovable = 0;

    for (; map[lines] != 0; cols++) {
        if (map[lines][cols] == '\n' || map[lines][cols] == '\0') {
            lines++;
            cols = -1;
            continue;
        } else if (save[lines][cols] == 'O' && map[lines][cols] == ' ')
            map[lines][cols] = 'O';
        if (map[lines][cols] == 'X' && lines != 0 && cols != 0
        && save[lines][cols] != 'O') {
            crates++;
            unmovable += check_unmovable_crates(map, lines, cols);
        }
    }
    unmovable = (unmovable == 0) ? -1 : unmovable;
    return (crates == unmovable) ? -1 : crates;
}