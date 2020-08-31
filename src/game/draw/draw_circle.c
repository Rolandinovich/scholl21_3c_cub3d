#include "../game.h"

void	draw_textures(t_all all)
{
	float agile;
	size_t i;
	t_player plr;
	size_t column_height;

	i = 0;
	plr = all.player;
	while (i < all.win_w)
	{
		agile = plr.dir - plr.fov/2 + plr.fov * i / (float)all.win_w;
		column_height = calc_distance(all, agile , '1');
		put_rectangle(&all, i, all.win_h/2 - column_height*0.6, i + 1, all.win_h/2 + column_height*0.6, 0x0000FF00);
		i++;
	}
}

void	draw_sprites(t_all all)
{
	float agile;
	size_t i;
	t_player plr;
	size_t column_height;

	i = 0;
	plr = all.player;
	while (i < all.win_w)
	{
		agile = plr.dir - plr.fov/2 + plr.fov * i / (float)all.win_w;
		column_height = calc_distance(all, agile , '2');
		put_rectangle(&all, i, all.win_h/2 - column_height*0.6, i + 1, all.win_h/2 + column_height*0.6, 0xCCCCCCCC);
		i++;
	}
}


void	draw_circle(t_all all)
{
	for (all.player.dir = 0.1; all.player.dir <= M_PI*2; all.player.dir +=0.1)
	{
		draw_f_c(all);
		draw_textures(all);
//		draw_sprites(all);
		mlx_put_image_to_window(all.win->mlx, all.win->win, all.win->img, 0, 0);
	}
}