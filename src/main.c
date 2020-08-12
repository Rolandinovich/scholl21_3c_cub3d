/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmon <charmon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:09:25 by charmon           #+#    #+#             */
/*   Updated: 2020/08/12 22:28:42 by charmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

#include "minilibx_ubuntu/mlx.h"

int main(int argc, char **argv) {
    t_data data;

    argc++;
    void *mlx_ptr;
    void *win_ptr;

	make_map(argv[1], &data);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "uraaaa");
	mlx_loop(mlx_ptr);


    return 0;
}
