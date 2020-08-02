/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:49:58 by charmon           #+#    #+#             */
/*   Updated: 2020/05/01 18:28:39 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_pointer;
	unsigned char	*src_pointer;
	size_t			idx;

	if ((dest == src) || !n)
		return (dest);
	dest_pointer = (unsigned char *)dest;
	src_pointer = (unsigned char *)src;
	idx = -1;
	while (++idx < n)
	{
		*dest_pointer = *src_pointer;
		dest_pointer++;
		src_pointer++;
	}
	return (dest);
}
