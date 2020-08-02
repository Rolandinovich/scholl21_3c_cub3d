/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:26:28 by charmon           #+#    #+#             */
/*   Updated: 2020/05/03 08:53:27 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx;
	size_t	idx2;
	size_t	len;
	char	*rst;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	rst = (char *)malloc((len + 1) * sizeof(char));
	if (!rst)
		return (NULL);
	idx = -1;
	while (s1[++idx] != '\0')
		rst[idx] = s1[idx];
	idx2 = idx;
	idx = -1;
	while (s2[++idx] != '\0')
		rst[idx2++] = s2[idx];
	rst[idx2] = '\0';
	return (rst);
}
