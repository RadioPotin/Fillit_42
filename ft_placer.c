/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:25:15 by dapinto           #+#    #+#             */
/*   Updated: 2019/07/18 15:14:20 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_placer(char **map, t_tetri *node, int y, int x)
{
	int j;

	j = 0;
	while (j < 4)
	{
		map[y + node->coor[j][0]][x + node->coor[j][1]] = node->name;
		j++;
	}
	return (1);
}
