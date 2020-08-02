/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:33:37 by charmon           #+#    #+#             */
/*   Updated: 2020/05/08 17:17:55 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_revers(char *s)
{
	int		len;
	int		idx;
	char	*rst;

	len = ft_strlen(s);
	rst = (char *)malloc((len + 1) * sizeof(char));
	if (!rst)
		return (NULL);
	idx = -1;
	while (++idx < len)
		rst[idx] = s[len - idx - 1];
	rst[idx] = '\0';
	return (rst);
}

char		*ft_itoa(int n)
{
	char	buf[11];
	int		sign;
	int		idx;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	idx = 0;
	while (n != 0)
	{
		buf[idx++] = (char)(n % 10 + '0');
		n = n / 10;
	}
	if (sign)
		buf[idx++] = '-';
	buf[idx] = '\0';
	return (ft_revers(buf));
}
