/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:43:46 by dmillan           #+#    #+#             */
/*   Updated: 2022/07/07 18:52:25 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_bgd(t_data *data, int col, int row)
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
			color = get_pixel_from_xpm(data->bgd.img, x, y);
			pixel_put(&data->img, x + (col * TILESIZE),
				y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data, int col, int row)
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
			color = get_pixel_from_xpm(data->player.img, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE),
					y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	draw_walls(t_data *data, int col, int row)
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
			color = get_pixel_from_xpm(data->wall.img, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE),
					y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	draw_exit(t_data *data, int col, int row)
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
			color = get_pixel_from_xpm(data->exit.img, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE),
					y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	draw_collectable(t_data *data, int col, int row)
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
			color = get_pixel_from_xpm(data->collectable.current_img, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE),
					y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}
