#include "so_long.h"

int	check_rectangle(char *line, int column)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	if (i == column)
		return (1);
	else
		return (0);
}

void	check_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (ft_strnstr(map, ".ber", len) == 0)
		exit_game("Wrong extension, use file with .ber.");
}