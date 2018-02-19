/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fullmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:27:32 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/19 13:27:34 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*get_fullmap(int fd)
{
	char	*str;
	char	*buf;
	char	*tmp;
	char	*res;
	int		i;

	tmp = 0;
	str = 0;
	i = 0;
	while (get_next_line(fd, &buf))
	{
		tmp = str;
		if (i == 0)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		tmp = str;
		str = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
		i = i + 1;
	}
	res = ft_strdup(str);
	ft_strdel(&str);
	return (res);
}
