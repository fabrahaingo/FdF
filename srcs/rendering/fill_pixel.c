/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:03:37 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/21 16:03:41 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void fill_pixel(char *img_str, int x, int y, int color, int line_nb)
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
