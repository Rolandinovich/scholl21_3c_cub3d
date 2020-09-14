#include "../game.h"

void update_sprite_distance(t_all all)
{
	int i;
	float min_a;
	float max_a;
	float dist;
	t_player plr;

	i = -1;
	plr = all.player;
	min_a = plr.dir - plr.fov/2;
	max_a = plr.dir + plr.fov/2;
	while (++i < all.sprite_c)
	{
		dist = sqrt(pow(plr.x - all.sprites[i].x, 2)
				+ pow(plr.y - all.sprites[i].y, 2));
		if (((all.sprites[i].x - plr.x) / dist) > cos(min_a) && ((all.sprites[i].x - plr.x) / dist) < cos(max_a))
			all.sprites[i].dist = dist;
		else
			all.sprites[i].dist = -1;
	}
}