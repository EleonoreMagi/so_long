/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:43:39 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/22 23:31:57 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_walls(t_data *data)
{
	int	img_w;
	int	img_h;

	data->wall.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/stone.xpm", &img_w, &img_h);
}

void	fill_collectables(t_data *data)
{
	int	img_w;
	int	img_h;

	data->collectable.img_1.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/flower-1.xpm", &img_w, &img_h);
	data->collectable.img_2.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/flower-2.xpm", &img_w, &img_h);
}

void	fill_player(t_data *data)
{
	int	img_w;
	int	img_h;

	data->player.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/unicorn.xpm", &img_w, &img_h);
}

void	fill_exit(t_data *data)
{
	int	img_w;
	int	img_h;

	data->exit.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/rainbow.xpm", &img_w, &img_h);
}

void	load_data(t_data *data)
{
	int	img_w;
	int	img_h;

	data->bgd.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/grass.xpm", &img_w, &img_h);
	fill_player(data);
	fill_collectables(data);
	fill_enemy(data);
	fill_exit(data);
	fill_walls(data);
}
