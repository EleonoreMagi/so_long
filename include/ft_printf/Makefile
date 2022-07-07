NAME 	= libftprintf.a

SRCS 	= ft_printf.c \
			ft_flags.c \
			ft_parse_char.c \
			ft_parse_diu.c \
			ft_parse_ptrhex.c \
			ft_types.c \
			ft_utils.c \
			ft_utils2.c

OBJS 	= $(SRCS:.c=.o)

CC = 	gcc

CFLAGS 	= -c -Wall -Wextra -Werror

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): 	$(OBJS)
			@printf $(UP)$(CUT)
			@echo $(Y)Compiling [$(NAME)]...$(X)
			@ar -rcs $(NAME) $(OBJS)
			@echo $(G)Finished [$(NAME)]$(X)
			@echo

all: 		$(NAME)

bonus:		all

clean:		
			@rm -f $(OBJS)
			@echo $(R)Removed ft_print .o $(X)

fclean: 	clean
			@rm -f $(NAME)
			@echo $(R)Removed [$(NAME)]$(X)

re: 		fclean all

rebonus: 	fclean bonus

.PHONY:		all clean fclean re bonus rebonus