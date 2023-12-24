NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RLFLAGS = -L/usr/include -lreadline

SRC = $(wildcard *.c)

LIBFTDIR = ./libft
LIBFTA = ./libft/libft.a

all: $(NAME)

$(NAME):
	@make -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFTA) $(RLFLAGS) -o $(NAME)

clean:
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
