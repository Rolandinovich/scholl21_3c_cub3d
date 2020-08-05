#include "../game.h"

static char	*read_file(int fd, t_data *data)
{
	char	buf[1025];
	int		count;
	char	*tmp;
	char	*text;

	text = NULL;
	while ((count = read(fd, buf, 1024)))
	{
		buf[count] = '\0';
		if (!(tmp = (text) ? ft_strjoin(text, buf) : ft_strjoin("", buf)))
		{
			(*data).error = 2;
			if (text)
				free(text);
			return (NULL);
		}
		free(text);
		text = tmp;
	}
	return (text);
}

void		load_data(char *file, t_data *data)
{
	int		fd;
	char	*text;

	if (!(fd = open(file, O_RDONLY)))
	{
		(*data).error = 1;
		return ;
	}
	if ((text = read_file(fd, data)))
	{
		(*data).data_lines = ft_split(text, '\n');
		if ((*data).data_lines)
			(*data).error = 0;
		else
			(*data).error = 2;
		free(text);
	}
	close(fd);
}
