/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:29:31 by charmon           #+#    #+#             */
/*   Updated: 2020/05/09 07:59:43 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	size_t	len;
	char	*rst;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	while (*start != '\0' && ft_strchr(set, *start))
		start++;
	len = ft_strlen(start);
	while (len && ft_strchr(set, start[len]))
		len--;
	if (len == 0 && ft_strchr(set, start[len]))
		return (ft_strdup(""));
	rst = ft_substr(start, 0, len + 1);
	return (rst);
}
