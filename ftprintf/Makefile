# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 11:10:00 by fandre-b          #+#    #+#              #
#    Updated: 2023/11/07 21:01:29 by fandre-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libftprintf.a

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror
RM					=	rm -rf

OBJ_DIR				=	obj
LIBFT_DIR			=	libft

SRCS				=	ft_printf
					
SRC_FILES 			=	$(addsuffix .c, $(SRC))

$(OBJ_DIR):			
			mkdir	./$(OBJ_DIR)

OBJS				=	$(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH			=	./$(LIBFT_DIR)/libft.a					
./%.a: 				$(LIBFT_PATH)%.a
			make -C $(LIBFT_PATH) all
    		cp 		$< ./

$(LIBFT)/%.o:		$(LIBFT_PATH)
			make -C $(LIBFT_PATH) all
			cp 		$< $(DEST_DIR)

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):				$(LIBFT) $(OBJ_DIR) $(OBJS)
				cp		$(LIBFT) $(NAME)
				ar rcs 	$(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft