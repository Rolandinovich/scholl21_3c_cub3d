/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_so.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:47:40 by charmon           #+#    #+#             */
/*   Updated: 2020/08/12 21:36:43 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void		parsing_so(char *str, t_data *data)
{
	char	**list;
	int		count;

	data->error = 3;
	if (data->so_fill)
		return ;
	list = ft_split(str, ' ');
	count = 0;
	while (list[count])
		count++;
	if (count != 2 || !ft_strnstr(list[0], "SO", 2))
	{
		clear_2x_list(list);
		return ;
	}
	data->so = ft_strdup(list[1]);
	clear_2x_list(list);
	if (!data->so)
		return ;
	data->error = 0;
	data->so_fill = 1;
}
