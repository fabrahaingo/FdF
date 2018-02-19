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
	int_map = (int **)malloc(sizeof(int *) * j + 1);
	int_map[j] = NULL;
	i = -1;
	j = 0;
	while (char_map[++i] != '\n')
	{
		while (char_map[i] == ' ')
			i++;
		if (ft_isdigit(char_map[i]))
		{
			if (!ft_isdigit(char_map[i + 1]))
				j++;
		}
		else
		{
			if (char_map[i] != ' ' || char_map[i] != '\n')
				return (NULL);
		}
	}
	i = -1;
	while (int_map[++i])
		int_map[i] = (int *)malloc(sizeof(int) * j);
	return (int_map);
}

int **fill_fullmap(char *char_map)
{
	int **int_map;
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	int_map = NULL;
	int_map = map_size(char_map, int_map);
	if (!char_map)
		return (NULL);
	while (char_map[i])
	{
		if (ft_isdigit(char_map[i]))
		{
			int_map[y][x] = ft_atoi(char_map + i);
			while (ft_isdigit(char_map[i]) && char_map[i] != '\n')
				i++;
			if (char_map[i] == '\n')
				y++;
			x++;
		}
		i++;
	}
	return (int_map);
}
