# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 21:06:41 by fandre-b          #+#    #+#              #
#    Updated: 2024/02/16 21:06:41 by fandre-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

CC := @cc
RM := -@rm -rf
CFLAGS := -Wall -Wextra -Werror -std=c99 -fsanitize=address -g
VAL := valgrind --leak-check=full --show-leak-kinds=all -s

#FT := libft
OBJ_DIR := obj
INCLUDES_DIR := includes

SRCS := fractol.c pixel_transf.c handles.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

#########not mine
# mlx library
#ifeq ($(OS), Linux)
MLX		= ./minilibx-linux/
MLX_LNK	= -L$(MLX) -lmlx -lXext -lX11 -lm -lz
#MLX_LNK	= -L $(MLX) -lmlx -lXext -lX11 -lm -lz
#else
#	MLX		= ./miniLibX/
#	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
#endif

MLX_LIB	= $(addprefix $(MLX),mlx.a)

# # ft library
# FT_LIB	= $(addprefix $(FT)/,libft.a)
# #FT_INC	= -I $(FT)
# FT_LNK	= -L $(FT) -l ft -l pthread
# #########not mine
# #$(FT_INC)
# #$(FT_LNK)

all:	$(NAME)

# $(FT_LIB):
# 	@make -C $(FT)

$(MLX_LIB):
	-@make -s -C $(MLX)

$(OBJ_DIR)/%.o:	%.c $(MLX_LIB)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(MLX) -I$(INCLUDES_DIR) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) -lm -o $(NAME)

test:
	@echo "<Still need to set up>"

clean:
	$(RM) $(OBJ_DIR)
	-@make -s -C $(MLX) clean
#	make -C $(FT) clean

fclean:	clean
	$(RM) $(NAME)
#	make -C $(FT) fclean

re:	fclean all

PHONY:	all $(NAME) test clean fclean re
