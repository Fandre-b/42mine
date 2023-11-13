# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 11:10:00 by fandre-b          #+#    #+#              #
#    Updated: 2023/11/13 14:02:25 by fandre-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libftprintf.a

CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror -I./libft
RM						=	rm -rf

OBJ_DIR					=	./obj
LIBFT_DIR				=	./libft

SRCS					=	ft_printf.c ft_nbr_convert.c ft_converter.c

OBJS_PATH					=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_PATH				=	$(addprefix $(LIBFT_DIR), /libft.a)

#questoes
###inseri -I path nas flags para dizer onde estão headers do libft
###tambem adicionei libft.h na bibilioteca, preciso disso?
###este libft.h preciso de dizer o dir?
###não é suposto só precisar do file libft.a?
#quando compilamos o novo .a so estamos a colar obj na biblioteca antiga, right?

all:					$(NAME)

$(OBJ_DIR)/%.o: 			%.c
			mkdir -p 	$(OBJ_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH):
			mkdir -p	$(LIBFT_DIR)
			make -C		$(LIBFT_DIR) all

$(NAME):			$(OBJS_PATH) $(LIBFT_PATH)
			cp			$(LIBFT_PATH) $(NAME)
			ar rcs		$(NAME) $(OBJS_PATH)

clean:
			make -C 	$(LIBFT_DIR) clean
						$(RM) $(OBJ_DIR)

fclean:					clean
			make -C 	$(LIBFT_DIR) fclean
						$(RM) $(NAME)


re:						fclean all

.PHONY:					all bonus clean fclean re