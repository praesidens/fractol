# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 15:51:22 by bsuprun           #+#    #+#              #
#    Updated: 2018/10/14 21:59:38 by bsuprun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT_NAME = libft.a

LIBFT_PATH = libft/$(LIBFT_NAME)

SRCS = $(wildcard *.c)

OBJ = $(SRCS:*.c=.o)

CFLAGS = -Wall -Wextra -Werror

FLAGS = -lmlx -framework OpenGL -framework AppKit

CC = gcc

.PHONY: clean fclean re all

.NOTPARALLEL: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft/
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT_PATH) $(FLAGS)

clean:
	/bin/rm -f *.o
	$(MAKE) clean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) fclean -C libft/

re: fclean all

