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

int			main(int argc, char **argv)
{
	int		**parsed_map;
	int		fd;
	int		line_nb;
	char	*full_map;

	full_map = NULL;
	if ((fd = put_error(argc, argv)) == -1)
		return (-1);
	full_map = get_fullmap(fd);
	line_nb = count_lines(full_map);
	parsed_map = fill_fullmap(full_map);
	if (rendering(parsed_map, argv[1], line_nb) == -1)
		return (-1);
	return (0);
}
