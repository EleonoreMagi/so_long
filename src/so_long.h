/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:41:37 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/22 21:41:37 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/libft/libft.h"
# include "../include/ft_printf/ft_printf.h"
# include "../include/mlx/mlx.h"
# include "../include/gnl/get_next_line.h"

# include <errno.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <stdio.h>

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

typedef struct s_enemy {
	int		enemy_count;
	int		x;
	int		y;
	t_img	current_img;
	t_img	img_1;
	t_img	img_2;
}	t_enemy;

typedef struct s_wall {
	t_img	current_img;
	t_img	img;
}	t_wall;

typedef struct s_exit {
	t_img	current_img;
	t_img	img;
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
	t_enemy			enemy;
	t_collectable	collectable;
	int				row;
	int				column;
}	t_data;

void			initialize_map(t_data *data, int argc);
void			parse_map(t_data *data, char *map);
void			check_map(t_data *data);
int				exit_game(char *err_message);
void			pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_pixel_from_xpm(t_img xpm, int x, int y);
void			hook_event(t_data *data);
int				check_movement(t_data *data, int row, int col, char *move);
void			load_data(t_data *data);
void			draw_bgd(t_data *data, int col, int row);
void			draw_player(t_data *data, int col, int row);
void			draw_walls(t_data *data, int col, int row);
void			draw_exit(t_data *data, int col, int row);
void			draw_collectable(t_data *data, int col, int row);
void			draw_enemy(t_data *data, int col, int row);
int				enemy_animations(t_data *data);
int				animate(t_data *data);
void			draw_window(t_data *data);
void			check_extension(char *map);
int				check_rectangle(char *line, int column);
void			check_enemy_movements(t_data *data);
void			check_death(t_data *data);
void			fill_enemy(t_data *data);

#endif