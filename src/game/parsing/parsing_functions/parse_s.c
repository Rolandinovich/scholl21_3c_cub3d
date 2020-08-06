/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:07:52 by charmon           #+#    #+#             */
/*   Updated: 2020/08/06 22:07:52 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void		parsing_s(char *str, t_data *data)
{
	char	**list;
	int		count;

	data->error = 3;
	if (data->s_fill)
		return ;
	list = ft_split(str, ' ');
	count = 0;
	while (list[count])
		count++;
	if (count != 2 || !ft_strnstr(list[0], "S", 2))
	{
		clear_2x_list(list);
		return ;
	}
	data->s = ft_strdup(list[1]);
	clear_2x_list(list);
	if (!data->s)
		return ;
	data->error = 0;
	data->s_fill = 1;
}
