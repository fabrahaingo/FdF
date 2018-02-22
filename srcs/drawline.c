/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:31:22 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/22 16:31:24 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_coefx(t_fpix pix1, t_fpix pix2)
{
	int x;
	int y;
	int coefx;

	x = pix1.x - pix2.x;
	y = pix1.y - pix2.y;
	coefx = x / abs(y);
	return (coefx);
}

int		ft_coefy(t_fpix pix1, t_fpix pix2)
{
	int x;
	int y;
	int coefy;

	x = pix1.x - pix2.x;
	y = pix1.y - pix2.y;
	coefy = y / abs(y);
	return (coefy);
}

void	drawline(t_fpix pix1, t_fpix pix2, t_all all)
{
	int coefx;
	int coefy;
	int signx;
	int signy;

	if (pix1.x == pix2.x && pix1.y == pix2.y)
		return ;
	coefy = ft_coefy(pix1, pix2);
	signy = copysign(1, coefy);
	coefx = ft_coefx(pix1, pix2);
	signx = copysign(1, coefx);
	if (abs(coefx) <= abs(coefy))
	{
		while (pix1.y != pix2.y)
		{
			mlx_pixel_put(MLX.mlx_ptr, MLX.win_ptr, pix1.x, pix1.y, pix1.color);
			coefx = ft_coefx(pix1, pix2);
			pix1.x = pix1.x + coefx * signx;
			pix1.y = pix1.y + 1;
		}
	}
	else
	{
		while (pix1.x != pix2.x)
		{
			mlx_pixel_put(MLX.mlx_ptr, MLX.win_ptr, pix1.x, pix1.y, pix1.color);
			coefy = ft_coefy(pix1, pix2);
			pix1.x = pix1.x + 1;
			pix1.y = pix1.y + coefy * signy;
		}
	}
}
