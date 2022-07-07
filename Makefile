NAME		= so_long
BONUS		= so_long_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -fsanitize=address
MLXFLAGS	= -framework OpenGL -framework Appkit

LIBFT		= ./include/libft/libft.a
FT_PRINTF	= ./include/ft_printf/libftprintf.a
MLX			= ./include/mlx/libmlx.a

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

SRCS		= src/main.c \
			src/check_file.c \
			src/check_map.c \
			src/create_window.c \
			src/draw_elements.c \
			src/exit_game.c \
			src/hook_event.c \
			src/load_data.c \
			src/parse_map.c \
			src/pixel_utils.c \
			include/gnl/get_next_line.c \
			include/gnl/get_next_line_utils.c \

SRC_BONUS	= bonus/main.c \
			bonus/animations.c \
			bonus/check_file.c \
			bonus/check_map.c \
			bonus/create_window.c \
			bonus/draw_elements.c \
			bonus/enemy_func.c \
			bonus/enemy_movements.c \
			bonus/exit_game.c \
			bonus/hook_event.c \
			bonus/load_data.c \
			bonus/parse_map.c \
			bonus/pixel_utils.c \
			include/gnl/get_next_line.c \
			include/gnl/get_next_line_utils.c \

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRC_BONUS:.c=.o)

all:		$(NAME)

$(LIBFT):
		make -C include/libft all
$(FT_PRINTF):
		make -C include/ft_printf all
$(MLX):
		make -C include/mlx all
		@echo

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<
	@printf $(UP)$(CUT)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	@printf $(UP)$(CUT)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) -o $(NAME)
	@echo
	@echo $(G)Compiling complete$(X)

bonus: 	$(OBJS_BONUS) $(LIBFT) $(FT_PRINTF) $(MLX)
	@printf $(UP)$(CUT)
	@echo
	@echo $(Y)Compiling [$(BONUS)]...$(X)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS_BONUS) $(LIBFT) $(FT_PRINTF) $(MLX) -o $(BONUS)
	@echo
	@echo $(G)Compiling complete$(X)

clean:
	@rm -f $(OBJS)
	@printf $(UP)$(CUT)
	@make -C include/libft/ clean
	@make -C include/ft_printf/ clean
	@make -C include/mlx/ clean
	@rm -f $(OBJS)
	@echo $(R)Removed [$(NAME)]$(X)
	@rm -f $(OBJS_BONUS)
	@echo $(R)Removed [$(BONUS)]$(X)

fclean:	
	@make -C include/libft/ fclean
	@make -C include/ft_printf/ fclean
	@make -C include/mlx/ fclean
	@rm -f $(OBJS)
	@echo $(R)Removed /src .o$(X)
	@rm -f $(OBJS_BONUS)
	@echo $(R)Removed /bonus .o$(X)
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)
	@rm -f $(BONUS)
	@echo $(R)Removed [$(BONUS)]$(X)

re:			fclean all

.PHONY:		all clean fclean re
