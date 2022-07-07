# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 17:20:08 by tblaase           #+#    #+#              #
#    Updated: 2022/06/28 20:27:22 by dmillan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# colors for printing
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

%.o : %.c
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
	@printf $(UP)$(CUT)
	@echo $(Y)Compiling [$<]...$(X)
%.o : %.m
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
	@printf $(UP)$(CUT)
	@echo $(Y)Compiling [$<]...$(X)

CFLAGS+= -DSTRINGPUTX11

all: $(NAME)

$(NAME): $(OBJ)
	@printf $(UP)$(CUT)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@rm -f $(OBJ)
	@echo $(R)Removed mlx .o$(X)

fclean: clean
	@rm -f $(NAME) *~
	@rm -f mlx_app
	@echo $(R)Removed [$(NAME)]$(X)

re: clean all
