##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compile libmy
##

CC	= gcc

SRC	= $(wildcard *.c)

OBJ	= $(SRC:.c=.o)

NAME	= solver

CFLAGS	= -W -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
