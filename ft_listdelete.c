/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:41:38 by dapinto           #+#    #+#             */
/*   Updated: 2019/07/18 15:14:16 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_listdelete(t_tetri **node)
{
	t_tetri *ptr;

	if (*node)
	{
		while (*node)
		{
			ptr = *node;
			*node = (*node)->next;
			if (ptr != NULL)
				free(ptr);
		}
		*node = NULL;
	}
}
