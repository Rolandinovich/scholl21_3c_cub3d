/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:00:05 by charmon           #+#    #+#             */
/*   Updated: 2020/05/05 15:19:21 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	if (!dst && !src)
		return (0);
	if (!dst && src)
		return (ft_strlen(src));
	count = 0;
	while (src[count] != '\0' && count < size - 1 && size != 0)
	{
		dst[count] = src[count];
		count++;
	}
	if (size != 0)
		dst[count] = '\0';
	while (src[count] != '\0')
		count++;
	return (count);
}
