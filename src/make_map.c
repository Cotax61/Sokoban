/*
** EPITECH PROJECT, 2019
** get_map.c
** File description:
** get and check the map
*/

#include <stdlib.h>

int count_lines(char *buffer)
{
    int line = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            line++;
    return (line);
}

char **allocate_map(char *buffer)
{
    char **map;
    int lines = count_lines(buffer);
    int character = 0;
    int i = 0;

    map = malloc(sizeof(char *) * (lines + 2));
    lines = 0;
    while (buffer[i] != '\0') {
        for (; buffer[i] != '\n' && buffer[i] != '\0'; i++, character++);
        map[lines] = malloc(sizeof(char) * character + 1);
        map[lines][character] = '\0';
        character = 0;
        lines++;
        i += (buffer[i] != '\0') ? 1 : 0;
    }
    map[lines] = NULL;
    return (map);
}

void copy_buffer_to_map(char *buffer, char **map)
{
    int i = 0;
    int col = 0;
    int line = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            map[line][col] = '\0';
            col = 0;
            line++;
            i++;
        }
        if (buffer[i] == '\0')
            break;
        map[line][col] = buffer[i];
        col++;
        i += (buffer[i] != '\0') ? 1 : 0;
    }
    if (map[line] != NULL)
        map[line][col] = '\0';
}

char **make_map_from_buffer(char *buffer)
{
    char **map = allocate_map(buffer);

    copy_buffer_to_map(buffer, map);
    return (map);
}