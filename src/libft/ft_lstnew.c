/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:00:52 by charmon           #+#    #+#             */
/*   Updated: 2020/05/11 12:58:17 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*rst;

	rst = (t_list *)malloc(sizeof(t_list));
	if (!rst)
		return (NULL);
	rst->content = content;
	rst->next = NULL;
	return (rst);
}
