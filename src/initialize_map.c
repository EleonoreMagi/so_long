#include "so_long.h"

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
	data->attacker.attacker_count = 0;
	data->collectable.collectable_count = 0;
	data->map = NULL;
}