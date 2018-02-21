/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_pix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:15:16 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/21 19:15:17 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	modify_pix(t_pix pix, t_fpix fpix, int pos)
{
	fpix.x = (pix.x + pos);
	fpix.y = (pix.y + pos);
	fpix.color = pix.color;
}
