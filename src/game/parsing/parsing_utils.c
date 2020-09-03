/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:37 by charmon           #+#    #+#             */
/*   Updated: 2020/09/03 09:31:39 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int			symbols_in_str(char *str, char *symbols)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != '\0' && (ft_strchr(symbols, str[idx])))
		idx++;
	if (str[idx] == '\0')
		return (0);
	return (3);
}
