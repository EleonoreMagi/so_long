#include "so_long.h"

int	main(int argc, char **argv){
	t_data data;

	initialize_map(&data, argc);
	parse_map(&data, argv[1]);
	check_map(&data);
	load_data(&data);
	create_window(&data);
	push_data(&data);
	mlx_loop_hook(data.mlx, animate, &data);
	hook_events(&data);
	mlx_loop(data.mlx);
	return (0);	
}