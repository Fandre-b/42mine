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

SRCS			= push_swap.c lst_manipulation.c ft_sorter.c

OBJS			= $(SRCS:.c=.o)

CC				= @cc
RM				= @rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c99

%.o:            %.c
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

teste:			$(NAME)
				$(CC) $(CFLAGS) $(OBJS) -o $(TEST_NAME)
			
debug:			$(NAME)
				@gcc -g $(CFLAGS) -o $(TEST_NAME) $(OBJS)
				@gdb ./$(TEST_NAME)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)
				@echo "created"

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all teste clean fclean re
