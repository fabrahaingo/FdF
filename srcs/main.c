/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:15:34 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/15 16:15:35 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(int argc, char **argv)
{
	int **parsed_map;
	int fd;
	int i;
	int j;
	char buf[BUFF_SIZE + 1];

	parsed_map = NULL;
	i = 0;
	j = -1;
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
		ft_putendl("This type of file is not supported");
		return (-1);
	}
	read(fd, buf, BUFF_SIZE);
	parsed_map = parse_map(buf);
	if (!parsed_map)
	{
		ft_putendl("This map is not supported");
		return (-1);
	}
	if (parsed_map)
	{
		while (parsed_map[i])
		{
			while (parsed_map[i][++j])
				ft_putnbr(parsed_map[i][j]);
			j = -1;
			i++;
		}
	}
	return (0);
}
