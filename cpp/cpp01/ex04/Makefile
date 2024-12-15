# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/14 22:55:49 by fandre-b          #+#    #+#              #
#    Updated: 2024/12/15 16:01:04 by fandre-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = swich_files

CPP = c++
CPP_FLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic
SRC_F = 	main.cpp

OBJ_F = $(SRC_F:.cpp=.o)


all: $(NAME)

$(NAME):$(OBJ_F)
	$(CPP) $(CPP_FLAGS) $(OBJ_F) -o $(NAME) 

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_F)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re