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

NAME			:= pipex
BONUS_NAME		:= checker
DEBUG_NAME		:= debug

CC := gcc
RM := -@rm -f
CFLAGS := -Wall -Wextra -Werror -std=c99
VAL := valgrind --leak-check=full --show-leak-kinds=all -s

OBJ_DIR := obj
INCLUDES_DIR := includes

SRCS := src/ft_get_next_line.c src/ft_extract_info.c src/ft_pipex.c src/ft_split.c src/ft_exe_program.c src/ft_libft_utils.c src/ft_libft_utils2.c
#src/ft_gnl.c
BONUS := src/ft_get_next_line.c src/ft_extract_info.c src/ft_pipex.c src/ft_split.c src/ft_exe_program.c src/ft_libft_utils.c src/ft_libft_utils2.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJ_BONUS := $(addprefix $(OBJ_DIR)/, $(BONUS:.c=.o))

all:	$(NAME)

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@ -g

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS_NAME)

$(DEBUG_NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(DEBUG_NAME) -g
	gdb -ex "layout split" ./$(DEBUG_NAME) -q

test:	re bonus
	@echo "\n<To be made>\n"

clean:
	$(RM) -rf $(OBJ_DIR)
	@echo "Objects removed"

fclean:	clean
	$(RM) $(NAME) $(BONUS_NAME) $(DEBUG_NAME)
	@echo "Executable removed"

re:	fclean all

PHONY:	all $(NAME) bonus test clean fclean re
