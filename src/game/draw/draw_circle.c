#include "../game.h"

void	texture_column(t_all all, t_img img, int column_height, const size_t texcoord, size_t win_x)
{
	size_t y;
	size_t pix_x;
	size_t pix_y;
	size_t win_y;

	y = 0;
	while(y<column_height)
	{
		pix_x = texcoord;
		pix_y = (y*img.height)/column_height;
		win_y = y + all.win_h/2-column_height/2;
		if ((win_y < 0 || win_y >= all.win_h) && (y += 1))
			continue;
		pixel_put(&all, win_x, win_y,img.data[(int)((int)pix_x + (int)pix_y *
			(img.width))]);
		y++;
	}
}

void	draw_textures(t_all all)
{
	float agile;
	size_t i;
	t_player plr;
	size_t column_height;
	char texture;
	float textcord;

	i = 0;
	plr = all.player;
	while (i < all.win_w)
	{
		agile = plr.dir - plr.fov/2 + plr.fov * i / (float)all.win_w;
		column_height = calc_text_distance(all, agile, &texture, &textcord);
		texture_column(all, all.textures[texture],column_height, textcord, i);
		i++;
	}
}

void	draw_sprites(t_all all)
{
	float agile;
	size_t i;
	t_player plr;
	int column_height;
	float textcord;

	i = 0;
	plr = all.player;
	while (i < all.win_w)
	{
		agile = plr.dir - plr.fov/2 + plr.fov * i / (float)all.win_w;
		column_height = calc_sprite_distance(all, agile);
		if (column_height > 0)
			texture_column(all, all.sprite, column_height, textcord, i);
		i++;
	}
}


void	draw_circle(t_all all)
{
	for (all.player.dir = 0.1; all.player.dir <= M_PI*2; all.player.dir +=0.1)
	{
		draw_f_c(all);
		draw_textures(all);
		draw_sprites(all);
		mlx_put_image_to_window(all.win->mlx, all.win->win, all.win->img, 0, 0);
	}
}