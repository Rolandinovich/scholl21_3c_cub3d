/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:17:58 by charmon           #+#    #+#             */
/*   Updated: 2020/09/14 22:17:58 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int				loop_manager(void *param)
{
	t_all		*all;

	all = (t_all *)param;
	draw_circle(*all);
	key_manager(all);
	return (0);
}
