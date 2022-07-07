/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:43:43 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/28 03:47:57 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(char *err_message)
{
	if (ft_strnstr(err_message, "Win!", ft_strlen(err_message)))
	{
		ft_printf("\033[0;32;1m");
		ft_printf("%s\n", err_message);
		ft_printf("You're the best! Let's play again! \n\033[0m");
		exit(EXIT_SUCCESS);
	}
	else if (ft_strnstr(err_message,
			"Player got caught! Try again!", ft_strlen(err_message))
		|| ft_strnstr(err_message, "Exited game", ft_strlen(err_message)))
	{
		ft_printf("\033[0;31;1m%s\n", err_message);
		exit(EXIT_SUCCESS);
	}
	else if (err_message)
	{
		ft_printf("\033[0;31;1m");
		ft_printf("Error\n%s\n\033[0m", err_message);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("It was nice to play!\n");
		exit(EXIT_SUCCESS);
	}
}
