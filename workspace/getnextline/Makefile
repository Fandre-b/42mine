# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 14:09:43 by fandre-b          #+#    #+#              #
#    Updated: 2023/11/13 21:19:28 by fandre-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

CC = cc
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=n
RM = rm -rf

SRCS = get_next_line.c get_next_line_utils.c

OBJ_DIR = ./obg

OBJS_PATH = $(SRCS:%.c = $(OBJ_DIR)/.o)

all:					$(NAME)

$(OBJ_DIR)/%.o: 			%.c
			mkdir -p 	$(OBJ_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJS_PATH) $(LIBFT_PATH)
			ar rcs		$(NAME) $(OBJS_PATH)

clean:
						$(RM) $(OBJ_DIR)

fclean:					clean
						$(RM) $(NAME)

re:						fclean all

.PHONY:					all bonus clean fclean re