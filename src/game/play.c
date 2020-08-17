#include "game.h"

int		start_game()
{
	t_plr	plr;
	t_key	key;
	t_win 	win;
	t_all	all;
	t_place place;
	int 	idx=0;

	ft_bzero(&key, sizeof(t_key));
	all.key = &key;
	ft_bzero(&plr, sizeof(t_plr));
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1000, 512, "CUB2D");
	win.img = mlx_new_image(win.mlx, 1000, 512);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.endian);
	all.win = &win;
	place.x = 0;
	place.y = 0;
	while (place.x <= 100) {
		put_rectangle(&all, place);
		sleep(1);
		place.y = 0;
		win.img = mlx_new_image(win.mlx, 1000, 512);
		win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.endian);
		all.win = &win;
		place.x += 5;
	}
	mlx_loop(win.mlx);
}