/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_no.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:47:10 by charmon           #+#    #+#             */
/*   Updated: 2020/08/06 21:25:19 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void		parsing_no(char *str, t_data *data)
{
	char	**list;
	int		count;

	data->error = 3;
	if (data->no_fill)
		return ;
	list = ft_split(str, ' ');
	count = 0;
	while (list[count])
		count++;
	if (count != 2 || !ft_strnstr(list[0], "NO", 2))
	{
		clear_2x_list(list);
		return ;
	}
	data->no = ft_strdup(list[1]);
	clear_2x_list(list);
	if (!data->no)
		return ;
	data->error = 0;
	data->no_fill = 1;
}
