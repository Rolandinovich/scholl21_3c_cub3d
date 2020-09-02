/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:14 by charmon           #+#    #+#             */
/*   Updated: 2020/09/02 20:37:14 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void		parsing_r(char *str, t_data *data)
{
	char	**list;
	int		count;

	(*data).error = 3;
	if ((*data).r_fill)
		return ;
	if (symbols_in_str(str, LIGAL_R_SIMBOLS))
		return ;
	list = ft_split(str, ' ');
	count = 0;
	while (list[count])
		count++;
	if (count != 3)
	{
		clear_2x_list(list);
		return ;
	}
	(*data).r[0] = ft_atoi(list[1]);
	(*data).r[1] = ft_atoi(list[2]);
	if ((*data).r[0] < 0 || (*data).r[1] < 0)
		(*data).error = 3;
	else
		(*data).error = 0;
	clear_2x_list(list);
	(*data).r_fill = 1;
}
