/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:43:53 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/22 21:43:53 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_existance(t_data *data)
{
	t_map	*map;

	map = data->map;
	while (map)
	{
		if (map->content == PLAYER)
		{
			data->player.player_count++;
			data->player.x = map->x;
			data->player.y = map->y;
		}
		if (map->content == COLLECTABLE)
			data->collectable.collectable_count++;
		if (map->content == EXIT)
			data->exit.exit_count++;
		map = map->next;
	}
	if (data->collectable.collectable_count >= 1
		&& data->exit.exit_count >= 1 && data->player.player_count == 1)
		return (1);
	return (0);
}

void	check_map_content(t_map *map, int col, int row)
{
	if (ft_strchr("01CPE", map->content) == 0)
		exit_game("Invalid characters used in the map.");
	if (map->x == 0 || map->y == 0
		|| map->x == col - 1 || map->y == row - 1)
		if (map->content != WALL)
			exit_game("Map is not covered with walls!");
}

void	check_map(t_data *data)
{
	t_map	*map;
	int		column;
	int		row;

	map = data->map;
	column = data->column;
	row = data->row;
	while (map)
	{
		check_map_content(map, column, row);
		map = map->next;
	}
	if (check_map_existance(data) == 0)
		exit_game("Incorrect number of players, exits or collectables!");
}
