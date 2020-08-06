/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_undefine_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:08:05 by charmon           #+#    #+#             */
/*   Updated: 2020/08/06 23:44:23 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void	parse_undefined_line(char *str, t_data *data)
{
	if (!symbols_in_str(str, " ") || *str == '\0')
		return ;
	if (symbols_in_str(str, LIGAL_MAP_SIMBOLS))
	{
		data->error = 3;
		return ;
	}
	else
		data->map_start = 1;
}
