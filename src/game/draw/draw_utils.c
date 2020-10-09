/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:17:10 by charmon           #+#    #+#             */
/*   Updated: 2020/10/09 22:42:13 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

char		text_distance(t_all *all, float cxy[2],
					float *cord, float agile)
{
	char	texture;

	while (agile > 2 * M_PI)
		agile -= 2 * M_PI;
	while (agile < 0)
		agile += 2 * M_PI;
	cxy[0] = cxy[0] - floor(cxy[0] + .5);
	cxy[1] = cxy[1] - floor(cxy[1] + .5);
	if (fabs(cxy[0]) > fabs(cxy[1]))
	{
		texture = (agile >= M_PI) ? 'N' : 'S';
		*cord = cxy[0] * all->textures[(int)texture].width;
	}
	else
	{
		texture = (agile >= 3 * M_PI / 2 || agile <= M_PI / 2) ? 'E' : 'W';
		*cord = cxy[1] * all->textures[(int)texture].width;
	}
	if (*cord < 0)
		*cord += all->textures[(int)texture].width;
	if (fabs(fabs(cxy[0]) - fabs(cxy[1])) < 0.01 && fabs(cxy[0]) < 0.01)
		texture = all->last_t;
	return (texture);
}

float		calc_text_distance(t_all all,
			char *texture, float *cord, float *dist)
{
	float	t;
	float	cxy[2];

	t = 0;
	while (t < 200)
	{
		cxy[0] = all.player.x + t * cos(all.current_agile);
		cxy[1] = all.player.y + t * sin(all.current_agile);
		t += 0.01;
		if (all.map[(int)cxy[1]][(int)cxy[0]] == '1')
		{
			*dist = t;
			*texture = text_distance(&all, cxy, cord, all.current_agile);
			return (all.win_w / (t * cos(all.current_agile - all.player.dir)));
		}
	}
	return (-1);
}

void		pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	if (x > data->win_w || x < 0 || y > data->win_h || y < 0)
		return ;
	dst = data->win->addr + (y * data->win->line_length + \
	x * (data->win->bits_per_pixel / 8));
	*(int*)dst = color;
}

void		draw_f_c(t_all all, int column_height, size_t win_x)
{
	int		y;
	int		min;
	int		max;

	min = all.win_h / 2 - column_height / 2;
	max = all.win_h / 2 + column_height / 2;
	y = all.win_h;
	while (y >= 0)
		if (y > max || y < min)
		{
			if (y < all.win_h / 2)
				pixel_put(&all, win_x, y--, all.color_c);
			else
				pixel_put(&all, win_x, y--, all.color_f);
		}
		else
			y--;
}
