/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:36:29 by charmon           #+#    #+#             */
/*   Updated: 2020/05/10 12:46:40 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_count;
	size_t	free_buf_count;

	dst_count = ft_strlen(dst);
	if (dst_count >= size)
		return (size + ft_strlen(src));
	free_buf_count = size - dst_count - 1;
	while (*src != '\0' && free_buf_count--)
		dst[dst_count++] = *src++;
	dst[dst_count] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
