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
	int done;
	int fd;
	char *full_map;

	i = 0;
	done = 1;
	full_map = "\0";
	if ((fd = put_error(argc, argv)) == -1)
		return (-1);
	full_map = get_fullmap(fd);
	parsed_map = fill_fullmap(full_map);
	if (!parsed_map)
	{
		ft_putendl("This map could no be parsed");
		return (-1);
	}
	else
	{
		return (0);
	}
	return (0);
}
