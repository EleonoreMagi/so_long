/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:43:28 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/25 23:39:33 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include <unistd.h>

void	initialize_map(t_data *data, int argc)
{
	if (argc < 2)
		exit_game("No map entered, please try again.");
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_game("Failed to start game.");
	data->row = 0;
	data->column = 0;
	data->exit_count = 0;
	data->moves_count = 1;
	data->player.player_count = 0;
	data->enemy.enemy_count = 0;
	data->collectable.collectable_count = 0;
	data->map = NULL;
}

t_map	*insert_content(char content, int x, int y)
{
	t_map	*cur_node;

	cur_node = (t_map *)malloc(sizeof(t_map));
	if (!cur_node)
		exit_game("Malloc failed!");
	cur_node->x = x;
	cur_node->y = y;
	cur_node->content = content;
	cur_node->next = NULL;
	return (cur_node);
}

void	add_new_node(t_map **map, t_map *new_node)
{
	t_map	*tmp;

	tmp = *map;
	if (*map)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	else
		*map = new_node;
}

void	parse_position(t_map **map, char *line, int y)
{
	t_map	*pos;
	int		x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		pos = insert_content(line[x], x, y);
		add_new_node(map, pos);
		x++;
	}
}

void	parse_map(t_data *data, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_game("Cannot read map. Try again!");
	check_extension(map);
	//printf("check!");
	line = get_next_line(fd);
	if (!line)
		exit_game("No lines, invalid map. Try again!");
	data->column = ft_strlen(line) - 1;
	while (line)
	{
		if (check_rectangle(line, data->column) == 0)
			exit_game("Invalid map, no rectangle. Try again!");
		parse_position(&data->map, line, data->row);
		free(line);
		line = get_next_line(fd);
		data->row++;
	}
	free(line);
	close(fd);
}
