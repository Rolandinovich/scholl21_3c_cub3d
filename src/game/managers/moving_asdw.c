/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_asdw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:18:12 by charmon           #+#    #+#             */
/*   Updated: 2020/10/06 20:34:06 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		move_forward(t_all *all)
{
	float	new_x;
	float	new_y;

	new_x = all->player.x + all->player.speed * cos(all->player.dir);
	new_y = all->player.y + all->player.speed * sin(all->player.dir);
	if (all->map[(int)new_y][(int)new_x] == '0')
	{
		all->player.x = new_x;
		all->player.y = new_y;
	}
}

void		move_backward(t_all *all)
{
	float	new_x;
	float	new_y;

	new_x = all->player.x + all->player.speed * cos(all->player.dir - M_PI);
	new_y = all->player.y + all->player.speed * sin(all->player.dir - M_PI);
	if (all->map[(int)new_y][(int)new_x] == '0')
	{
		all->player.x = new_x;
		all->player.y = new_y;
	}
}

void		move_left(t_all *all)
{
	float	new_x;
	float	new_y;

	new_x = all->player.x + all->player.speed *
		cos(all->player.dir + 3 * M_PI / 2);
	new_y = all->player.y + all->player.speed *
		sin(all->player.dir + 3 * M_PI / 2);
	if (all->map[(int)new_y][(int)new_x] == '0')
	{
		all->player.x = new_x;
		all->player.y = new_y;
	}
}

void		move_right(t_all *all)
{
	float new_x;
	float new_y;

	new_x = all->player.x + all->player.speed *
		cos(all->player.dir - 3 * M_PI / 2);
	new_y = all->player.y + all->player.speed *
		sin(all->player.dir - 3 * M_PI / 2);
	if (all->map[(int)new_y][(int)new_x] == '0')
	{
		all->player.x = new_x;
		all->player.y = new_y;
	}
}
