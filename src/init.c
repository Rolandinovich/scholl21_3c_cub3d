/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 21:40:59 by charmon           #+#    #+#             */
/*   Updated: 2020/08/27 21:13:42 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

int	init_mlx(t_data *data, t_all *all)
{
	t_win *win;

	if (!(win = (t_win*)malloc(sizeof(t_win))))
	{
		data->error = 2;
		return (2);
	}
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, data->r[0], data->r[1], "CUB-IK");
	win->img = mlx_new_image(win->mlx, data->r[0], data->r[1]);
	win->addr = mlx_get_data_addr(win->img,
	&(win->bits_per_pixel),
	&(win->line_length), &(win->endian));
	all->win = win;
}

int	init_texture_1(t_data *data, t_all *all)
{
	all->textures['N'].ptr = mlx_xpm_file_to_image(all->win->mlx, data->no,
	&(all->textures['N'].width), &(all->textures['N'].height));
	if (all->textures['N'].ptr)
		all->textures['N'].data = (int *)mlx_get_data_addr(
			all->textures['N'].ptr, &(all->textures['N'].bpp),
			&(all->textures['N'].size_l), &(all->textures['N'].endian));
	else
		return ((all->error = 1));
	all->textures['S'].ptr = mlx_xpm_file_to_image(all->win->mlx, data->so,
	&(all->textures['S'].width), &(all->textures['S'].height));
	if (all->textures['S'].ptr)
		all->textures['S'].data = (int *)mlx_get_data_addr(
			all->textures['S'].ptr, &(all->textures['S'].bpp),
			&(all->textures['S'].size_l), &(all->textures['S'].endian));
	else
	{
		free(all->textures['N'].ptr);
		return ((all->error = 1));
	}
}

int	init_texture_2(t_data *data, t_all *all)
{
	all->textures['W'].ptr = mlx_xpm_file_to_image(all->win->mlx, data->we,
		&(all->textures['W'].width), &(all->textures['W'].height));
	if (all->textures['W'].ptr)
		all->textures['W'].data = (int*)mlx_get_data_addr(
			all->textures['W'].ptr, &(all->textures['W'].bpp),
		&(all->textures['W'].size_l), &(all->textures['W'].endian));
	else
		return ((all->error = 1));
	all->textures['E'].ptr = mlx_xpm_file_to_image(all->win->mlx, data->ea,
		&(all->textures['E'].width), &(all->textures['E'].height));
	if (all->textures['E'].ptr)
		all->textures['E'].data = (int*)mlx_get_data_addr(
			all->textures['E'].ptr, &(all->textures['E'].bpp),
		&(all->textures['E'].size_l), &(all->textures['E'].endian));
	else
	{
		free(all->textures['W'].ptr);
		return ((all->error = 1));
	}
}

int	init_sprite(t_data *data, t_all *all)
{
	all->sprite.ptr = mlx_xpm_file_to_image(all->win->mlx, data->no,
	&(all->sprite.width), &(all->sprite.height));
	if (all->sprite.ptr)
		all->sprite.data = (int*)mlx_get_data_addr(
			all->sprite.ptr, &(all->sprite.bpp),
			&(all->sprite.size_l), &(all->sprite.endian));
	else
		return ((all->error = 1));
	return (0);
}

int	init_data_1(t_data *data, t_all *all)
{
	all->error = 0;
	all->map = data->map;
	all->player.x = data->position[0] + .5;
	all->player.y = data->position[1] + .5;
	all->player.fov = M_PI / 3.;
	all->player.speed = 0.1;
	all->player.step = 0.1;
	if (data->orientation == 'N')
		all->player.direction = 3. * M_PI / 2.;
	else if (data->orientation == 'E')
		all->player.direction = 0;
	else if (data->orientation == 'S')
		all->player.direction = M_PI / 2;
	else if (data->orientation == 'W')
		all->player.direction = M_PI;
	all->color_f = (data->f[0] << 16) + (data->f[1] << 8) + (data->f[2]);
	all->color_c = (data->c[0] << 16) + (data->c[1] << 8) + (data->c[2]);
	init_mlx(data, all);
	init_texture_1(data, all);
	init_texture_2(data, all);
	init_sprite(data, all);
	return (all->error);
}
