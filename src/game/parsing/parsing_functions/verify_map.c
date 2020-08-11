/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 20:04:04 by charmon           #+#    #+#             */
/*   Updated: 2020/08/11 20:19:28 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

static void	checking_border_x(t_data *data, int x, int y)
{
	int		idx;
	int		border_count;

	border_count = 0;
	idx = x;
	while (++idx < data->map_rows_count && data->map[y][idx] != ' ')
		if (data->map[y][idx] == '1')
		{
			border_count++;
			break ;
		}
	idx = x;
	while (--idx >= 0 && data->map[y][idx] != ' ')
		if (data->map[y][idx] == '1')
		{
			border_count++;
			break ;
		}
	if (border_count != 2)
		data->error = 3;
}

static void	checking_border_y(t_data *data, int x, int y)
{
	int		idx;
	int		border_count;

	border_count = 0;
	idx = y;
	while (++idx < data->map_line_count && data->map[idx][x] != ' ')
		if (data->map[idx][x] == '1')
		{
			border_count++;
			break ;
		}
	idx = y;
	while (--idx >= 0 && data->map[idx][x] != ' ')
		if (data->map[idx][x] == '1')
		{
			border_count++;
			break ;
		}
	if (border_count != 2)
		data->error = 3;
}

void		verify_map(t_data *data)
{
	int		idx_x;
	int		idx_y;

	idx_x = -1;
	while (++idx_x < data->map_rows_count && !data->error)
	{
		idx_y = -1;
		while (++idx_y < data->map_line_count && !data->error)
		{
			if (ft_strchr("NSEW", data->map[idx_y][idx_x]))
			{
				if (data->orientation)
					data->error = 3;
				data->orientation = data->map[idx_y][idx_x];
				data->position[0] = idx_x;
				data->position[1] = idx_y;
			}
			if (data->map[idx_y][idx_x] == '0')
			{
				checking_border_x(data, idx_x, idx_y);
				checking_border_y(data, idx_x, idx_y);
			}
		}
	}
}
