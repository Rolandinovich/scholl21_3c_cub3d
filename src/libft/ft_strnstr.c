/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:10:38 by charmon           #+#    #+#             */
/*   Updated: 2020/05/01 19:34:51 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	if (*little == '\0')
		return ((char *)(big));
	while (big[idx1] != '\0' && idx1 < len)
	{
		idx2 = 0;
		while (big[idx1] == little[idx2] &&
				big[idx1] != '\0' && little[idx2] != '\0' && idx1 < len)
		{
			idx1++;
			idx2++;
		}
		if (little[idx2] == '\0')
			return ((char *)(&big[idx1 - idx2]));
		idx1 = idx1 - idx2 + 1;
	}
	return (NULL);
}
