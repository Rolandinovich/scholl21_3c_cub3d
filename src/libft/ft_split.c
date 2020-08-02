/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:31:25 by charmon           #+#    #+#             */
/*   Updated: 2020/05/11 08:01:06 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_word(char **s, char c)
{
	char	*start;
	char	*rst;
	size_t	len;

	while (**s == c && **s != '\0')
		(*s)++;
	len = 0;
	start = *s;
	while (start[len] != c && start[len] != '\0')
	{
		len++;
		(*s)++;
	}
	rst = ft_substr(start, 0, len);
	return (rst);
}

static	int	get_word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
		if (*s == c)
			while (*s == c && *s != '\0')
				s++;
		else
		{
			s++;
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	return (count);
}

static void	clear_rst(char **mas)
{
	size_t	idx;

	idx = 0;
	while (mas[idx])
		free(mas[idx++]);
	free(mas);
}

char		**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	idx;
	char	**rst;
	char	*start;

	if (!s)
		return (NULL);
	count = get_word_count(s, c);
	rst = (char **)malloc((count + 1) * sizeof(char *));
	if (!rst)
		return (NULL);
	idx = 0;
	rst[count] = NULL;
	start = (char *)s;
	while (idx < count)
	{
		rst[idx] = get_word(&start, c);
		if (!rst[idx++])
		{
			clear_rst(rst);
			return (NULL);
		}
	}
	return (rst);
}
