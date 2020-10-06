/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:49:13 by charmon           #+#    #+#             */
/*   Updated: 2020/10/06 20:34:06 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void		parsing_ea(char *str, t_data *data)
{
	char	**list;
	int		count;

	data->error = 3;
	if (data->ea_fill || str[ft_strlen(str) - 1] == ' ')
		return ;
	list = ft_split(str, ' ');
	count = 0;
	while (list[count])
		count++;
	if (count != 2 || !ft_strnstr(list[0], "EA", 2))
	{
		clear_2x_list(list);
		return ;
	}
	data->ea = ft_strdup(list[1]);
	clear_2x_list(list);
	if (!data->ea)
		return ;
	data->error = 0;
	data->ea_fill = 1;
}
