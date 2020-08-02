/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:24:53 by charmon           #+#    #+#             */
/*   Updated: 2020/05/07 20:57:28 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	c_count;
	unsigned int	idx;
	char			*result;

	if (!s)
		return (NULL);
	idx = -1;
	c_count = 0;
	while (s[++idx] != '\0' && idx < start + len)
		c_count += (idx >= start) ? 1 : 0;
	if (!c_count)
		return (ft_strdup(""));
	result = (char *)malloc((c_count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	idx = start - 1;
	while (s[++idx] != '\0' && idx < len + start)
		result[idx - start] = s[idx];
	result[idx - start] = '\0';
	return (result);
}
