#include "so_long.h"

	// 1. if player is left_top, moves left top
	// 2.if player is right_top, move right_top
void	check_enemy_movement_top(t_data *data)
{
	static int	i;

	if (data->attacker.y > data->player.y && data->attacker.x > data->player.x)
	{
		if ((i == 1) || (i == 4) || (i == 7))
		{
			attacker_animations(data);
			data->attacker.y--;
			data->attacker.x--;
		}
	}
	if (data->attacker.y > data->player.y && data->attacker.x < data->player.x)
	{
		if ((i == 2) || (i == 5) || (i == 0))
		{
			attacker_animations(data);
			data->attacker.y--;
			data->attacker.x++;
		}
	}
	i++;
	if (i == 8)
		i = 0;
}

void	check_enemy_movement_bottom(t_data *data)
{
	static int	i;

	if (data->attacker.y < data->player.y && data->attacker.x > data->player.x)
	{
		if ((i == 1) || (i == 4) || (i == 7))
		{
			attacker_animations(data);
			data->attacker.x--;
			data->attacker.y++;
		}	
	}
	if (data->attacker.y < data->player.y && data->attacker.x < data->player.x)
	{
		if ((i == 2) || (i == 5) || (i == 0))
		{
			attacker_animations(data);
			data->attacker.x++;
			data->attacker.y++;
		}
	}
	i++;
	if (i == 8)
		i = 0;
}

	// 1. if player is left, move left
	// 2. if player is rightt, move right	
void	check_enemy_movement_sideways(t_data *data)
{
	static int	i;

	if (data->attacker.y == data->player.y && data->attacker.x > data->player.x)
	{
		if ((i == 1) || (i == 4) || (i == 7))
		{
			attacker_animations(data);
			data->attacker.x--;
		}	
	}
	if (data->attacker.y == data->player.y && data->attacker.x < data->player.x)
	{
		if ((i == 2) || (i == 5) || (i == 0))
		{
			attacker_animations(data);
			data->attacker.x++;
		}	
	}
	i++;
	if (i == 8)
		i = 0;
}

	// 1. if player is top, move top
	// 2. if player is bottom, move bottom
void	check_enemy_movement_updown(t_data *data)
{
	static int	i;

	if (data->attacker.x == data->player.x && data->attacker.y > data->player.y)
	{
		if ((i == 1) || (i == 4) || (i == 7))
		{
			attacker_animations(data);
			data->attacker.y--;
		}
	}
	if (data->attacker.x == data->player.x && data->attacker.y < data->player.y)
	{
		if ((i == 2) || (i == 5) || (i == 0))
		{
			attacker_animations(data);
			data->attacker.y++;
		}
	}
	i++;
	if (i == 8)
		i = 0;
}

void	check_enemy_movements(t_data *data)
{
	check_enemy_movement_top(data);
	check_enemy_movement_bottom(data);
	check_enemy_movement_sideways(data);
	check_enemy_movement_updown(data);
}