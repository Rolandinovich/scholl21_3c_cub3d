#include "game.h"

int start_game(t_data *data) {
	t_plr plr;
	t_key key;
	t_win win;
	t_all all;
	t_place place;
	t_place end;
	int idx;
	int idy;
	int size;

	ft_bzero(&key, sizeof(t_key));
	all.key = &key;
	ft_bzero(&plr, sizeof(t_plr));
	win.mlx = mlx_init();
	int win_w = 700;
	int win_h = 512;
	win.win = mlx_new_window(win.mlx, win_w, win_h, "CUB2D");
	win.img = mlx_new_image(win.mlx, win_w, win_h);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.endian);
	all.win = &win;
	size = 20;
	place.x = 0;
	place.y = 0;
	end.x = place.x + size;
	end.y = place.y + size;
	idx = -1;
//	while (++idx < data->map_rows_count) {
//		idy = -1;
//		place.y = 0;
//		end.y = place.y + size;
//		while (++idy < data->map_line_count) {
//			if (data->map[idy][idx] == '1')
//				put_rectangle(&all, place.x, place.y, end.x, end.y);
//			place.y += size;
//			end.y = place.y + size;
//		}
//		place.x += size;
//		end.x = place.x + size;
//	}
	const float fov = M_PI/3.;
//	double plr_a = 3 * M_PI / 2;
	double plr_a = 0;
	float c = 0;
	data->map[(int) data->position[1]][(int) data->position[0]] = '0';
	for (double plr_a = 0.1; plr_a <= M_PI*2; plr_a = plr_a + 0.1) {
		put_rectangle(&all, 0, 0, 700, 512, 0xFFFFFFFF);
		for (size_t i = 0; i < win_w; i++) { // draw the visibility cone
			float angle = plr_a - fov/2 + fov*i/(float) win_w;
			for (float t = 0; t < 20; t += .01) {
				float cx = data->position[0] + t*cos(angle);
				float cy = data->position[1] + t*sin(angle);
				if (data->map[(int) cy][(int) cx]!='0') {
					size_t column_height = win_h/(t*cos(angle - plr_a));
					put_rectangle(&all, i, win_h/2 - column_height*0.5, i + 1, win_h/2 + column_height*0.5, 0x0000FF00);
					break;
				}
			}
		}
		mlx_put_image_to_window(all.win->mlx, all.win->win, all.win->img, 0, 0);
//		mlx_destroy_image(all.win->mlx, all.win->img);
//		win.img = mlx_new_image(win.mlx, win_w, win_h);
//		win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.endian);
//		all.win = &win;
//		sleep(1);
	}
//	int32_t *img;
	char *relative_path = "./src/textures/east.xpm";
	int img_width;
	int img_height;

	typedef struct	s_img
	{
		void		*ptr;
		int			*data;
		int			bpp;
		int			endian;
		int			size_l;
		int			width;
		int			height;
	}				t_img;
	t_img img;
	int color;

//	dt = mlx_xpm_file_to_image(all.win->mlx, relative_path, &img_width, &img_height);
//	dt = (int*)mlx_get_data_addr(img,&bpp, &data->weapon.size_l, &data->weapon.endian);
	img.ptr = mlx_xpm_file_to_image(all.win->mlx, relative_path,
											 &img.width, &img.height);
	img.data = (int*)mlx_get_data_addr(img.ptr,
												&img.bpp, &img.size_l, &img.endian);
	for (int x = 0; x < 64; x++)
		for (int y = 0; y < 64; y++) {
			color = img.data[(int)((int)x + (int)y *
				(img.width))];
			pixel_put(&all, x+50, y+50, color);
		}
	mlx_put_image_to_window(all.win->mlx, all.win->win, all.win->img, 0, 0);
	mlx_loop(win.mlx);
}