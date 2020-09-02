/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:28 by charmon           #+#    #+#             */
/*   Updated: 2020/09/02 20:37:15 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int		make_map(char *file, t_data *data)
{
	data_init(data);
	load_data(file, data);
	if (data->error)
		ft_putstr_fd("Error\n read file\n", 1);
	else
	{
		ft_putstr_fd("Read file completed\n", 1);
		parsing(data);
	}
	if (!data->error)
		ft_putstr_fd("Settings successful loaded\n", 1);
	else
	{
		ft_putstr_fd("Error\nParsing fail. Map incorrect\n", 1);
		clear_2x_list(data->map);
	}
	clear_2x_list(data->data_lines);
	return (data->error);
}
