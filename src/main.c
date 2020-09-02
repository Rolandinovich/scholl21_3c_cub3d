/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:25 by charmon           #+#    #+#             */
/*   Updated: 2020/08/26 21:35:02 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

int			main(int argc, char **argv)
{
	t_data	data;
	t_all	all;

	if (!((argc > 1) &&
	!(make_map(argv[1], &data)) &&
	!(init_data_1(&data, &all))))
		return (0);
	mlx_hook(all.win, 2, 1L << 0, event_key_pressed, &all);
	mlx_hook(all.win, 3, 1L << 1, event_key_released, &all);
	mlx_hook(all.win, 17, 1L << 17, event_destroy_window, &all);
	mlx_loop_hook(all.win, loop_manager, &all);
	mlx_loop(all.win->mlx);
	return (0);
}
