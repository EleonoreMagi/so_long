NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -fsanitize=address
MLXFLAGS	= -framework OpenGL -framework Appkit

LIBFT		= ./include/libft/libft.a
FT_PRINTF	= ./include/ft_printf/libftprintf.a
MLX			= ./mlx/libmlx.a

SRCS		= src/main.c \
			src/initialize_map.c \
			src/check_map.c \
			src/hook_events.c \
			src/exit_game.c \
			src/create_window.c \
			src/load_data.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			src/map_parsing.c \
			src/check_errors.c \
			src/put_images.c \
			src/attacker_info.c \
			src/pixel_functions.c \
			src/push_data.c \
			src/animations.c \
			src/check_enemy_movements.c \
			src/initialize_attacker.c \
			src/attacker_animations.c \


OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(LIBFT):
		$(MAKE) -C ./libft
$(FT_PRINTF):
		$(MAKE) -C ./ft_printf
$(MLX):
		$(MAKE) -C ./mlx

$(NAME): 	$(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) -o $(NAME)
	@echo "\033[92mDone\033[0m"

clean:
	rm -f $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	# $(MAKE) -C libft/ clean
	# $(MAKE) -C ft_printf/ clean
	# $(MAKE) -C mlx/ clean
	@echo "\033[92mClean\033[0m"
	
fclean:		clean
	rm -f $(NAME)
	# @$(MAKE) -C libft/ clean
	# @$(MAKE) -C ft_printf/ clean
	@echo "\033[92mFclean\033[0m"

re:			fclean all

.PHONY:		all clean fclean re

test:
	./test_script/test.sh

test_all:
	./test_script/test_all.sh