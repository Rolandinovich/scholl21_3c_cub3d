/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:11:41 by charmon           #+#    #+#             */
/*   Updated: 2020/05/02 21:14:39 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*position;
	size_t			idx;

	position = (unsigned char*)s;
	idx = -1;
	while (++idx < n)
	{
		*position = c;
		position++;
	}
	return (s);
}
