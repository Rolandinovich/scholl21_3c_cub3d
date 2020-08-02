/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:16:08 by charmon           #+#    #+#             */
/*   Updated: 2020/05/02 13:55:34 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_pointer;
	unsigned char	*dest_pointer;
	size_t			idx;

	src_pointer = (unsigned char *)src;
	dest_pointer = (unsigned char *)dest;
	if (dest == src || n == 0)
		return (dest);
	idx = (dest < src) ? 0 : n;
	if (dest < src)
		while (idx < n)
		{
			dest_pointer[idx] = src_pointer[idx];
			idx++;
		}
	else
	{
		while (--idx != 0)
			dest_pointer[idx] = src_pointer[idx];
		dest_pointer[idx] = src_pointer[idx];
	}
	return (dest);
}
