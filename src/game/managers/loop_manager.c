/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:17:58 by charmon           #+#    #+#             */
/*   Updated: 2020/10/10 12:11:28 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int				loop_manager(void *param)
{
	t_all		*all;
	double		x;
	double		y;
	double		dir;

	all = (t_all *)param;
	y = all->player.y;
	x = all->player.x;
	dir = all->player.dir;
	key_manager(all);
	if (all->player.y != y || all->player.x != x || all->player.dir != dir)
		draw_circle(all);
	return (0);
}
