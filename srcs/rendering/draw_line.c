/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:13:15 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/21 13:13:16 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int		ft_coefx(t_pix pix1, t_pix pix2)
{
	int coefx;
	int x;
	int y;

	coefx = 0;
	x = pix1.x - pix2.x;
	y = pix1.y - pix2.y;
	coefx = (x / abs(y));
	return (coefx);
}

int		ft_coefy(t_pix pix1, t_pix pix2)
{
	int coefy;
	int x;
	int y;

	coefy = 0;
	x = pix1.x - pix2.x;
	y = pix1.y - pix2.y;
	coefy = (y / abs(x));
	return (coefy);
}

void	draw_line(t_pix	pix1, t_pix pix2, t_all all)
{
	int coefx;
	int coefy;
	int signx;
	int signy;

	coefx = ft_coefx(pix1, pix2);
	signx = copysign(1, coefx);
	coefy = ft_coefy(pix1, pix2);
	signy = copysign(1, coefy);
	if (coefx < coefy)
	{
		while (pix1.x != pix2.x)
		{
			fill_pixel(MLX->img_str, pix1.x, pix1.y, 255255255, all.map.lines);
		}
	}
}
