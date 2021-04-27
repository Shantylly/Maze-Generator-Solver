/*
** EPITECH PROJECT, 2021
** dante
** File description:
** maze
*/

#include "include/maze.h"

int get_max(char **map, char direction)
{
    int result = 0;

    if (direction == 'x') {
        for (int i = 0; map[0][i]; i++)
            result++;
    } else {
        for (int i = 0; map[i]; i++)
            result++;
    }
    return (result);
}

void print_solved_map(char **map)
{
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            check_solved_map(map, i, j);
        }
    }
}

int move_bottom(char **map, int *pos, maze_char_t *oldpos)
{
    map[pos[1]][pos[0]] = '.';
    pos[1] += 1;
    push_front(&oldpos, pos[0], pos[1]);
    return solve(map, pos, oldpos);
}

int move_up(char **map, int *pos, maze_char_t *oldpos)
{
    map[pos[1]][pos[0]] = '.';
    pos[1] -= 1;
    push_front(&oldpos, pos[0], pos[1]);
    return solve(map, pos, oldpos);
}

int dead_end(char **map, int *pos, maze_char_t *oldpos)
{
    map[oldpos->y][oldpos->x] = 'x';
    map[pos[1]][pos[0]] = 'x';
    pop_front(&oldpos);
    if (oldpos == NULL) {
        printf("no solution found");
        exit(0);
    }
    pos[0] = oldpos->x;
    pos[1] = oldpos->y;
    return solve(map, pos, oldpos);
}