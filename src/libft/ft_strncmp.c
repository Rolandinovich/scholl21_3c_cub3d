/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 22:04:57 by charmon           #+#    #+#             */
/*   Updated: 2020/05/07 09:22:15 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (!n)
		return (0);
	idx = 0;
	while (s1[idx] == s2[idx] && s1[idx] != '\0'
	&& s2[idx] != '\0' && idx < n - 1)
		idx++;
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
