/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:17:10 by charmon           #+#    #+#             */
/*   Updated: 2020/09/14 22:17:10 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

char 	text_distance(t_all all, float cx, float cy,  float *cord, float agile)
{
	char texture;

	cx = cx - floor(cx+.5);
	cy = cy - floor(cy+.5);
	if (fabs(cx) > fabs(cy))
	{
		texture = (agile > M_PI) ? 'N' : 'S';
		*cord = cx*all.textures[texture].width;
	}
	else
	{
		texture = (agile > 3 * M_PI/2 || agile < M_PI/2) ? 'W' : 'E';
		*cord = cy*all.textures[texture].width;
	}
	if (*cord < 0)
		*cord += all.textures[texture].width;
	return (texture);
}

float	calc_text_distance(t_all all, float agile, char *texture, float *cord, float *dist)
{
	float		t;
	float cx;
	float cy;

	t = 0;
	while (t < 20)
	{
		cx = all.player.x + t*cos(agile);
		cy = all.player.y + t*sin(agile);
		t += 0.01;
		if (all.map[(int)cy][(int)cx] == '1')
		{
			while (all.map[(int)cy][(int)cx] == '1')
			{
				t -= 0.001;
				cx = all.player.x + t*cos(agile);
				cy = all.player.y + t*sin(agile);
			}
			*dist = t;
			*texture = text_distance(all, cx, cy, cord, agile);
			return (all.win_w/(t*cos(agile-all.player.dir)));
		}
	}
	return (-1);
}

float	calc_sprite_distance(t_all all, float agile, float *cord)
{
	float		t;
	float		cx;
	float		cy;

	t = 0;
	while (t < 20)
	{
		cx = all.player.x + t*cos(agile);
		cy = all.player.y + t*sin(agile);
		t += 0.01;
		if (all.map[(int)cy][(int)cx] == '1')
			break;
		if (all.map[(int)cy][(int)cx] == '2')
		{
			cx = cx - floor(cx+.5);
			cy = cy - floor(cy+.5);
			if (fabs(cx) > fabs(cy))
				*cord = cx*all.sprite.width;
			else
				*cord = cy*all.sprite.width;
			*cord = (*cord < 0) ? *cord + all.sprite.width : *cord;
			return (all.win_h/(t*cos(agile - all.player.dir)));
		}
	}
	return (-1);
}

void            pixel_put(t_all *data, int x, int y, int color)
{
	char    *dst;

	if (x > data->win_w || x < 0 || y > data->win_h || y < 0)
		return;
	dst = data->win->addr + (y * data->win->line_length + \
	x * (data->win->bits_per_pixel / 8));
	*(int*)dst = color;
}

void draw_f_c(t_all all, int column_height, size_t win_x)
{
	int x;
	int y;
	int min;
	int max;

	min = all.win_h/2 - column_height/2;
	max = all.win_h/2 + column_height/2;
	y = all.win_h;
	while (y >= 0)
		if (y > max || y < min)
		{
			if (y < all.win_h/2)
				pixel_put(&all, win_x, y--, all.color_c);
			else
				pixel_put(&all, win_x, y--, all.color_f);
		}
		else
			y--;
}
