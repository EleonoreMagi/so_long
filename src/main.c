/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:43:23 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/22 21:43:23 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	initialize_map(&data, argc);
	parse_map(&data, argv[1]);
	check_map(&data);
	load_data(&data);
	draw_window(&data);
	mlx_loop_hook(data.mlx, animate, &data);
	hook_event(&data);
	mlx_loop(data.mlx);
	return (0);
}
