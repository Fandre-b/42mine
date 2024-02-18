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

RANDOM_NUMBERS := $(shell shuf -i 1-100 -n 10)

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

teste:			$(NAME)
				$(CC) $(CFLAGS) $(OBJS) -o $(TEST_NAME)
#				$(VAL) ./push_swap $(RANDOM_NUMBERS) > output.txt 2>&1
				$(VAL) ./push_swap 42 1 36 37 52 60 70 57 61 86 > output.txt 2>&1
				./push_swap 42 1 36 37 52 60 70 57 61 86
				@grep -B 2 "HEAP SUMMARY" output.txt | awk 'NR==1'
				@grep "total heap usage" output.txt
				@grep -A 2 "total heap usage" output.txt | tail -n 1
				$(RM) output.txt
				
			
debug:			$(NAME)
				@gcc -g $(CFLAGS) -o $(TEST_NAME) $(OBJS)
				@gdb ./push_swap

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)
				@echo "created"

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all teste debug clean fclean re
