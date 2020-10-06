/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 23:10:16 by charmon           #+#    #+#             */
/*   Updated: 2020/10/05 23:10:18 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

int			init_data_2(t_data *data, t_all *all)
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

int			check_save(int argc, char **argv, t_all *all)
{
	int		l;

	all->save = 0;
	all->error = 0;
	if (argc == 3 && !(ft_strncmp(argv[2], "--save", 8)))
		all->save = 1;
	if (argc > 3 || argc == 1 ||
		(argc == 3 && ft_strncmp(argv[2], "--save", 8)))
	{
		ft_putstr_fd("Error\nWrongArguments", 1);
		return ((all->error = 1));
	}
	l = ft_strlen(argv[1]);
	if (l < 4 || argv[1][l - 1] != 'b' || argv[1][l - 2] != 'u'
		|| argv[1][l - 3] != 'c' || argv[1][l - 4] != '.')
	{
		ft_putstr_fd("Error\nWrongArguments", 1);
		return ((all->error = 1));
	}
	return (all->error);
}
