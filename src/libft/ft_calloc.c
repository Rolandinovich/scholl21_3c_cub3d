/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:34:45 by charmon           #+#    #+#             */
/*   Updated: 2020/05/11 04:43:22 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;
	size_t			idx;
	size_t			size_t_max;

	size_t_max = (size_t)~0;
	if ((nmemb && size_t_max / nmemb < size) ||
		(size && size_t_max / size < nmemb))
		return (NULL);
	result = (unsigned char *)malloc(nmemb * size);
	if (!result)
		return (NULL);
	idx = 0;
	while (idx < (nmemb * size))
		result[idx++] = '\0';
	return ((void *)result);
}
