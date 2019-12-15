/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:13:29 by evogel            #+#    #+#             */
/*   Updated: 2019/07/18 15:13:31 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		map_fill(t_tetri *current, t_map *map)
{
	int y;
	int x;
	int ret;

	y = -1;
	while (++y < map->size)
	{
		x = -1;
		while (++x < map->size)
		{
			if (check_relative(map, current, y, x) == 1)
			{
				ft_placer(map->map, current, y, x);
				if (!(current->next))
					return (0);
				if ((ret = map_fill(current->next, map)) == 1)
					return (1);
				else if (ret == 0)
					return (0);
				ft_eraser(map->map, current, y, x);
			}
		}
	}
	return (-1);
}

t_map	*build_map(t_tetri *begin)
{
	t_map		*map;
	static int	size = 2;
	int			min_size;

	min_size = ft_sqrt(ft_listlen_tet(begin) * 4);
	if (size < min_size)
		size = min_size;
	if (!(map = map_set(size)))
		return (NULL);
	if (map_fill(begin, map) == -1)
	{
		ft_tabdel(size - 1, &(map->map));
		free(map);
		size++;
		map = build_map(begin);
	}
	return (map);
}
