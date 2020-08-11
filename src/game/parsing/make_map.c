/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:28 by charmon           #+#    #+#             */
/*   Updated: 2020/08/11 20:26:56 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int		make_map(char *file, t_data *data)
{
	data_init(data);
	load_data(file, data);
	if (data->error)
		ft_putstr_fd("Error read file\n", 1);
	else
		ft_putstr_fd("Read file completed\n", 1);
	parsing(data);
	if (!data->error)
		ft_putstr_fd("Settings successful loaded\n", 1);
	return (data->error);
}
