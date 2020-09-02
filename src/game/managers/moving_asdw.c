#include "../game.h"

void	move_forward(t_all *all)
{
	float new_x;
	float new_y;

	new_x = all->player.x;
	new_y = all->player.y - all->player.speed;
	if (all->map[(int)new_y][(int)new_x] == '0')
	{
		all->player.x = new_x;
		all->player.y = new_y;
	}
}
void	move_backward(t_all *all)
{
	float new_x;
	float new_y;

	new_x = all->player.x;
	new_y = all->player.y + all->player.speed;
	if (all->map[(int)new_y][(int)new_x] == '0')
	{
		all->player.x = new_x;
		all->player.y = new_y;
	}
}

void	move_left(t_all *all)
{
	float new_x;
	float new_y;

	new_x = all->player.x - all->player.speed;
	new_y = all->player.y;
	if (all->map[(int)new_y][(int)new_x] == '0')
	{
		all->player.x = new_x;
		all->player.y = new_y;
	}
}

void	move_right(t_all *all)
{
	float new_x;
	float new_y;

	new_x = all->player.x + all->player.speed;
	new_y = all->player.y;
	if (all->map[(int)new_y][(int)new_x] == '0')
	{
		all->player.x = new_x;
		all->player.y = new_y;
	}
}