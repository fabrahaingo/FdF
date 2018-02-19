/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:16:25 by frahaing          #+#    #+#             */
/*   Updated: 2018/02/15 16:16:27 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include "../libft/libft.h"

int		**fill_fullmap(char *char_map);
int		put_error(int argc, char **argv);
char	*get_fullmap(int fd);

#endif
