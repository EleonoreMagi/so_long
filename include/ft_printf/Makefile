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

RM		= rm -f

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): 	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

all: 		$(NAME)

bonus:		all

clean:		
			rm -f $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

rebonus: 	fclean bonus

.PHONY:		all clean fclean re bonus rebonus