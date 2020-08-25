/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:16:40 by charmon           #+#    #+#             */
/*   Updated: 2020/08/12 21:36:43 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

static int	check_and_counting_lines(int idx, t_data *data, size_t *max)
{
	int		count;
	char	**lines;
	size_t	len;

	lines = data->data_lines;
	count = 0;
	*max = 0;
	while (lines[idx] != NULL && data->error == 0)
	{
		if (!symbols_in_str(lines[idx], LIGAL_MAP_SIMBOLS) && !data->map_finish
			&& *(lines[idx]) != '\0')
		{
			count++;
			len = ft_strlen(lines[idx]);
			*max = (len > *max) ? len : *max;
		}
		else if (!symbols_in_str(lines[idx], " 2") || *(lines[idx]) == '\0')
			data->map_finish = 1;
		else
			data->error = 3;
		idx++;
	}
	return (count);
}

static char	*create_line(size_t len, t_data *data, char *str)
{
	size_t	idx;
	char	*line;

	idx = 0;
	if (!(line = (char*)malloc(sizeof(char) * (len + 1))))
	{
		data->error = 2;
		return (NULL);
	}
	while (idx < len)
		line[idx++] = ' ';
	line[len] = '\0';
	idx = 0;
	while (str[idx])
	{
		line[idx] = str[idx];
		idx++;
	}
	return (line);
}

void		parse_map(int start_idx, t_data *data)
{
	size_t	max;
	int		count;
	int		idx;

	count = check_and_counting_lines(start_idx, data, &max);
	if (data->error)
		return ;
	data->map_line_count = count;
	data->map_rows_count = max;
	if (!(data->map = (char**)malloc((sizeof(char*) * (count + 1)))))
	{
		data->error = 2;
		return ;
	}
	idx = 0;
	while (idx < count && data->error == 0)
	{
		data->map[idx] = create_line(max, data, data->data_lines[start_idx]);
		idx++;
		start_idx++;
	}
	data->map[idx] = NULL;
	if (data->error == 2)
		clear_2x_list(data->map);
}
