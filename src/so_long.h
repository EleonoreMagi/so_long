#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/libft/libft.h"
# include "../include/ft_printf/ft_printf.h"
# include "../include/mlx/mlx.h"
# include "../include/gnl/get_next_line.h"

# include <errno.h>
# include <stddef.h>

# define TILESIZE 32

typedef enum e_keycode {
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	ESC = 53,
}	t_keycode;

typedef enum e_mapcode {
	EMPTY_SPACE = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	EXIT = 'E',
	PLAYER = 'P',
	ATTACKER = 'A',
}	t_mapcode;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map {
	int				x;
	int				y;
	char			content;
	struct s_map	*next;
}	t_map;

typedef struct s_collectable {
	int		collectable_count;
	t_img	current_img;
	t_img	img_1;
	t_img	img_2;
}	t_collectable;

typedef struct s_player {
	int		player_count;
	int		x;
	int		y;
	t_img	current_img;
	t_img	img;
}	t_player;

typedef struct s_attacker {
	int		attacker_count;
	int		x;
	int		y;
	t_img	current_img;
	t_img	img_1;
	t_img	img_2;
}	t_attacker;

typedef struct s_wall {
	t_img	current_img;
	t_img	img;
}	t_wall;

typedef struct s_exit {
	t_img	current_img;
	t_img	img_1;
	t_img	img_2;
}	t_exit;

typedef struct s_data {
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	int				exit_count;
	int				moves_count;
	t_map			*map;
	t_img			bgd;
	t_exit			exit;
	t_wall			wall;
	t_player		player;
	t_attacker		attacker;
	t_collectable	collectable;
	int				row;
	int				column;
}	t_data;

#endif