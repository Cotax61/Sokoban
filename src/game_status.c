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
    int pos[2] = {0, 0};
    int crates = 0;
    int unmovable = 0;
    int sorted = 0;

    for (; map[pos[1]] != 0; pos[0]++) {
        if (map[pos[1]][pos[0]] == '\n' || map[pos[1]][pos[0]] == '\0') {
            pos[1]++;
            pos[0] = -1;
            continue;
        } else if (save[pos[1]][pos[0]] == 'O' && map[pos[1]][pos[0]] == ' ')
            map[pos[1]][pos[0]] = 'O';
        if (map[pos[1]][pos[0]] == 'X' && pos[1] != 0 && pos[0] != 0) {
            unmovable += check_unmovable_crates(map, pos[1], pos[0]);
            crates++;
            sorted += (save[pos[1]][pos[0]] == 'O') ? 1 : 0;
        }
    }
    sorted = (sorted == crates) ? 0 : 1;
    return (crates == unmovable && sorted != 0) ? -1 : sorted;
}