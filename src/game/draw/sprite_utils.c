/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:16:52 by charmon           #+#    #+#             */
/*   Updated: 2020/09/20 10:43:55 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void draw_sprite(t_sprites sprite, t_all all)
{
	float s_dir;

	float sprite_dir = atan2(sprite.y - all.player.y, sprite.x - all.player.x);
	while (sprite_dir - all.player.dir >  M_PI) sprite_dir -= 2*M_PI;
	while (sprite_dir - all.player.dir < -M_PI) sprite_dir += 2*M_PI;
	float sprite_dist = sqrt(pow(all.player.x - sprite.x, 2) + pow(all.player.y - sprite.y, 2));
	size_t sprite_screen_size =(int)(all.win_h/sprite_dist);
	int h_offset = (sprite_dir - all.player.dir)*(all.win_w)/(all.player.fov) + (all.win_w)/2 - sprite_screen_size/2;
	for (size_t i=0; i<sprite_screen_size; i++) {
		if (h_offset+(int)i<0 || h_offset+i>=all.win_w) continue;
		if (all.col_h[h_offset+(int)i] > sprite_dist)
//			sprite_column(all, all.sprite,all.win_h/(sprite_dist*cos(s_dir - all.player.dir)),(i/(float)sprite_screen_size)*all.sprite.width, (size_t)h_offset+i);
			sprite_column(all, all.sprite,sprite_screen_size,(i/(float)sprite_screen_size)*all.sprite.width, (size_t)h_offset+i);
	}
}

void update_sprite_distance(t_all all)
{
	int i;
	int k;
	float dist;
	t_player plr;

	i = -1;
	plr = all.player;
	while (++i < all.sprite_c)
		all.sprites[i].dist = sqrt(pow(plr.x - all.sprites[i].x, 2)
								   + pow(plr.y - all.sprites[i].y, 2));
	k=0;
	while (k != -1)
	{
		i = -1;
		k=-1;
		dist = -1;
		while (++i < all.sprite_c)
			if (all.sprites[i].dist > dist)
			{
				k=i;
				dist = all.sprites[i].dist;
			}
		if (k !=-1)
		{
			draw_sprite(all.sprites[k], all);
			all.sprites[k].dist=-1;
		}
	}
}