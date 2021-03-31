# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bellan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 19:18:50 by bellan            #+#    #+#              #
#    Updated: 2021/03/31 20:42:02 by bellan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC = ./test_mlx.c ./map.c ./checker.c ./texture.c
OBJS = $(SRC:.c=.o)
CC = gcc
FLAGS = -g -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
CLEAN = rm *.o
RM = rm -f

$(NAME):$(OBJS)
	$(MAKE) -C libft
	$(CC) $(FLAGS) $(SRC) libft/libft.a -o $(NAME)
	./$(NAME) map1.cub

$(OBJS):cub3d.h

all: $(NAME)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re

# gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit test_mlx.c libft/libft.a
#  gcc -Wall -Wextra -Werror libft/libft.a map.c
# gcc -Wall -Wextra -Werror -lft -Llibft map.c 