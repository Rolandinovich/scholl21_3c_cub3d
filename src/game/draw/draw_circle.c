#include "../game.h"

void	texture_column(t_img img, int **column, int column_height, const size_t texcoord)
{
	size_t y;
	size_t pix_x;
	size_t pix_y;
	int x;

	y = 0;
	while(y<column_height)
	{
		pix_x = texcoord;
		pix_y = (y*img.height)/column_height;
		x = img.data[(int)((int)pix_x + (int)pix_y *
			(img.width))];
//		(*column)[y] = img.data[(int)((int)pix_x + (int)pix_y *
//			(img.width))];
		y++;
	}
}

void	draw_textures(t_all all)
{
	float agile;
	size_t i;
	int j;
	t_player plr;
	size_t column_height;
	char texture;
	int column[all.win_h];
	float textcord;
	int pix_y;

	i = 0;
	plr = all.player;
	while (i < all.win_w)
	{
		agile = plr.dir - plr.fov/2 + plr.fov * i / (float)all.win_w;
		column_height = calc_text_distance(all, agile, &texture, &textcord);
		texture_column(all.textures[texture], (int**)&column, column_height, textcord);
		j = 0;
		while (j < column_height)
		{
			pix_y = j + all.win_h/2-column_height/2;
			if (pix_y < 0 || pix_y >= all.win_w) continue;
			pixel_put(&all, i, pix_y,column[j]);
			j++;
		}
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
		column_height = calc_sprite_distance(all, agile);
		if (column_height != -1)
			put_rectangle(&all, i, all.win_h/2 - column_height*0.3,\
			i + 1, all.win_h/2 + column_height*0.6, 0xCCCCCCCC);
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