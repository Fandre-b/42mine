NAME 				=	so_long

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -g -I $(INCLUDES)
SANITIZE			=	-fsanitize=address,undefined
RANDOM_MALLOC		=	-Xlinker --wrap=malloc
AR					=	ar rcs
RM					=	rm -rf

SRCS				=	aux_walls.c check.c end_game.c images.c main.c moves.c parser.c units.c
SRCS_PATH			=	srcs/

OBJ_DIR				=	objects/
OBJS				=	$(SRCS:%.c=$(OBJ_DIR)%.o)
ALL_OBJS			=	$(OBJ_DIR)*.o

INCLUDES			=	includes/

MLX_PATH			=	libs/minilibx-linux/
MLX					=	$(MLX_PATH)libmlx_Linux.a
LIBFT_PATH			=	libs/Libft/
LIBFT				=	$(LIBFT_PATH)libft.a
FT_PRINTF_PATH		=	libs/ft_printf/
FT_PRINTF			=	$(FT_PRINTF_PATH)libftprintf.a
GNL					=	libs/get_next_line/get_next_line_bonus.c libs/get_next_line/get_next_line_utils_bonus.c
PERSONAL_LIBS		=	-lft -lftprintf
OTHER_LIBS			=	-lmlx -lXext -lX11 -lm -lz

$(OBJ_DIR)%.o:		$(SRCS_PATH)%.c
					@$(CC) $(CFLAGS) -I /usr/local/include -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(LIBFT) $(FT_PRINTF) $(MLX) $(OBJS)
					@$(CC) $(CFLAGS) $(OBJS) $(GNL) -L$(LIBFT_PATH) -L$(FT_PRINTF_PATH) -L$(MLX_PATH) $(PERSONAL_LIBS) $(OTHER_LIBS) -o $(NAME)
					@echo "$(GREEN)$(NAME)$(DEFAULT) successfully created"

sanitize:			$(OBJ_DIR) $(LIBFT) $(GNL) $(FT_PRINTF) $(MLX) $(OBJS)
					@$(CC) $(CFLAGS) $(SANITIZE) $(OBJS) $(GNL) -L$(LIBFT_PATH) -L$(FT_PRINTF_PATH) -L$(MLX_PATH) $(PERSONAL_LIBS) $(OTHER_LIBS) -o $(NAME)
					@echo "$(GREEN)$(NAME)$(DEFAULT) successfully created"

random_m:			$(OBJ_DIR) $(LIBFT) $(GNL) $(FT_PRINTF) $(MLX) $(OBJS)
					@$(CC) $(CFLAGS) $(SANITIZE) $(RANDOM_MALLOC) $(OBJS) $(GNL) -L$(LIBFT_PATH) -L$(FT_PRINTF_PATH) -L$(MLX_PATH) $(PERSONAL_LIBS) $(OTHER_LIBS) -o $(NAME)
					@echo "$(GREEN)$(NAME)$(DEFAULT) successfully created"

$(MLX):
					@make -s -C $(MLX_PATH) all

$(LIBFT):
					@make -s -C $(LIBFT_PATH) all

$(FT_PRINTF):
					@make -s -C $(FT_PRINTF_PATH) all

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					@$(RM) $(OBJ_DIR)
					@echo "$(RED)$(OBJ_DIR)$(DEFAULT) deleted"

fclean:				clean
					@$(RM) $(LIBFT)
					@echo "$(RED)$(LIBFT)$(DEFAULT) deleted"
					@$(RM) $(FT_PRINTF)
					@echo "$(RED)$(FT_PRINTF)$(DEFAULT) deleted"
					@$(RM) $(MLX)
					@echo "$(RED)$(MLX)$(DEFAULT) deleted"
					@$(RM) $(NAME)
					@echo "$(RED)$(NAME)$(DEFAULT) deleted"

re:					fclean all

.PHONY:				all bonus clean fclean re

GREEN				=	\033[32m
RED					=	\033[31m
DEFAULT				=	\033[0m