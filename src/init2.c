#include "game/game.h"

int	init_data_2(t_data *data, t_all *all)
{
	int		idx_x;
	int		idx_y;

	idx_x = -1;
	all->sprite_c = 0;
	while (++idx_x < data->map_rows_count && !data->error)
	{
		idx_y = -1;
		while (++idx_y < data->map_line_count && !data->error)
		{
			if (data->map[idx_y][idx_x] == '2')
			{
				all->sprites[all->sprite_c].x = idx_x + 0.5;
				all->sprites[all->sprite_c].y = idx_y + 0.5;
				all->sprites[all->sprite_c++].dist = -1;
			}
		}
	}
	return (0);
}