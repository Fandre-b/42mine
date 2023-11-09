# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 11:10:00 by fandre-b          #+#    #+#              #
#    Updated: 2023/11/08 22:07:06 by fandre-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	libftprintf.a

CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror
RM						=	rm -rf

SRCS					=	ft_printf.c

INCLUDES				=	libft.a

OBJ_DIR					=	./obj
LIBFT_DIR				=	./libft
INCLUDE_DIR				=	./includes

OBJS					=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

all:					$(NAME)

$(OBJ_DIR)/%.o: 		%.c
			mkdir -p 	$(OBJ_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

$(INCLUDE_DIR)/$(INCLUDES):
			mkdir -p	$(INCLUDE_DIR)
			make -C		$(LIBFT_DIR) all
			mv			$(LIBFT_DIR)/$(INCLUDES) $(INCLUDE_DIR)

$(NAME):				$(INCLUDE_DIR)/$(INCLUDES) $(OBJS)
			mkdir -p 	$(OBJ_DIR)
			ar rcs		$(NAME) $(OBJS) $(INCLUDE_DIR)/$(INCLUDES)

clean:
			make -C 	$(LIBFT_DIR) clean
						$(RM) $(OBJ_DIR)

fclean:					clean
			make -C 	$(LIBFT_DIR) fclean
						$(RM) $(NAME)
						$(RM) $(INCLUDE_DIR)

re:						fclean all

.PHONY:					all bonus clean fclean re libft