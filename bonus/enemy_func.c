/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:44:03 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/25 23:33:29 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_enemy(t_data *data)
{
	int	img_w;
	int	img_h;

	data->enemy.img_1.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/bat-1.xpm", &img_w, &img_h);
	data->enemy.img_2.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/bat-2.xpm", &img_w, &img_h);
}

void	draw_enemy(t_data *data, int col, int row)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < TILESIZE)
	{
		x = 0;
		while (x < TILESIZE)
		{
			color = get_pixel_from_xpm(data->enemy.current_img, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE),
					y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}
