/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:39:54 by charmon           #+#    #+#             */
/*   Updated: 2020/05/01 16:48:16 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_bzero(void *s, size_t n)
{
	unsigned char	*position;
	size_t			idx;

	position = (unsigned char*)s;
	idx = -1;
	while (++idx < n)
	{
		*position = '\0';
		position++;
	}
	return (s);
}
