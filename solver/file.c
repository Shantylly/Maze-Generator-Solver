/*
** EPITECH PROJECT, 2021
** dante
** File description:
** file
*/

#include "include/maze.h"

int print_map(char **map)
{
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[j]; j++)
            printf("%c", map[i][j]);
        if (i != get_max(map, 'y') - 1)
            printf("\n");
    }
    return (0);
}

int my_lenght(char *filepath)
{
    struct stat buff;
    int ret = stat(filepath, &buff);

    if (ret == -1)
        return (-1);
    return (buff.st_size);
}

char **load_map(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer = malloc(sizeof(char) * (my_lenght(file) + 1));

    if (buffer == NULL || fd == -1) {
        free(buffer);
        return (NULL);
    }
    read(fd, buffer, my_lenght(file));
    buffer[my_lenght(file)] = 0;
    return (my_str_to_word_array(buffer, "\n"));
}