# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:15:13 by ntojamur          #+#    #+#              #
#    Updated: 2022/10/26 18:43:15 by ntojamur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

HEADERS	=	./cub3D.h parsing/parsing.h error/error.h

MAIN	=	main.c

PARSING	=	parsing/parsing.c

ERROR	=	error/error.c

SRCS	=	$(MAIN) $(PARSING) $(ERROR)

OBJ = $(SRCS:.c=.o)

LIBFT = libft/libft.a
MLX = mlx/libmlx.a

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c $(HEADERS) Makefile
	$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT) : libft_re
	$(MAKE) -C libft

$(MLX) :
	$(MAKE) -C mlx

clean :
	$(RM) $(OBJ)
	$(MAKE) clean -C libft
	$(MAKE) clean -C mlx

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(MLX)

re : fclean all

.PHONY : all clean fclean re libft_re
