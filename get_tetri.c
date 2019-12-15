/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:00:29 by dapinto           #+#    #+#             */
/*   Updated: 2019/07/18 15:14:21 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_line(char *tet)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (tet[i])
	{
		if (tet[i] == '#')
			++count;
		else if (tet[i] != '.' && tet[i] != '\n')
			return (0);
		if (i % 5 == 4 || i == 20)
			if (tet[i] != '\n')
				return (0);
		++i;
	}
	if (count != 4)
		return (0);
	return (1);
}

int		tet_lstadd(t_tetri **tet_lst, t_tetri **node, char *tet)
{
	t_tetri *prev;

	prev = *node;
	if (!(*node = make_node(tet)))
		return (0);
	if (*tet_lst == NULL)
		*tet_lst = *node;
	else
		prev->next = *node;
	(*node)->next = NULL;
	return (1);
}

int		get_tetri(int fd, t_tetri **tet_lst)
{
	int		ret;
	int		pre_ret;
	char	*tet;
	t_tetri	*current;

	current = NULL;
	if (!(tet = ft_strnew(22)))
		return (-1);
	while ((ret = read(fd, tet, 21)) > 0)
	{
		tet[ret] = '\0';
		pre_ret = ret;
		if (ret < 20 || check_line(tet) == 0)
		{
			free(tet);
			return (-1);
		}
		if (!(tet_lstadd(tet_lst, &current, tet)))
			return (-1);
	}
	free(tet);
	if (pre_ret == 21 && ret == 0)
		return (-1);
	return (ret);
}
