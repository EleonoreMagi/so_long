#include "so_long.h"

void initialize_address(t_data *data)
{
	data->exit.img.addr = mlx_get_data_addr(data->exit.img.img,
			&data->exit.img.bits_per_pixel, &data->exit.img.line_length,
			&data->exit.img.endian);
	data->collectable.img_01.addr = mlx_get_data_addr(data->collectable.img_01.img,
			&data->collectable.img_01.bits_per_pixel, 
			&data->collectable.img_01.line_length, &data->collectable.img_01.endian);
	data->collectable.img_02.addr = mlx_get_data_addr(data->collectable.img_02.img,
		&data->collectable.img_02.bits_per_pixel,
		&data->collectable.img_02.line_length, &data->collectable.img_02.endian);
	data->wall.img.addr = mlx_get_data_addr(data->wall.img.img,
		&data->wall.img.bits_per_pixel, &data->wall.img.line_length,
		&data->wall.img.endian);
	data->player.img.addr = mlx_get_data_addr(data->player.img.img,
		&data->player.img.bits_per_pixel,
		&data->player.img.line_length, &data->player.img.endian);
	data->attacker.img_01.addr = mlx_get_data_addr(data->attacker.img_01.img,
			&data->attacker.img_01.bits_per_pixel, 
			&data->attacker.img_01.line_length, &data->attacker.img_01.endian);
	data->attacker.img_02.addr = mlx_get_data_addr(data->attacker.img_02.img,
		&data->attacker.img_02.bits_per_pixel,
		&data->attacker.img_02.line_length, &data->attacker.img_02.endian);
	data->attacker.current_img = data->attacker.img;
}

void	initialize_window(t_data *data)
{
	data_mlx_win = mlx_new_window(data->mlx, data->column * TILESIZE,
			data->row * TILESIZE, "so_long");
	if (!data->mlx)
		exit_game("Couldn't create new window");
	data->img.img = mlx_new_image(data->mlx, data->column * TILESIZE,
			data->row * TILESIZE);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	data->background.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	initialize_address(data);
}

void create_window(t_data *data)
{
	t_map *map;

	initialize_window(data);
	map = data->map;
	while (map)
	{
		draw_bgd(data, map->x, map->y);
		draw_player(data, map->x, map->y);
		if (map->content == WALL)
			draw_walls(data, map->x, map->y);
		if (map->content == EXIT)
			draw_exit(data, map->x, map->y);
		if (map->content == COLLECTABLE)
			draw_collectable(data, map->x, map->y);
		if (data->attacker.attacker_count >= 1)
			draw_attacker(data, data->attacker.x, data->attacker.y);
		map = map->next;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}