#include "../game.h"

void            pixel_put(t_all *data, int x, int y, int color)
{
	char    *dst;

	dst = data->win->addr + (y * data->win->line_length + x * (data->win->bits_per_pixel / 8));
	*(int*)dst = color;
}

void	put_rectangle(t_all *all, int start_x, int start_y, int end_x, int end_y)
{
	int x;
//	mlx_clear_window(all->win->mlx, all->win->win);
	x = start_x;
	while (start_y < end_y)
	{
		while (start_x < end_x)
			pixel_put(all, start_x++, start_y, 0x0000FF00);
		start_x = x;
		start_y += 1;
	}
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
//	mlx_destroy_image(all->win->mlx, all->win->img);
}