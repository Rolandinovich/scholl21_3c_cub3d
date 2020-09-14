#include "../game.h"

void update_sprite_distance(t_all all)
{
	int i;
	float min_a;
	float max_a;
	float dist;
	t_player plr;
	float min;
	float max;

	i = -1;
	plr = all.player;
	min_a = plr.dir - plr.fov/2;
	max_a = plr.dir + plr.fov/2;
	while (++i < all.sprite_c)
	{
		dist = sqrt(pow(plr.x - all.sprites[i].x, 2)
				+ pow(plr.y - all.sprites[i].y, 2));
		min = ((all.sprites[i].x - plr.x) / dist);
		if (min < 0)
			min += M_PI;
//		max = ((all.sprites[i].x - plr.x) / dist);
		if ( min > cos(min_a) && min < cos(max_a))
			all.sprites[i].dist = dist;
		else
			all.sprites[i].dist = -1;
	}
}