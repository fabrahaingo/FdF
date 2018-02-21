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

int		rendering(char *file_name, int line_nb, t_all *all)
{
	MLX.bpp = 0;
	MLX.s_l = 0;
	MLX.endian = 0;
	if (!all->map.int_map)
	{
		ft_putendl("The map could not be parsed");
		return (-1);
	}
	MLX.mlx_ptr = mlx_init();
	MLX.win_ptr = mlx_new_window(MLX.mlx_ptr, MAP.width, MAP.height, file_name);
	MLX.img_ptr = mlx_new_image(MLX.mlx_ptr, MAP.width, MAP.height);
	MLX.img_str = mlx_get_data_addr(MLX.img_ptr, &(MLX.bpp), &(MLX.s_l), &(MLX.endian));
	fill_pixel(MLX.img_str, 250, 400, 255255255, line_nb);
	mlx_put_image_to_window(MLX.mlx_ptr, MLX.win_ptr, MLX.img_ptr, 0, 0);
	mlx_loop(MLX.mlx_ptr);
	return(0);
}
