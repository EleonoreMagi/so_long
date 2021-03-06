/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:43:50 by dmillan           #+#    #+#             */
/*   Updated: 2022/07/07 18:54:14 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_address_ec(t_data *data)
{
	data->exit.img.addr = mlx_get_data_addr(data->exit.img.img,
			&data->exit.img.bits_per_pixel, &data->exit.img.line_length,
			&data->exit.img.endian);
	data->collectable.img_1.addr
		= mlx_get_data_addr(data->collectable.img_1.img,
			&data->collectable.img_1.bits_per_pixel,
			&data->collectable.img_1.line_length,
			&data->collectable.img_1.endian);
	data->collectable.img_2.addr
		= mlx_get_data_addr(data->collectable.img_2.img,
			&data->collectable.img_2.bits_per_pixel,
			&data->collectable.img_2.line_length,
			&data->collectable.img_2.endian);
	data->collectable.current_img = data->collectable.img_1;
}

void	initialize_address_wpb(t_data *data)
{
	data->wall.img.addr = mlx_get_data_addr(data->wall.img.img,
			&data->wall.img.bits_per_pixel, &data->wall.img.line_length,
			&data->wall.img.endian);
	data->player.img.addr = mlx_get_data_addr(data->player.img.img,
			&data->player.img.bits_per_pixel,
			&data->player.img.line_length, &data->player.img.endian);
	data->bgd.img.addr = mlx_get_data_addr(data->bgd.img.img,
			&data->bgd.img.bits_per_pixel,
			&data->bgd.img.line_length, &data->bgd.img.endian);
}

void	initialize_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->column * TILESIZE,
			data->row * TILESIZE, "So long: plan your escape with rainbows!");
	if (!data->mlx)
		exit_game("Couldn't create new window");
	data->img.img = mlx_new_image(data->mlx, data->column * TILESIZE,
			data->row * TILESIZE);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	initialize_address_ec(data);
	initialize_address_wpb(data);
}

void	draw_window(t_data *data)
{
	t_map	*map;

	map = data->map;
	while (map)
	{
		draw_bgd(data, map->x, map->y);
		if (map->content == PLAYER)
		{
			draw_player(data, map->x, map->y);
			map->content = EMPTY_SPACE;
		}
		if (map->content == WALL)
			draw_walls(data, map->x, map->y);
		if (map->content == EXIT)
			draw_exit(data, map->x, map->y);
		if (map->content == COLLECTABLE)
			draw_collectable(data, map->x, map->y);
		if (map->x == data->player.x && map->y == data->player.y)
			draw_player(data, map->x, map->y);
		map = map->next;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
