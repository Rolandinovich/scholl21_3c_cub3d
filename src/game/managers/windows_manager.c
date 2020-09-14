/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:18:30 by charmon           #+#    #+#             */
/*   Updated: 2020/09/14 22:18:30 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void			close_win(		int mod,		t_all	*all,		char *msg)
{
	if (mod == 0)
		mlx_destroy_window(all->win->mlx, all->win->win);
	ft_putstr_fd(msg, 1);
	if (msg[0])
		write(1, "\n", 1);
	exit(0);
}

int		event_destroy_window(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	close_win(0, all, "");
	return (0);
}