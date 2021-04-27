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
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct maze_char_s {
    int x;
    int y;
    struct maze_char_s *next;
} maze_char_t;

char **load_map(char *file);
int is_delim(char c, char const *delim);
char **my_str_to_word_array(char *str, char *separator);
int get_max(char **map, char direction);
void pop_front(maze_char_t **list);
void push_front(maze_char_t **list, int x, int y);
void print_solved_map(char **map);
int move_bottom(char **map, int *pos, maze_char_t *oldpos);
int move_up(char **map, int *pos, maze_char_t *oldpos);
int dead_end(char **map, int *pos, maze_char_t *oldpos);
int check_solved_map(char **map, int i, int j);
int solve(char **map, int *pos, maze_char_t *oldpos);
int print_map(char **map);

#endif