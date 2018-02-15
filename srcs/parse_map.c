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

int *map_size(char *char_map, int **int_map)
{
	int **int_map;
	int i;
	int j;

	i = 0;
	j = 0;
	while (char_map[i])
	{
		if ()
	}
}

int **parse_map(char *char_map)
{
	char **int_map;

	int_map = NULL;
	int_map = map_size(char_map, int_map);
	if (!int_map)
		return (NULL);

}
