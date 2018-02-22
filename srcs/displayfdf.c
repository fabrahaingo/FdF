/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayfdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:11:00 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/22 16:11:01 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void displayfdf(t_all all, char *name)
{
	t_fpix pix1;
	t_fpix pix2;

	pix1.x = 250;
	pix1.y = 250;
	pix1.color = 0xFFFFFFF;
	pix2.x = 500;
	pix2.y = 400;
	pix2.color = 0xFFFFFFF;
	MLX.mlx_ptr = mlx_init();
	MLX.win_ptr = mlx_new_window(MLX.mlx_ptr, MAP.width, MAP.height, name);
	drawline(pix1, pix2, all);
	mlx_loop(MLX.mlx_ptr);
}
