#include "../game.h"

void		make_map(char *file, t_data *data)
{
	int		idx;

	load_data(file, data);
	idx = -1;
	while ((*data).data_lines[++idx])
	{
		ft_putstr_fd((*data).data_lines[idx], 1);
		ft_putstr_fd("\n", 1);
	}
}
