/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:16:25 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/15 16:16:27 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MLX all.mlx
# define MAP all.map
# define PIX all.pix;

#include "mlx.h"
#include <math.h>
#include "../libft/libft.h"

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		endian;
}				t_mlx;

typedef struct	s_map
{
	int height;
	int width;
	int columns;
	int lines;
	int **int_map;
}				t_map;

typedef struct	s_fpix
{
	int	x;
	int	y;
	int	color;
}				t_fpix;

typedef struct	s_pix
{
	int		x;
	int		y;
	int		z;
	int		color;
	t_fpix	fpix;
}				t_pix;

typedef struct	s_all
{
	t_mlx	mlx;
	t_map	map;
	t_pix	pix;
}				t_all;

int		**fill_fullmap(char *char_map);
int		put_error(int argc, char **argv);
char	*get_fullmap(int fd);
void	fill_pixel(char *img_str, int x, int y, int color, t_map map);
void	displayfdf(t_all all, char *name);
void	drawline(t_fpix pix1, t_fpix pix2, t_all all);

#endif
