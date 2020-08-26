/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:25 by charmon           #+#    #+#             */
/*   Updated: 2020/08/26 21:35:02 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

int			main(int argc, char **argv)
{
	t_data	data;
	t_all	all;

	if (!((argc > 1) &&
	!(make_map(argv[1], &data)) &&
	!(init_data_1(&data, &all))))
		return (0);
	start_game(&data);
	return (0);
}
