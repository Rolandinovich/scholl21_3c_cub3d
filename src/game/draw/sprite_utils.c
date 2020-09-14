#include "../game.h"

void draw_sprite(t_sprites sprite, t_all all)
{

	float sprite_dir = atan2(sprite.y - all.player.y, sprite.x - all.player.x);
	while (sprite_dir - all.player.dir >  M_PI) sprite_dir -= 2*M_PI;
	while (sprite_dir - all.player.dir < -M_PI) sprite_dir += 2*M_PI;
	float sprite_dist = sqrt(pow(all.player.x - sprite.x, 2) + pow(all.player.y - sprite.y, 2));
	size_t sprite_screen_size =(int)(all.win_h/sprite_dist);
	int h_offset = (sprite_dir - all.player.dir)*(all.win_w)/(all.player.fov) + (all.win_w)/2 - sprite_screen_size/2;
	for (size_t i=0; i<sprite_screen_size; i++) {
		if (h_offset+(int)i<0 || h_offset+i>=all.win_w) continue;
		if (all.col_h[h_offset+(int)i] > sprite_dist)
			sprite_column(all, all.sprite,sprite_screen_size,(i/(float)sprite_screen_size)*all.sprite.width, (size_t)h_offset+i);
	}
}

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
//		min = acos((all.sprites[i].x - plr.x) / dist);
//		if (min < 0)
//			min += M_PI;
////		max = ((all.sprites[i].x - plr.x) / dist);
//		if ( min > min_a && min < max_a)
	all.sprites[i].dist = dist;
	draw_sprite(all.sprites[i], all);
//		else
//			all.sprites[i].dist = -1;
	}
}