/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:33 by charmon           #+#    #+#             */
/*   Updated: 2020/08/05 23:09:44 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int		parsing(t_data *data)
{
	int idx;

	idx = -1;
	while ((*data).data_lines[++idx])
	{
		if (ft_strnstr((*data).data_lines[idx], "R", (size_t)~0))
			parsing_r((*data).data_lines[idx], data);
	}
	return (0);
}
