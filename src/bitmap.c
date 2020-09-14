#include "game/game.h"

static int		make_header(unsigned char *bmp_fheader, unsigned char
*bmpinfheader, t_all *all)
{
	int file_size;

	file_size = 14 + 40 + all->win_w * all->win_h
		* all->win->bits_per_pixel / 8;
	bmp_fheader[0] = 'B';
	bmp_fheader[1] = 'M';
	bmp_fheader[2] = (unsigned char)(file_size);
	bmp_fheader[3] = (unsigned char)(file_size >> 8);
	bmp_fheader[4] = (unsigned char)(file_size >> 16);
	bmp_fheader[5] = (unsigned char)(file_size >> 24);
	bmp_fheader[10] = (unsigned char)(14 + 40);
	bmpinfheader[0] = (unsigned char)(40);
	bmpinfheader[4] = (unsigned char)(all->win_w);
	bmpinfheader[5] = (unsigned char)(all->win_w >> 8);
	bmpinfheader[6] = (unsigned char)(all->win_w >> 16);
	bmpinfheader[7] = (unsigned char)(all->win_w >> 24);
	bmpinfheader[8] = (unsigned char)(-all->win_h);
	bmpinfheader[9] = (unsigned char)(-all->win_h >> 8);
	bmpinfheader[10] = (unsigned char)(-all->win_h >> 16);
	bmpinfheader[11] = (unsigned char)(-all->win_h >> 24);
	bmpinfheader[12] = (unsigned char)(1);
	bmpinfheader[14] = (unsigned char)(all->win->bits_per_pixel);
	return (1);
}

static int		write_in_header(unsigned char *bmp_fheader,
								  unsigned char *bmpinfheader, t_all *all)
{
	int		fd;
	char	*filename;
	int		len;
	int		i;

	i = 0;
	filename = "screenshot.bmp";
	if ((fd = open(filename, O_RDWR | O_CREAT, 0755)) < 0)
		return (0);
	write(fd, bmp_fheader, 14);
	write(fd, bmpinfheader, 40);
	len = all->win->bits_per_pixel / 8 * all->win_w;
	while (i < all->win_h)
	{
		write(fd, all->win->addr + i * all->win->line_length, len);
		i++;
	}
	if (close(fd < 0))
	{
		ft_putstr_fd("Close file error!\n", 0);
		return (0);
	}
	return (1);
}

int				shot_screen(t_all *all)
{
	unsigned char	bmp_fheader[14];
	unsigned char	bmpinfheader[40];

	ft_putstr_fd("Saving screenshot to screenshot.bpm\n", 0);
	ft_bzero(bmp_fheader, 14);
	ft_bzero(bmpinfheader, 40);
	make_header(bmp_fheader, bmpinfheader, all);
	if (!write_in_header(bmp_fheader, bmpinfheader, all))
		ft_putstr_fd("Saving screenshot failed!\n", 0);
//	free_all(all, 0);
	return (0);
}