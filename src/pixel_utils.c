#include "so_long.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

unsigned int	get_pixel_from_xpm(t_img xpm, int x, int y)
{
	char	*dest;

	dest = xpm.addr + (y * xpm.line_length + x * (xpm.bits_per_pixel / 8));
	return (*(unsigned int *)dest);
}