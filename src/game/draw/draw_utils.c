#include "../game.h"

float	calc_text_distance(t_all all, float agile, char *texture, float *textcord)
{
	float		t;
	t_player	plr;
	float hit_x;
	float hit_y;
	float cx;
	float cy;

	plr = all.player;
	t = 0;
	while (t < 10)
	{
		cx = plr.x + t*cos(agile);
		cy = plr.y + t*sin(agile);
		t += 0.01;
		if (all.map[(int)cy][(int)cx] == '1')
		{
			hit_x = cx - floor(cx+.5);
			hit_y = cy - floor(cy+.5);
			if (fabs(hit_x) > fabs(hit_y))
			{
				*textcord = hit_x*all.sprite.width;
				*texture = (agile > M_PI) ? 'N' : 'S';
			}
			else
			{
				*textcord = hit_y*all.sprite.width;
				*texture = (agile > 3 * M_PI/2 || agile < M_PI/2) ? 'W' : 'E';
			}
			if (*textcord < 0)
				*textcord += all.sprite.width;
			return (all.win_w/(t*cos(agile-all.player.dir)));
		}
	}
	return (-1);
}

float	calc_sprite_distance(t_all all, float agile)
{
	float		t;
	float		cx;
	float		cy;
	t_player	plr;

	plr = all.player;
	t = 0;
	while (t < 10)
	{
		cx = plr.x + t*cos(agile);
		cy = plr.y + t*sin(agile);
		t += 0.01;
		if (all.map[(int)cy][(int)cx] == '1')
			break;
		if (all.map[(int)cy][(int)cx] == '2')
			return (all.win_h/(t*cos(agile - plr.dir)));
	}
	return (-1);
}

void draw_f_c(t_all all)
{
	put_rectangle(&all, 0, 0, all.win_w,all.win_h/2, all.color_c);
	put_rectangle(&all, 0,all.win_h/2, all.win_w,all.win_h, all.color_f);
}

void            pixel_put(t_all *data, int x, int y, int color)
{
	char    *dst;

	dst = data->win->addr + (y * data->win->line_length + \
	x * (data->win->bits_per_pixel / 8));
	*(int*)dst = color;
}

void	put_rectangle(t_all *all, int start_x,
				   int start_y, int end_x, int end_y, int color)
{
	int x;
	x = start_x;
	if (start_y<0)
		start_y = 0;
	if (end_y > all->win_h)
		end_y = all->win_h;
	while (start_y < end_y)
	{
		while (start_x < end_x)
			pixel_put(all, start_x++, start_y, color);
		start_x = x;
		start_y += 1;
	}
}