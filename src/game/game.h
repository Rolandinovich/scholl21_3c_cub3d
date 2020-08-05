#ifndef CUB3D_PARSING_H
#define CUB3D_PARSING_H

#include <fcntl.h>
#include <unistd.h>
#define LIGAL_SIMBOLS "NSOWEAFCR10 23456789"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
//0 ok
//1 read_file_error
//2 can't allocate memory


typedef struct s_data
{
    char *no;
    char *so;
    char *we;
    char *ea;
    char *s;
    int f[3];
    int c[3];
    int r[2];
    int map_res[2];
    char **map;
    char **data_lines;
    int error;
}           t_data;

void		load_data(char *file, t_data *data);
void		make_map(char *file, t_data *data);

#endif
