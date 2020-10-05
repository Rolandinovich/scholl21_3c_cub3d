/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:17:28 by charmon           #+#    #+#             */
/*   Updated: 2020/10/05 21:35:46 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		texture_column(t_all all, t_img img,
				const size_t texcoord, size_t win_x)
{
	int		y;
	size_t	pix_x;
	size_t	pix_y;
	size_t	win_y;

	y = 0;
	draw_f_c(all, all.col_h[win_x], win_x);
	while (y < all.col_h[win_x])
	{
		pix_x = texcoord;
		pix_y = (y * img.height) / all.col_h[win_x];
		win_y = y + all.win_h / 2 - all.col_h[win_x] / 2;
		if ((win_y < 0 || win_y >= all.win_h) && (y += 1))
			continue;
		pixel_put(&all, win_x, win_y, img.data[(int)((int)pix_x + (int)pix_y *
			(img.width))]);
		y++;
	}
}

void		sprite_column(t_all all, int column_height,
					const size_t texcoord, size_t win_x)
{
	size_t	y;
	size_t	pix_x;
	size_t	pix_y;
	size_t	win_y;
	int		color;

	y = 0;
	while (y < column_height && column_height > 0)
	{
		pix_x = texcoord;
		pix_y = (y * all.sprite.height) / column_height;
		win_y = y + all.win_h / 2 - column_height / 2;
		if ((win_y < 0 || win_y >= all.win_h) && (y += 1))
			continue;
		color = all.sprite.data[(int)((int)pix_x +
					(int)pix_y * (all.sprite.width))];
		if (color != 9961608)
			pixel_put(&all, win_x, win_y + 0.2 * column_height, color);
		y++;
	}
}

void		draw_textures(t_all *all)
{
	float		agile;
	size_t		i;
	char		texture;
	float		textcord;
	float		dist;

	i = 0;
	all->last_t = 'W';
	while (i < all->win_w)
	{
		agile = all->player.dir - all->player.fov / 2 +
			all->player.fov * i / (float)all->win_w;
		all->col_h[i] = calc_text_distance(*all, agile,
						&texture, &textcord, &dist);
		all->last_t = texture;
		texture_column(*all, all->textures[texture],
						textcord, i);
		all->col_h[i] = dist;
		i++;
	}
}

void		draw_circle(t_all all)
{
	draw_textures(&all);
	update_sprite_distance(all);
	if (!all.save)
		mlx_put_image_to_window(all.win->mlx, all.win->win, all.win->img, 0, 0);
}
