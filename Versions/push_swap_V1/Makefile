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

NAME			= push_swap.a
TEST_NAME		= push_swap

RANDOM_NUMBERS := $(shell shuf -i 1-500 -n 100)

SRCS			= push_swap.c lst_manipulation.c ft_sorter.c

BONUS			=

OBJS			= $(SRCS:.c=.o)

CC				= @cc
VAL				= -@valgrind --leak-check=full
RM				= @rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c99

%.o:            %.c
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

test:			$(NAME)
				$(CC) $(CFLAGS) $(OBJS) -o $(TEST_NAME)
				@echo "Number of movements: $$(./push_swap $(RANDOM_NUMBERS) | wc -l)"
				$(VAL) ./push_swap $(RANDOM_NUMBERS) > output.txt 2>&1
#				$(VAL) ./push_swap 42 1 36 37 52 60 70 57 61 86 > output.txt 2>&1
#				@grep -B 2 "HEAP SUMMARY" output.txt | awk 'NR==1'
				@grep "total heap usage" output.txt
				@grep -A 2 "total heap usage" output.txt | tail -n 1
				$(RM) output.txt $(TEST_NAME)
				
			
debug:			$(NAME)
				@gcc -g $(CFLAGS) -o $(TEST_NAME) $(OBJS)
				@gdb ./push_swap

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all test debug clean fclean re
