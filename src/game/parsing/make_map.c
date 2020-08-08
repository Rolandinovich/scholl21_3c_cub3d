/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:28 by charmon           #+#    #+#             */
/*   Updated: 2020/08/07 21:49:11 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		make_map(char *file, t_data *data)
{
	int 	idx;

	data_init(data);
	load_data(file, data);
	parsing(data);
	idx = -1;
	while (data->map[++idx] != NULL)
	{
		ft_putstr_fd(data->map[idx], 1);
		ft_putstr_fd("\n", 1);
		printf("%p\n", data->map[idx]);
	}
}
