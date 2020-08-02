/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:34:54 by charmon           #+#    #+#             */
/*   Updated: 2020/05/02 14:18:57 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_pointer;
	size_t			idx;

	s_pointer = (unsigned char *)s;
	idx = -1;
	while (++idx < n)
	{
		if (*s_pointer == (unsigned char)c)
			return (s_pointer);
		s_pointer++;
	}
	return (NULL);
}
