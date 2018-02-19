/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:33:40 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/19 17:33:41 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void fill_pixel(char *my_image_string, int x, int y, int color)
{
	int i;

	i = 0;
	i = i +
}

int		rendering(int **map, char *file_name, int line_nb)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		endian;

	bpp = 0;
	s_l = 0;
	endian = 0;
	if (!map)
	{
		ft_putendl("The map could not be parsed");
		return (-1);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1500, file_name);
	img_ptr = mlx_new_image(mlx_ptr, 1000, 1500);
	img_str = mlx_get_data_addr(img_ptr, &(bpp), &(s_l), &(endian));
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return(0);
}
