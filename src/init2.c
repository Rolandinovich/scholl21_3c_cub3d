/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:19:36 by charmon           #+#    #+#             *//*   Updated: 2020/10/05 20:55:31 by charmon          ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */
#include "game/game.h"

int	init_data_2(t_data *data, t_all *all)
{
	int		idx_x;
	int		idx_y;

	idx_x = -1;
	all->sprite_c = 0;
	while (++idx_x < data->map_rows_count && !data->error)
	{
		idx_y = -1;
		while (++idx_y < data->map_line_count && !data->error)
		{
			if (data->map[idx_y][idx_x] == '2')
			{
				all->sprites[all->sprite_c].x = idx_x + 0.5;
				all->sprites[all->sprite_c].y = idx_y + 0.5;
				all->sprites[all->sprite_c++].dist = -1;
			}
			if (data->map[idx_y][idx_x] == ' ')
				data->map[idx_y][idx_x] = '1';
		}
	}
	return (0);
}

int		check_save(int argc, char **argv, t_all *all)
{
	all->save = 0;
	if (argc == 3 && !(ft_strncmp(argv[2], "--save", 8)))
		all->save = 1;
	return (all->save);
}