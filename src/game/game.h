#ifndef CUB3D_PARSING_H
#define CUB3D_PARSING_H

#include <fcntl.h>
#include <unistd.h>
#define LIGAL_R_SIMBOLS "R 1234567890"
#define LIGAL_F_SIMBOLS "F, 1234567890"
#define LIGAL_C_SIMBOLS "C, 1234567890"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
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
	int map_fill;
    char **data_lines;
    int error;
}           t_data;

void		load_data(char *file, t_data *data);
void		make_map(char *file, t_data *data);
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

#endif
