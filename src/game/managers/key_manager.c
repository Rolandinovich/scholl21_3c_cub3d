
#include "../game.h"

int		key_manager(t_all *all)
{
	if (all->key.toward == 1)
		move_forward(all);
	if (all->key.backward == 1)
		move_backward(all);
	if (all->key.left == 1)
		move_left(all);
	if (all->key.right == 1)
		move_right(all);
	if (all->key.turn_left == 1)
		all->player.dir -= all->player.fov_step;
	if (all->key.turn_right == 1)
		all->player.dir += all->player.fov_step;
	if (all->player.dir > 2* M_PI)
		all->player.dir -= 2 * M_PI;
	if (all->player.dir < 0)
		all->player.dir = 2 * M_PI;
	return (0);
}

int		event_key_released(	int key,	void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (key == TOWARD && all->key.toward == 1)
		all->key.toward = 0;
	else if (key == BACKWARD && all->key.backward == 1)
		all->key.backward = 0;
	else if (key == LEFT && all->key.left == 1)
		all->key.left = 0;
	else if (key == RIGHT && all->key.right == 1)
		all->key.right = 0;
	else if (key == CAM_LEFT && all->key.turn_left == 1)
		all->key.turn_left = 0;
	else if (key == CAM_RIGHT && all->key.turn_right == 1)
		all->key.turn_right = 0;
	return (0);
}

int		event_key_pressed(	int key,	void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (key == ESC)
		close_win(0, all, "");
	else if (key == TOWARD && all->key.toward == 0)
		all->key.toward = 1;
	else if (key == BACKWARD && all->key.backward == 0)
		all->key.backward = 1;
	else if (key == LEFT && all->key.left == 0)
		all->key.left = 1;
	else if (key == RIGHT && all->key.right == 0)
		all->key.right = 1;
	else if (key == CAM_LEFT && all->key.turn_left == 0)
		all->key.turn_left = 1;
	else if (key == CAM_RIGHT && all->key.turn_right == 0)
		all->key.turn_right = 1;
	return (0);
}
