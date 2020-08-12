/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:46:16 by charmon           #+#    #+#             */
/*   Updated: 2020/08/12 21:36:43 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void		parsing_c(char *str, t_data *data)
{
	char	**list;
	int		count;

	data->error = 3;
	space2comma(str);
	if (data->c_fill)
		return ;
	if (symbols_in_str(str, LIGAL_C_SIMBOLS))
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
	data->c[0] = ft_atoi(list[1]);
	data->c[1] = ft_atoi(list[2]);
	data->c[2] = ft_atoi(list[3]);
	data->error = 0;
	clear_2x_list(list);
	data->c_fill = 1;
}
