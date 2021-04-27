/*
** EPITECH PROJECT, 2021
** dante
** File description:
** main
*/

#include "include/maze.h"

int check_win(char **map, int *pos)
{
    if (pos[0] == get_max(map, 'x') - 1 && pos[1] == get_max(map, 'y') - 1) {
        print_solved_map(map);
        print_map(map);
        exit(0);
    }
    return (0);
}

int move_right(char **map, int *pos, maze_char_t *oldpos)
{
    map[pos[1]][pos[0]] = '.';
    pos[0] += 1;
    push_front(&oldpos, pos[0], pos[1]);
    return solve(map, pos, oldpos);
}

int move_left(char **map, int *pos, maze_char_t *oldpos)
{
    map[pos[1]][pos[0]] = '.';
    push_front(&oldpos, pos[0], pos[1]);
    pos[0] -= 1;
    return solve(map, pos, oldpos);
}

int solve(char **map, int *pos, maze_char_t *oldpos)
{
    check_win(map, pos);
    if (pos[0] < get_max(map, 'x') - 1 && map[pos[1]][pos[0] + 1] == '*')
        return (move_right(map, pos, oldpos));
    else if (pos[0] > 0 && map[pos[1]][pos[0] - 1] == '*')
        return (move_left(map, pos, oldpos));
    else {
        if (pos[1] < get_max(map, 'y') - 1 && map[pos[1] + 1][pos[0]] == '*')
            return (move_bottom(map, pos, oldpos));
        else if (pos[1] > 0 && map[pos[1] - 1][pos[0]] == '*')
            return (move_up(map, pos, oldpos));
        else
            return (dead_end(map, pos, oldpos));
    }
    return (1);
}

int main(int ac, char **av)
{
    char **map = NULL;
    int *pos = malloc(sizeof(int) * 2);
    maze_char_t *oldpos = NULL;

    if (ac != 2) {
        free(map);
        return (84);
    }
    map = load_map(av[1]);
    if (map == NULL)
        return (84);
    pos[0] = 0;
    pos[1] = 0;
    solve(map, pos, oldpos);
    return (0);
}