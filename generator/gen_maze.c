/*
** EPITECH PROJECT, 2021
** generator
** File description:
** generate maze
*/

#include "include/maze.h"

int	check_side(dante_t *dante, coo_t *co)
{
    int i = 0;

    if (co->x >= 0 && co->y - 1 >= 0 && co->x < dante->width \
    && co->y - 1 < dante->height && dante->maze[co->y - 1][co->x] != 'X')
            i++;
    if (co->x + 1 >= 0 && co->y >= 0 && co->x + 1 < dante->width \
    && co->y < dante->height && dante->maze[co->y][co->x + 1] != 'X')
            i++;
    if (co->x >= 0 && co->y + 1 >= 0 && co->x < dante->width \
    && co->y + 1 < dante->height && dante->maze[co->y + 1][co->x] != 'X')
            i++;
    if (co->x - 1 >= 0 && co->y >= 0 && co->x - 1 < dante->width \
    && co->y < dante->height && dante->maze[co->y][co->x - 1] != 'X')
            i++;
    return (i);
}

int	verif_side(dante_t *dante, coo_t *co)
{
    coo_t pos;

    pos.x = co->x;
    pos.y = co->y -1;
    if (in_map(dante, &pos) && check_side(dante, &pos) == 1)
        return (1);
    pos.y = co->y + 1;
    if (in_map(dante, &pos) && check_side(dante, &pos) == 1)
        return (1);
    pos.x = co->x - 1;
    pos.y = co->y;
    if (in_map(dante, &pos) && check_side(dante, &pos) == 1)
        return (1);
    pos.x = co->x + 1;
    if (in_map(dante, &pos) && check_side(dante, &pos) == 1)
        return (1);
    return (0);
}

int	maze(dante_t *dante, coo_t *co)
{
    coo_t pos;

    srand(time(NULL));
    pos.x = co->x;
    pos.y = co->y;
    while ((pos.y == 0 && pos.x == 0) || ((verif_side(dante, &pos)) == 1 \
    && (pos.y != dante->height - 1 && pos.x != dante->width - 1))) {
        uppos(dante, &pos);
        dante->maze[pos.y][pos.x] = '*';
    }
    return (0);
}

int	gen_maze(dante_t *dante, int perfect)
{
    coo_t co = {0, 0};

    for (co.y = 0; co.y < dante->height; co.y++)
        shorty(dante, perfect, co);
    dante->maze[dante->width-1][dante->height-1] = '*';
    return (0);
}