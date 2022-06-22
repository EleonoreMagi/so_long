#include "so_long.h"

int	attacker_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->attacker.current_img = data->attacker.img_01;
	if (i == 1)
		data->attacker.current_img = data->attacker.img_02;
	i++;
	if (i == 2)
		i = 0;
	push_data(data);
	return (0);
}

int	wall_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->wall.current_img = data->wall.img_01;
	if (i == 1)
		data->wall.current_img = data->wall.img_02;
	i++;
	if (i == 2)
		i = 0;
	push_data(data);
	return (0);
}

int	collectable_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->collectable.current_img = data->collectable.img_01;
	if (i == 5)
		data->collectable.current_img = data->collectable.img_02;
	i++;
	if (i == 10)
		i = 0;
	push_data(data);
	return (0);
}

int	player_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->player.current_img = data->player.img_01;
	if (i == 5)
		data->player.current_img = data->player.img_02;
	i++;
	if (i == 10)
		i = 0;
	push_data(data);
	return (0);
}

int	animations(t_data *data)
{
	attacker_animations(data);
	wall_animations(data);
	player_animations(data);
	collectable_animations(data);
	return (0);
}