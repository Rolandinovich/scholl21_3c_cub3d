/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:33 by charmon           #+#    #+#             */
/*   Updated: 2020/10/10 00:22:43 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static int	parsing_first_part(t_data *data, int idx)
{
	while ((*data).data_lines[++idx] && data->error == 0
	&& (data->first_part_fill + data->map_start != 2))
	{
		if (ft_strnstr((*data).data_lines[idx], "R", (size_t)~0))
			parsing_r((*data).data_lines[idx], data);
		else if (ft_strnstr((*data).data_lines[idx], "F", (size_t)~0))
			parsing_f((*data).data_lines[idx], data);
		else if (ft_strnstr((*data).data_lines[idx], "C", (size_t)~0))
			parsing_c((*data).data_lines[idx], data);
		else if (ft_strnstr((*data).data_lines[idx], "NO", (size_t)~0))
			parsing_no((*data).data_lines[idx], data);
		else if (ft_strnstr((*data).data_lines[idx], "SO", (size_t)~0))
			parsing_so((*data).data_lines[idx], data);
		else if (ft_strnstr((*data).data_lines[idx], "WE", (size_t)~0))
			parsing_we((*data).data_lines[idx], data);
		else if (ft_strnstr((*data).data_lines[idx], "EA", (size_t)~0))
			parsing_ea((*data).data_lines[idx], data);
		else if (ft_strnstr((*data).data_lines[idx], "S", (size_t)~0))
			parsing_s((*data).data_lines[idx], data);
		else
			parse_undefined_line((*data).data_lines[idx], data);
		check_first_part_fill(data);
	}
	return (--idx);
}

int			parsing(t_data *data)
{
	int		idx;

	idx = parsing_first_part(data, -1);
	if (data->error > 0)
	{
		ft_putstr_fd("Error parsing or verify params\n", 1);
		return (data->error);
	}
	parse_map(idx, data);
	if (data->error > 0)
	{
		ft_putstr_fd("Error parsing or verify map\n", 1);
		return (data->error);
	}
	verify_map(data);
	data->error = (data->orientation == '\0' || data->error == 3) ? 3 : 0;
	if (data->error > 0)
	{
		ft_putstr_fd("Error verify map\n", 1);
		return (data->error);
	}
	return (data->error);
}
