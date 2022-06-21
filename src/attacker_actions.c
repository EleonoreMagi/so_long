#include "so_long.h"

void	fill_attacker(t_data *data)
{
	int	img_w;
	int	img_h;

	data->attacker.img_1.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/bat.xpm", &img_w, &img_h);
	data->attacker.img_2.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/bat_open_wings.xpm", &img_w, &img_h);
}

void	draw_attacker(t_data data, int col, int row)
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
			color = get_pixel_from_xpm(data->attacker.current_img, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE),
							y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}