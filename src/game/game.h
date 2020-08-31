#ifndef CUB3D_PARSING_H
#define CUB3D_PARSING_H

#include <fcntl.h>
#include <unistd.h>
#define LIGAL_R_SIMBOLS "R 1234567890"
#define LIGAL_F_SIMBOLS "F, 1234567890"
#define LIGAL_C_SIMBOLS "C, 1234567890"
#define LIGAL_MAP_SIMBOLS " 120NSEW"
#define SIZE 8
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "../minilibx_ubuntu/mlx.h"
#include <math.h>
//0 ok
//1 read_file_error
//2 can't allocate memory
//3 validation error


typedef struct s_data
{
    char *no;
    int  no_fill;
    char *so;
    int so_fill;
    char *we;
    int we_fill;
    char *ea;
    int ea_fill;
    char *s;
    int s_fill;
    int f[3];
    int f_fill;
    int c[3];
	int c_fill;
    int r[2];
	int r_fill;
	int first_part_fill;
    char **map;
    int	map_line_count;
    int map_rows_count;
    char orientation;
    double 	position[2];
	int map_start;
	int map_finish;
    char **data_lines;
    int error;
}           t_data;

typedef struct		s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		endian;
	int		bits_per_pixel;
	int		line_length;
}					t_win;

typedef struct		s_plr
{
	int		player_x;
	int		player_y;
	float	player_a;
	float	angel;
	float	player_start;
	float	player_end;
}					t_plr;

typedef struct		s_player
{
	double 	x;
	double	y;
	double	fov;
	double	dir;
	double 	speed;
	double 	step;
}					t_player;

typedef struct		s_place
{
	float	x;
	float	y;
	float	fov;
}					t_place;

typedef struct		s_key
{
	int		w;
	int		s;
	int		a;
	int		d;
	int		l_arrow;
	int		r_arrow;
}					t_key;

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

typedef struct		s_all
{
	t_win	*win;
	int 	win_w;
	int 	win_h;
	t_key	*key;
	char	**map;
	t_img	textures[255];
	t_img	sprite;
	t_player player;
	int 	error;
	int		color_f;
	int		color_c;
}					t_all;


void		load_data(char *file, t_data *data);
int			make_map(char *file, t_data *data);
int			symbols_in_str(char *str, char *symbols);
void		clear_2x_list(char **list);
int			parsing(t_data *data);
void		data_init(t_data *data);
void		space2comma(char *str);
void		parsing_r(char *str, t_data *data);
void		parsing_f(char *str, t_data *data);
void		parsing_c(char *str, t_data *data);
void		parsing_no(char *str, t_data *data);
void		parsing_so(char *str, t_data *data);
void		parsing_we(char *str, t_data *data);
void		parsing_ea(char *str, t_data *data);
void		parsing_s(char *str, t_data *data);
void		parse_undefined_line(char *str, t_data *data);
void		check_first_part_fill(t_data *data);
void 		parse_map(int start_idx, t_data *data);
void        verify_map(t_data *data);
int			init_data_1(t_data *data, t_all *all);
void		pixel_put(t_all *data, int x, int y, int color);
void		put_rectangle(t_all *all, int start_x, int start_y, int end_x, int end_y, int color);
void		draw_circle(t_all all);
float		calc_text_distance(t_all all, float agile, char *texture, float *textcord);
float		calc_sprite_distance(t_all all, float agile);
void 		draw_f_c(t_all all);


#endif
