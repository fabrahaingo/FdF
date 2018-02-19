/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:25:02 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/15 18:25:04 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int put_error(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc != 2)
	{
		if (argc > 2)
			ft_putendl("Too much arguments given");
		else
			ft_putendl("FdF needs a map in order to work");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("This file does not exist");
		return (-1);
	}
	return (fd);
}
