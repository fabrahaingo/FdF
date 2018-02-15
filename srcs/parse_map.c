/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:47:51 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/15 17:47:52 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int **map_size(char *char_map, int **int_map)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (char_map[++i])
		if (char_map[i] == '\n')
			j++;
	int_map = (int **)ft_memalloc(sizeof(int *) * j);
	i = 0;
	j = 0;
	while (char_map[i] != '\n')
	{
		while (char_map[i] == ' ')
			i++;
		if (ft_isalpha(char_map[i]))
		{
			if (!ft_isalpha(char_map[i + 1]))
				j++;
		}
		else
		{
			if (char_map[i] != ' ' || char_map[i] != '\n')
				return (NULL);
		}
		i++;
	}
	i = -1;
	while (int_map[++i])
		int_map[i] = (int *)ft_memalloc(sizeof(int) * j);
	return (int_map);
}

int **parse_map(char *char_map)
{
	int **int_map;
	int i;
	int x;
	int y;

	i = -1;
	x = 0;
	y = 0;
	int_map = NULL;
	int_map = map_size(char_map, int_map);
	if (!int_map)
		return (NULL);
	while (char_map[++i])
	{
		if (char_map[i] == '\n')
			y++;
		if (ft_isalpha(char_map[i]))
			int_map[y][x++] = ft_atoi(char_map + i);
	}
	return (int_map);
}
