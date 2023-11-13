# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 11:10:00 by fandre-b          #+#    #+#              #
#    Updated: 2023/11/11 10:14:31 by fandre-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	libftprintf.a

CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror
RM						=	rm -rf

SRCS					=	ft_printf.c ft_nbr_convert.c

OBJ_DIR					=	./obj

OBJS					=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

all:					$(NAME)

$(OBJ_DIR)/%.o: 		%.c
			mkdir -p 	$(OBJ_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

$(NAME):				$(OBJS)
			ar rcs		$(NAME) $(OBJS)

clean:
						$(RM) $(OBJ_DIR)

fclean:					clean
						$(RM) $(NAME)

re:						fclean all

.PHONY:					all bonus clean fclean re libft