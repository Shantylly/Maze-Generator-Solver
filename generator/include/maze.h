/*
** EPITECH PROJECT, 2020
** lib
** File description:
** headers for everything
*/

#ifndef MAZE_H_
#define MAZE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

typedef struct coo_s {
    int x;
    int y;
} coo_t;

typedef struct dante_s {
    char **maze;
    int width;
    int height;
} dante_t;

int	gen_maze(dante_t *, int);
int	check_side(dante_t *, coo_t *);
int	uppos(dante_t *, coo_t *);
int	in_map(dante_t *, coo_t *);
int my_free(dante_t *);
int	maze(dante_t *, coo_t *);
void display_maze(dante_t *);
void shorty(dante_t *, int, coo_t);

#endif /* !MAZE_H_ */
