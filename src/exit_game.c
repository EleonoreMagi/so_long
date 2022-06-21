#include "so_long.h"

int	exit_game(char *err_message)
{
	if (ft_strnstr(err_message, "Win!", ft_strlen(err_message)))
	{
		ft_printf("\033[0;32;1m");
		ft_printf("%s\n\033[0m", err_message);
		ft_printf("You're the best! Let's play again! \n\033[0m");
		exit(EXIT_SUCCESS);
	}
	if (err_message)
	{
		ft_printf("\033[0;31;1m");
		ft_printf("%s\n\033[0m", err_message);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("\033[0;32;1m");
		ft_printf("It was nice to play! \n\033[0m");
		exit(EXIT_SUCCESS);
	}
}