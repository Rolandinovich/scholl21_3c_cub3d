#include "../game.h"

void            pixel_put(t_all *data, int x, int y, int color)
{
	char    *dst;

	dst = data->win->addr + (y * data->win->line_length + x * (data->win->bits_per_pixel / 8));
	*(int*)dst = color;
}

void	put_rectangle(t_all *all, t_place place, t_place end)
{
	int x;

	mlx_clear_window(all->win->mlx, all->win->win);
	x = place.x;
	while (place.y < end.y)
	{
		while (place.x < end.x)
			pixel_put(all, place.x++, place.y, 0x0000FF00);
		place.x = x;
		place.y += 1;
	}
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
//	mlx_destroy_image(all->win->mlx, all->win->img);
}