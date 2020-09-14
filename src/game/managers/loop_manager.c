#include "../game.h"

int				loop_manager(void *param)
{
	t_all *all;

	all = (t_all *)param;
	draw_circle(*all);
	key_manager(all);
	return (0);
}
