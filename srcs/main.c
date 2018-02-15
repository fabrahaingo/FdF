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
	int i;
	int j;
	int done;
	int fd;
	char buf[BUFF_SIZE + 1];
	char *full_map;

	parsed_map = NULL;
	i = 0;
	full_map = NULL;
	done = 1;
	fd = 0;
	if (put_error(argc, argv[1]) == -1)
		return (-1);
	while (done)
	{
		done = read(fd, buf, BUFF_SIZE);
		if (done == -1)
		{
			ft_putstr("This map is not supported");
			return (-1);
		}
		full_map = ft_strjoin(full_map, buf);
		free(buf);
		if (done == 0)
			break ;
	}
	parsed_map = parse_map(full_map);
	if (!parsed_map)
	{
		ft_putendl("This map is not well formated");
		return (-1);
	}
	else
	{
		j = -1;
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
