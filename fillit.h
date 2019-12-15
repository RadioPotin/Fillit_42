/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:20:49 by evogel            #+#    #+#             */
/*   Updated: 2019/07/18 15:14:13 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_tetri
{
	char			name;
	int				coor[4][2];
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	int				size;
	char			**map;
}					t_map;

int					check_arg(int ac);
t_map				*map_set(int size);
int					error(t_tetri **lst);
int					check_line(char *tet);
t_tetri				*make_node(char *tet);
t_map				*build_map(t_tetri *begin);
void				coord_relate(t_tetri *node);
void				ft_listdelete(t_tetri **node);
int					ft_listlen_tet(t_tetri *head);
int					count_links(char *tet, int i);
int					get_tetri(int fd, t_tetri **tet_lst);
int					map_fill(t_tetri *current, t_map *map);
void				save_coor(t_tetri *node, int x, int y);
int					ft_placer(char **map, t_tetri *node, int y, int x);
void				ft_eraser(char **map, t_tetri *node, int y, int x);
int					check_relative(t_map *map, t_tetri *node, int y, int x);
int					tet_lstadd(t_tetri **tet_lst, t_tetri **node, char *tet);

#endif
