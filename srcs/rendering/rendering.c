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

static void fill_pixel(char *img_str, int x, int y, int color, int line_nb)
{
	int i;

	(void)line_nb;
	i = 0 + 4 * x * 750;
	i = i + 4 * y;
	img_str[i + 2] = (char)(color / 1000000);
	color /= 1000;
	img_str[i + 1] = (char)(color / 1000);
	color /= 1000;
	img_str[i] = (char)(color);
}

int		rendering(char *file_name, int line_nb, t_all *all)
{
	int		x;
	int		y;


	all->mlx->bpp = 0;
	all->mlx->s_l = 0;
	all->mlx->endian = 0;
	x = 750;
	y = 500;
	if (!all->map->int_map)
	{
		ft_putendl("The map could not be parsed");
		return (-1);
	}
	all->mlx->mlx_ptr = mlx_init();
	all->mlx->win_ptr = mlx_new_window(all->mlx->mlx_ptr, x, y, file_name);
	all->mlx->img_ptr = mlx_new_image(all->mlx->mlx_ptr, x, y);
	all->mlx->img_str = mlx_get_data_addr(all->mlx->img_ptr, &(all->mlx->bpp), &(all->mlx->s_l), &(all->mlx->endian));
	fill_pixel(all->mlx->img_str, 250, 250, 255255255, line_nb);
	mlx_put_image_to_window(all->mlx->mlx_ptr, all->mlx->win_ptr, all->mlx->img_ptr, 0, 0);
	mlx_loop(all->mlx->mlx_ptr);
	return(0);
}
