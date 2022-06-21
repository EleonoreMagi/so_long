#include "so_long.h"

void	fill_walls(t_data *data)
{
	int	img_w;
	int	img_h;

	data->wall.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/wall.xpm", &img_w, &img_h);
}

void	fill_collectables(t_data *data)
{
	int	img_w;
	int	img_h;

	data->exit.img_1.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/collectables_1.xpm", &img_w, &img_h);
	data->exit.img_2.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/collectables_2.xpm", &img_w, &img_h);
}

void	fill_player(t_data *data)
{
	int	img_w;
	int	img_h;

	data->exit.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/player.xpm", &img_w, &img_h);
}

void	fill_exit(t_data *data)
{
	int	img_w;
	int	img_h;

	data->exit.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/exit_01.xpm", &img_w, &img_h);
}

void	load_data(t_data *data)
{
	int	img_w;
	int	img_h;

	data->bgd.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/background.xpm", &img_w, &img_h);
	fill_player(data);
	fill_collectables(data);
	fill_attacker(data);
	fill_o_attacker(data);
	fill_exit(data);
	fill_walls(data);
}

