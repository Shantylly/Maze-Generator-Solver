/*
** EPITECH PROJECT, 2020
** lib
** File description:
** is_delim.c
*/

#include "include/maze.h"

void push_front(maze_char_t **list, int x, int y)
{
    maze_char_t *node = malloc(sizeof(*node));

    node->x = x;
    node->y = y;
    node->next = *list;
    *list = node;
}

void pop_front(maze_char_t **list)
{
    maze_char_t *node = *list;

    *list = (*list)->next;
    free(node);
}

int is_delim(char c, char const *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return (-1);
    return (0);
}

int check_solved_map(char **map, int i, int j)
{
    if (map[i][j] == '.' ||
    (i == get_max(map, 'y') - 1 && j == get_max(map, 'x') - 1))
        map[i][j] = 'o';
    else if (map[i][j] == 'x')
        map[i][j] = '*';
    return (0);
}