#ifndef CUB3D_PARSING_H
#define CUB3D_PARSING_H

#include <fcntl.h>
#define LIGAL_SIMBOLS "NSOWEAFCR10 23456789"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

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
}           t_data;

#endif
