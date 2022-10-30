# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:15:13 by ntojamur          #+#    #+#              #
#    Updated: 2022/10/30 18:43:41 by ntojamur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

HEADERS	=	cub3D.h \
			parsing/parsing.h \
			error/error.h \
			state/state.h

MAIN	=	main.c

PARSING	=	parsing/parsing.c \
			parsing/read_file.c \
			parsing/parsing_utils.c \
			parsing/check_digits.c \
			parsing/check_strings.c \
			parsing/repeats_and_arg.c \
			parsing/parsing_map.c

ERROR	=	error/error.c

STATE	=	state/state.c

SRCS	=	$(MAIN) $(PARSING) $(ERROR) $(STATE)

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
