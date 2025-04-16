# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/14 22:55:49 by fandre-b          #+#    #+#              #
#    Updated: 2025/04/16 11:01:33 by fandre-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

CPP = c++
CPP_FLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic
SRC_F = 	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

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