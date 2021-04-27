/*
** EPITECH PROJECT, 2021
** utilitaries
** File description:
** function useful
*/

#include "include/maze.h"

void shorty(dante_t *dante, int perfect, coo_t co)
{
    for (co.x = 0; co.x < dante->width; co.x++) {
        if ((co.y == 0 && co.x == 0) || (dante->maze[co.y][co.x] == 'X' \
        && ((check_side(dante, &co) == 1) || (perfect == 1 && \
        check_side(dante, &co) == 2)))) {
                dante->maze[co.y][co.x] = '*';
                maze(dante, &co);
        }
    }
}

int	in_map(dante_t *dan, coo_t *co)
{
    if (co->y < 0 || co->x < 0 || co->y >= dan->height || co->x >= dan->width)
        return (0);
    return (1);
}

int	uppos(dante_t *dante, coo_t *co)
{
    coo_t pos = {co->x, co->y};
    int random = rand() % 2;
    int value = (rand() % 2) * 2 - 1;

    if (random == 0)
        co->y += value;
    else
        co->x += value;
    while (in_map(dante, co) == 0 || check_side(dante, co) > 1 || \
    dante->maze[co->y][co->x] == '*') {
        co->x = pos.x;
        co->y = pos.y;
        random = rand() % 2;
        value = (rand() % 2) * 2 - 1;
        if (random == 0)
            co->y += value;
        else
            co->x += value;
    }
    return (1);
}

int my_free(dante_t *dante)
{
    for (int i = 0; i < dante->height; i++)
        free(dante->maze[i]);
    free(dante->maze);
    return (0);
}

void display_maze(dante_t *dante)
{
    for (int i = 0; i < dante->height; i++) {
        for (int j = 0; j < dante->width; j++)
            printf("%c", dante->maze[i][j]);
        if (i != dante->height - 1)
            printf("\n");
    }
}