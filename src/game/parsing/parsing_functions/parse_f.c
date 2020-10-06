/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:45:38 by charmon           #+#    #+#             */
/*   Updated: 2020/10/06 20:34:06 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void		check_f(t_data *data)
{
	if (data->f[0] >= 0 && data->f[1] >= 0 && data->f[2] >= 0 &&
		data->f[0] <= 255 && data->f[1] <= 255 && data->f[2] <= 255)
		data->error = 0;
	else
		data->error = 3;
}

void		parsing_f(char *str, t_data *data)
{
	char	**list;
	int		count;

	data->error = 3;
	space2comma(str);
	if (data->f_fill)
		return ;
	if (symbols_in_str(str, LIGAL_F_SIMBOLS))
		return ;
	list = ft_split(str, ',');
	count = 0;
	while (list[count])
		count++;
	if (count != 4)
	{
		clear_2x_list(list);
		return ;
	}
	data->f[0] = ft_atoi(list[1]);
	data->f[1] = ft_atoi(list[2]);
	data->f[2] = ft_atoi(list[3]);
	check_f(data);
	clear_2x_list(list);
	data->f_fill = 1;
}
