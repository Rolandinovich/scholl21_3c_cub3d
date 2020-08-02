/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:42:22 by charmon           #+#    #+#             */
/*   Updated: 2020/05/08 16:57:36 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	char	buf[11];
	int		sign;
	int		idx;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n == 0)
		return (ft_putstr_fd("0", fd));
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
	while (--idx >= 0)
		ft_putchar_fd(buf[idx], fd);
}
