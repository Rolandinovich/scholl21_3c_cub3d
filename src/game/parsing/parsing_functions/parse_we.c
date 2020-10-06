/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_we.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:48:16 by charmon           #+#    #+#             */
/*   Updated: 2020/10/06 20:34:06 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void		parsing_we(char *str, t_data *data)
{
	char	**list;
	int		count;

	data->error = 3;
	if (data->we_fill || str[ft_strlen(str) - 1] == ' ')
		return ;
	list = ft_split(str, ' ');
	count = 0;
	while (list[count])
		count++;
	if (count != 2 || !ft_strnstr(list[0], "WE", 2))
	{
		clear_2x_list(list);
		return ;
	}
	data->we = ft_strdup(list[1]);
	clear_2x_list(list);
	if (!data->we)
		return ;
	data->error = 0;
	data->we_fill = 1;
}
