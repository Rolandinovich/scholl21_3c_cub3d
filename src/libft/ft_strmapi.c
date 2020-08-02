/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:35:25 by charmon           #+#    #+#             */
/*   Updated: 2020/05/04 11:48:39 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rst;
	char			*start;
	unsigned int	idx;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	rst = (char *)malloc((len + 1) * sizeof(char));
	if (!rst)
		return (NULL);
	rst[len] = '\0';
	start = rst;
	idx = 0;
	while (*s != '\0')
	{
		*start = f(idx++, *s);
		start++;
		s++;
	}
	return (rst);
}
