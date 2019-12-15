/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_relative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:10:32 by dapinto           #+#    #+#             */
/*   Updated: 2019/07/18 15:14:08 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_relative(t_map *map, t_tetri *node, int y, int x)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (y + node->coor[j][0] >= map->size
				|| x + node->coor[j][1] >= map->size
				|| map->map[y + node->coor[j][0]][x + node->coor[j][1]] != '.')
			return (0);
		j++;
	}
	return (1);
}
