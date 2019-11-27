/*
** EPITECH PROJECT, 2019
** get_map.c
** File description:
** get and check the map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "map.h"

int get_file_size(char *file)
{
    struct stat st;

    if (stat(file, &st) != 0)
        exit(84);
    if ((st.st_size) == 0)
        exit(84);
    return (st.st_size);
}

char *read_file(char *file_path)
{
    int fd;
    int size;
    char *buffer;

    fd = open(file_path, O_RDONLY);
    size = get_file_size(file_path);
    buffer = malloc(sizeof(char) * size + 2);
    if (buffer == NULL)
        return (NULL);
    read(fd, buffer, size);
    buffer[size] = '\0';
    return (buffer);
}