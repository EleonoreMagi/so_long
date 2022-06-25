/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:43:36 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/26 00:29:07 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_movement(t_data *data, int row, int col, char *move)
{
	t_map	*map;

	map = data->map;
	ft_printf("\033[0;35m%s\033[0m | \033[0;36m%d\n\033[0m", \
	move, data->moves_count++);
	while (map)
	{
		if (map->x == row && map->y == col && map->content != WALL)
		{
			if (map->content == COLLECTABLE)
			{
				data->collectable.collectable_count--;
				map->content = EMPTY_SPACE;
			}
			if (map->content == EXIT)
				if (data->collectable.collectable_count == 0)
					exit_game("Win!");
			return (1);
		}
		check_death(data);
		map = map->next;
	}
	return (0);
}

char	*key(int move)
{
	char	*action;

	if (move == DOWN)
		action = "Down ";
	if (move == UP)
		action = "Up ";
	if (move == RIGHT)
		action = "Right ";
	if (move == LEFT)
		action = "Left ";
	return (action);
}

int	hook_key(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_win, data->mlx_win);
		exit_game("Exit game...");
	}
	if (keycode == DOWN)
		if (check_movement(data, data->player.x, data->player.y + 1, key(DOWN)))
		{
			ft_printf("check - down\n");
			data->player.y += 1;
		}
	if (keycode == UP)
		if (check_movement(data, data->player.x, data->player.y - 1, key(UP)))
			data->player.y -= 1;
	if (keycode == RIGHT)
		if (check_movement(data, data->player.x + 1,
				data->player.y, key(RIGHT)))
			data->player.x += 1;
	if (keycode == LEFT)
		if (check_movement(data, data->player.x - 1, data->player.y, key(LEFT)))
			data->player.x -= 1;
	check_enemy_movements(data);
	draw_window(data);
	return (0);
}

void	hook_event(t_data *data)
{
	mlx_key_hook(data->mlx_win, hook_key, data);
	mlx_hook(data->mlx_win, 17, (1L << 17), exit_game, "Exit game");
}
