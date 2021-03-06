/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:25 by charmon           #+#    #+#             */
/*   Updated: 2020/10/10 19:17:32 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

int			main(int argc, char **argv)
{
	t_data	data;
	t_all	all;

	data.map = NULL;
	data.data_lines = NULL;
	all.map = NULL;
	all.destroy_win = 0;
	if (!((!check_save(argc, argv, &all)) &&
	!(make_map(argv[1], &data)) &&
	!(check_files(&data)) &&
	!(init_data_1(&data, &all)) &&
	!(init_data_2(&data, &all))))
		event_destroy_window(&all);
	draw_circle(&all);
	if (all.save)
	{
		shot_screen(&all);
		return (0);
	}
	mlx_hook(all.win->win, 2, 1L << 0, event_key_pressed, &all);
	mlx_hook(all.win->win, 3, 1L << 1, event_key_released, &all);
	mlx_hook(all.win->win, 17, 1L << 17, event_destroy_window, &all);
	mlx_loop_hook(all.win->mlx, loop_manager, &all);
	mlx_loop(all.win->mlx);
	return (0);
}
