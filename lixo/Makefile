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

#TODO Adicionar os vddrs ficheiros.
#TODO reordenar header functions pelos ficheiros.
#TODO adicionar static qd nao usamos fora do scope.
#TODO arranjar test e debug rules.
NAME			= push_swap
BONUS_NAME		= checker

# RANDOM_NUMBERS	:= $(shell shuf -i 1-500 -n 500)
RANDOM_NUMBERS	:= 1 5 2 4 3

CC = @cc
RM = @rm -f
CFLAGS = -Wall -Wextra -Werror -std=c99
VAL = -@valgrind --leak-check=full

OBJ_DIR = obj
INCLUDES_DIR = includes

SRCS_DIR = srcs
CHECK_DIR = bonus
UTILS_DIR = utils
MOV_DIR = list_moves

SRCS_PUSH =	ft_push_swap.c ft_sorter.c ft_sorter_utils.c
SRCS_CHECK = bonus.c ft_gnl.c
SRCS_UTILS = ft_split.c ft_lst_general_utils.c ft_general_utils.c
SRCS_MOVS = ft_lst_moves_push.c ft_lst_moves_revrot.c ft_lst_moves_rot.c ft_lst_moves_swap.c

SRCS_UTILS_DIR = $(addprefix $(UTILS_DIR)/,$(SRCS_UTILS))
SRCS_MOVS_DIR = $(addprefix $(MOV_DIR)/,$(SRCS_MOVS))

SRCS = $(SRCS_PUSH) $(SRCS_UTILS_DIR) $(SRCS_MOVS_DIR)
SRCS_BONUS = $(SRCS_CHECK) $(SRCS_UTILS_DIR) $(SRCS_MOVS_DIR) 

SRCS_SRCS_DIR = $(addprefix $(SRCS_DIR)/,$(SRCS))
SRCS_BONUS_DIR = $(addprefix $(CHECK_DIR)/,$(SRCS_BONUS))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS_SRCS_DIR:%.c=%.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/,$(SRCS_BONUS_DIR:%.c=%.o))

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $(OBJS))
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

all: $(NAME) bonus

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJ_W_DIR)
	$(CC) $(CFLAGS) $(OBJ_W_DIR) -o $(BONUS_NAME)

test: $(NAME) bonus
	@echo "Number of movements: $$(./$(NAME) $(RANDOM_NUMBERS) | wc -l)"
	$(VAL) ./$(NAME) $(RANDOM_NUMBERS) > output.txt 2> /dev/null #2>&1
	@grep -B 2 "HEAP SUMMARY" output.txt | awk 'NR==1'
	@grep "total heap usage" output.txt
	@grep -A 2 "total heap usage" output.txt | tail -n 1
	./$(NAME) $(RANDOM_NUMBERS) > output.txt 2> /dev/null #2>&1
	#repeat all for checker using output of prev.
	$(VAL) ./$(BONUS_NAME) $(RANDOM_NUMBERS) < output.txt > output2.txt 2> /dev/null #2>&1
	@grep -B 2 "HEAP SUMMARY" output2.txt | awk 'NR==1'
	@grep "total heap usage" output2.txt
	@grep -A 2 "total heap usage" output2.txt | tail -n 1
	./$(BONUS_NAME) $(RANDOM_NUMBERS) < output.txt > output2.txt 2> /dev/null #2>&1
	$(RM) output.txt output2.txt
	$(MAKE) fclean

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus test debug clean fclean re
