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
CFLAGS := -Wall -Wextra -Werror -std=c99
VAL := valgrind --leak-check=full --show-leak-kinds=all -s

FT := libft
OBJ_DIR := obj
INCLUDES_DIR := includes

SRCS := ./test.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

#########not mine
# mlx library
#ifeq ($(OS), Linux)
MLX		= ./minilibx-linux/
MLX_LNK	= -L $(MLX) -lmlx -lXext -lX11
#else
#	MLX		= ./miniLibX/
#	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
#endif

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# ft library
FT_LIB	= $(addprefix $(FT)/,libft.a)
#FT_INC	= -I $(FT)
FT_LNK	= -L $(FT) -l ft -l pthread
#########not mine
#$(FT_INC)
#$(FT_LNK)

all:	$(NAME)

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MLX_INC) -I $(INCLUDES_DIR) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) -lm -o $(NAME)

test:
	@echo "<Still need to set up>"

clean:
	$(RM) $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean:	clean
	$(RM) $(NAME)
	make -C $(FT) fclean

re:	fclean all

PHONY:	all $(NAME) test clean fclean re