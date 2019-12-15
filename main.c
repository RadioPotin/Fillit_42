/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:51:48 by evogel            #+#    #+#             */
/*   Updated: 2018/12/07 13:56:07 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		error(t_tetri **lst)
{
	ft_listdelete(lst);
	ft_putendl("error");
	return (0);
}

int		check_arg(int ac)
{
	if (ac < 2)
	{
		ft_putendl("usage:\t./fillit [source_file]");
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	t_tetri	*tet_lst;
	t_map	*map;

	if (!(check_arg(ac)))
		return (0);
	tet_lst = NULL;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (error(&tet_lst));
	if ((ret = get_tetri(fd, &tet_lst)) == -1)
		return (error(&tet_lst));
	if (ret == 0 && tet_lst == NULL)
		return (error(&tet_lst));
	if (!(map = build_map(tet_lst)))
		return (error(&tet_lst));
	ft_puttab(map->map);
	ft_tabdel(map->size - 1, &map->map);
	free(map);
	ft_listdelete(&tet_lst);
	return (0);
}
