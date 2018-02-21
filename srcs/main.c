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

static int	count_lines(char *full_map)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (full_map[++i])
		if (full_map[i] == '\n')
			count++;
	return (count);
}

static int	count_columns(char *full_map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (full_map[i] != '\n')
	{
		if (ft_isdigit(full_map[i]))
		{
			while (ft_isdigit(full_map[i]) && full_map)
				i++;
			j++;
		}
		i++;
	}
	return (j);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		line_nb;
	char	*full_map;
	t_all	all;

	full_map = NULL;
	all.map.height = 500;
	all.map.width = 750;
	if ((fd = put_error(argc, argv)) == -1)
		return (-1);
	full_map = get_fullmap(fd);
	all.map.lines = count_lines(full_map);
	all.map.columns = count_columns(full_map);
	all.map.columns = count_columns(full_map);
	all.map.int_map = fill_fullmap(full_map);
	if (rendering(argv[1], line_nb, &all) == -1)
		return (-1);
	return (0);
}
