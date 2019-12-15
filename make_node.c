/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:58:39 by dapinto           #+#    #+#             */
/*   Updated: 2019/07/18 15:14:25 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	save_coord(t_tetri *node, int y, int x)
{
	static int	i = 0;
	static char	name = 'A';

	if (i > 3)
		i = 0;
	node->coor[i][0] = y;
	node->coor[i][1] = x;
	if (i == 0)
	{
		node->name = name;
		name++;
	}
	i++;
}

int		count_links(char *tet, int i)
{
	int x;
	int y;
	int adj[4];

	x = i % 5;
	y = i / 5;
	adj[0] = ((x + 1) < 4) ? (y * 5 + (x + 1)) : -1;
	adj[1] = ((x - 1) >= 0) ? (y * 5 + (x - 1)) : -1;
	adj[2] = ((y - 1) >= 0) ? ((y - 1) * 5 + x) : -1;
	adj[3] = ((y + 1) < 4) ? ((y + 1) * 5 + x) : -1;
	x = 0;
	y = 0;
	while (x < 4)
	{
		if (adj[x] >= 0 && tet[adj[x]] == '#')
			++y;
		++x;
	}
	return (y);
}

void	coord_relate(t_tetri *node)
{
	int min_y;
	int	min_x;
	int	j;

	min_y = 4;
	min_x = 4;
	j = 0;
	while (j < 4)
	{
		if (node->coor[j][0] < min_y)
			min_y = node->coor[j][0];
		if (node->coor[j][1] < min_x)
			min_x = node->coor[j][1];
		j++;
	}
	j = 0;
	while (j < 4)
	{
		node->coor[j][0] -= min_y;
		node->coor[j][1] -= min_x;
		j++;
	}
}

t_tetri	*make_node(char *tet)
{
	int		i;
	int		count;
	t_tetri	*node;

	i = 0;
	count = 0;
	if (!(node = (t_tetri*)ft_memalloc(sizeof(t_tetri))))
		return (NULL);
	while (tet[i])
	{
		if (tet[i] == '#')
		{
			save_coord(node, (i / 5), (i % 5));
			count += count_links(tet, i);
		}
		++i;
	}
	if ((count != 6 && count != 8) || node->name > 'Z')
	{
		free(tet);
		ft_memdel((void**)&node);
	}
	else
		coord_relate(node);
	return (node);
}
