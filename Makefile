NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -fsanitize=address
MLXFLAGS	= -framework OpenGL -framework Appkit

LIBFT		= ./include/libft/libft.a
FT_PRINTF	= ./include/ft_printf/libftprintf.a
MLX			= ./include/mlx/libmlx.a

SRCS		= src/main.c \
			src/animations.c \
			src/check_file.c \
			src/check_map.c \
			src/create_window.c \
			src/draw_elements.c \
			src/enemy_func.c \
			src/enemy_movements.c \
			src/exit_game.c \
			src/hook_event.c \
			src/load_data.c \
			src/parse_map.c \
			src/pixel_utils.c \
			include/gnl/get_next_line.c \
			include/gnl/get_next_line_utils.c \


OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(LIBFT):
		$(MAKE) -C ./include/libft
$(FT_PRINTF):
		$(MAKE) -C ./include/ft_printf
$(MLX):
		$(MAKE) -C ./include/mlx

$(NAME): 	$(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) -o $(NAME)
	@echo "\033[92mDone\033[0m"

clean:
	rm -f $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	# $(MAKE) -C include/libft/ clean
	# $(MAKE) -C include/ft_printf/ clean
	# $(MAKE) -C include/mlx/ clean
	@echo "\033[92mClean\033[0m"
	
fclean:		clean
	rm -f $(NAME)
	# @$(MAKE) -C include/libft/ clean
	# @$(MAKE) -C include/ft_printf/ clean
	@echo "\033[92mFclean\033[0m"

re:			fclean all

.PHONY:		all clean fclean re

test:
	./test_script/test.sh

test_all:
	./test_script/test_all.sh