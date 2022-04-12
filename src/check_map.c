#include "so_long.h"

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
	if (check_content_existance(data) == 0)
		exit_game("There are not enough players, exits or collectables!");
}