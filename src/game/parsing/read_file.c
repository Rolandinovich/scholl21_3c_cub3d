/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:10:32 by charmon           #+#    #+#             */
/*   Updated: 2020/09/03 09:31:39 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int			count_lines(char *file, t_data *data)
{
	char	*line;
	int		fd;
	int		res;
	int		count;

	data->error = 1;
	if (!(fd = open(file, O_RDONLY)))
		return (-1);
	count = 0;
	while ((res = get_next_line(fd, &line)) >= 0)
	{
		free(line);
		count++;
		if (res == 0)
			break ;
	}
	data->error = 0;
	return (count);
}

void		load_data(char *file, t_data *data)
{
	int		fd;
	int		count;
	int		idx;

	(*data).error = 1;
	count = count_lines(file, data);
	if (!(data->data_lines = (char**)malloc(sizeof(char*) * (count + 1))))
		return ;
	idx = -1;
	if (!(fd = open(file, O_RDONLY)))
		return ;
	while (++idx < count)
		get_next_line(fd, &((*data).data_lines[idx]));
	(*data).data_lines[idx] = NULL;
	close(fd);
	(*data).error = 0;
}
