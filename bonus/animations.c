/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:44:06 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/26 00:07:28 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->enemy.current_img = data->enemy.img_1;
	if (i == 10)
		data->enemy.current_img = data->enemy.img_2;
	i++;
	if (i == 20)
		i = 0;
	draw_window(data);
	return (0);
}

int	collectable_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->collectable.current_img = data->collectable.img_1;
	if (i == 5)
		data->collectable.current_img = data->collectable.img_2;
	i++;
	if (i == 10)
		i = 0;
	draw_window(data);
	return (0);
}

int	animate(t_data *data)
{
	enemy_animations(data);
	collectable_animations(data);
	return (0);
}
