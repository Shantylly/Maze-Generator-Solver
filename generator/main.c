/*
** EPITECH PROJECT, 2020
** dante's star
** File description:
** main for dante's star
*/

#include "include/maze.h"

void usage(void)
{
    printf("USAGE:\n\t./generator [WIDTH] [HEIGHT] (perfect)\n\n");
    printf("DESCRIPTION:\n\tWIDTH: strictly over 1");
    printf("\n\tHEIGHT: strictly over 1");
    printf("\n\tperfect: (optionnal) make a perfect maze\n");
    exit(84);
}

int	init_dante(dante_t *dante)
{
    if ((dante->maze = malloc(sizeof(char *) * dante->height)) == NULL)
        return (0);
    for (int i = 0; i < dante->height; i++) {
        dante->maze[i] = malloc(sizeof(char) * dante->width + 1);
        memset(dante->maze[i], 88, dante->width);
        dante->maze[i][dante->width] = '\0';
    }
    return (1);
}

int is_number(char c)
{
    char arr[10] = "0123456789";

    for (int i = 0; i <= 9; i++) {
        if (c == arr[i])
            return (1);
    }
    return (0);
}

void error(int ac, char **av, int ret)
{
    if (ret > 0)
        usage();
    if (ac < 3 || ac > 4)
        error(ac, av, 1);
    for (int i = 0; av[1][i] != '\0'; i++)
        if (is_number(av[1][i]) == 0)
            error(ac, av, 1);
    for (int i = 0; av[2][i] != '\0'; i++)
        if (is_number(av[2][i]) == 0)
            error(ac, av, 1);
    if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0)
        error(ac, av, 1);
    if (ac == 4)
        if (strcmp(av[3], "perfect"))
            error(ac, av, 1);
}

int main(int ac, char **av)
{
    dante_t dante;

    error(ac, av, 0);
    dante.height = atoi(av[1]);
    dante.width = atoi(av[2]);
    dante.maze = NULL;
    if ((init_dante(&dante)) == -1)
        return (84);
    if (ac == 4 && strcmp(av[3], "perfect") == 0)
            gen_maze(&dante, 0);
        else
            gen_maze(&dante, 1);
    display_maze(&dante);
    my_free(&dante);
    return (0);
}