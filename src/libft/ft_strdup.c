/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:35:24 by charmon           #+#    #+#             */
/*   Updated: 2020/05/03 08:40:14 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_line;

	len = ft_strlen(s);
	new_line = (char *)malloc((len + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, s, len + 1);
	return (new_line);
}
