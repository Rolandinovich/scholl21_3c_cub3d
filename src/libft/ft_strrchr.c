/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:14:36 by charmon           #+#    #+#             */
/*   Updated: 2020/05/01 18:35:07 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	char	*link;

	idx = 0;
	link = NULL;
	while (s[idx] != '\0')
	{
		if (s[idx] == c)
			link = (char *)(&s[idx]);
		idx++;
	}
	if (s[idx] == '\0' && c == '\0')
		return ((char *)(&s[idx]));
	return (link);
}
