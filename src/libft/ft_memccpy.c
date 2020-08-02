/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:11:00 by charmon           #+#    #+#             */
/*   Updated: 2020/05/08 07:19:12 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_pointer;
	unsigned char	*src_pointer;
	size_t			idx;

	dest_pointer = (unsigned char *)dest;
	src_pointer = (unsigned char *)src;
	idx = 0;
	if (n == 0)
		return (NULL);
	while (idx++ < n)
	{
		if (*src_pointer == (unsigned char)c)
		{
			*dest_pointer = *src_pointer;
			return (++dest_pointer);
		}
		*dest_pointer = *src_pointer;
		dest_pointer++;
		src_pointer++;
	}
	return (NULL);
}
