/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:19:58 by charmon           #+#    #+#             */
/*   Updated: 2020/05/05 14:50:19 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			miss_simbols(const char *nptr)
{
	int				idx;

	idx = 0;
	while ((nptr[idx] == '\n' || nptr[idx] == '\t' || nptr[idx] == '\v'
		|| nptr[idx] == '\f'
		|| nptr[idx] == '\r' || nptr[idx] == ' ') && nptr[idx] != '\0')
		idx++;
	return (idx);
}

int					ft_atoi(const char *nptr)
{
	int				idx;
	int				sign;
	unsigned long	long_res;

	idx = miss_simbols(nptr);
	long_res = 0;
	sign = 1;
	if (nptr[idx] == '-')
	{
		sign = -1;
		idx++;
	}
	else if (nptr[idx] == '+')
		idx++;
	while (ft_isdigit(nptr[idx++]))
	{
		long_res = long_res * 10 + nptr[idx - 1] - '0';
		if (long_res > 9223372036854775807 && sign == -1)
			return (0);
		if (long_res > 9223372036854775807 && sign == 1)
			return (-1);
	}
	return ((int)long_res * sign);
}
