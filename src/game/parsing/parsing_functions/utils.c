/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:42 by charmon           #+#    #+#             */
/*   Updated: 2020/10/10 19:13:16 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void	clear_2x_list(char **list)
{
	int	idx;

	if (!list)
		return ;
	idx = -1;
	while (list[++idx])
		free(list[idx]);
	free(list);
	list = NULL;
}

void	space2comma(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			*str = ',';
		str++;
	}
}

void	data_init(t_data *data)
{
	data->no_fill = 0;
	data->so_fill = 0;
	data->we_fill = 0;
	data->ea_fill = 0;
	data->s_fill = 0;
	data->f_fill = 0;
	data->c_fill = 0;
	data->r_fill = 0;
	data->map_start = 0;
	data->map_finish = 0;
	data->error = 0;
	data->first_part_fill = 0;
	data->orientation = '\0';
}

void	check_first_part_fill(t_data *data)
{
	if (data->r_fill && data->c_fill && data->ea_fill && data->f_fill
		&& data->no_fill && data->s_fill && data->so_fill
		&& data->c_fill && data->we_fill)
		data->first_part_fill = 1;
}
