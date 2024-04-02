# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:45:24 by mpais-go          #+#    #+#              #
#    Updated: 2024/02/09 19:39:17 by mpais-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c ft_putchar.c ft_putstr.c \
			ft_putadd.c ft_putnbr.c ft_putuns.c \
			ft_puthexa.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)

.c.o:
	@$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

$(NAME): $(OBJECTS)
	@$(AR) $(NAME) $(OBJECTS)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re