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

#include "mlx.h"
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
	int **int_map;
}				t_map;

typedef struct	s_all
{
	t_mlx	*mlx;
	t_map	*map;
}				t_all;

int		**fill_fullmap(char *char_map);
int		put_error(int argc, char **argv);
char	*get_fullmap(int fd);
int		rendering(char *file_name, int line_nb, t_all *all);

#endif
