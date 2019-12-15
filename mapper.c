/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:39:21 by dapinto           #+#    #+#             */
/*   Updated: 2019/07/18 15:14:30 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*map_set(int size)
{
	int		j;
	t_map	*map;

	j = 0;
	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->map = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (j < size)
	{
		if (!(map->map[j] = ft_strnew(size)))
		{
			ft_tabdel(j - 1, &map->map);
			return (NULL);
		}
		ft_memset(map->map[j], '.', size);
		j++;
	}
	map->map[j] = 0;
	map->size = size;
	return (map);
}
