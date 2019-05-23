/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:08:47 by gbellege          #+#    #+#             */
/*   Updated: 2019/05/16 13:09:50 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**draw_map(char **map, short int size)
{
	short int	y;
	short int	x;

	y = -1;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	while (++y < size)
	{
		x = -1;
		map[y] = (char *)malloc(sizeof(char) * (size + 1));
		while (++x < size)
			map[y][x] = '.';
		map[y][x] = '\0';
	}
	map[y] = NULL;
	return (map);
}

short int		set_min_size(short int tetra_qt)
{
	short int	size;

	size = 2;
	while (size * size < tetra_qt * 4)
		size++;
	return (size);
}

void			get_solution(t_tetra *tetramino, t_map *map_op)
{
	int			i;
	char		**map;

	map = NULL;
	map_op->map_size = set_min_size(map_op->tetra_qt);
	map = draw_map(map, map_op->map_size);
	while (!fillit(tetramino, map_op, map))
	{
		ft_freearray(map);
		(map_op->map_size)++;
		map = draw_map(map, map_op->map_size);
	}
	i = -1;
	while (++i < map_op->map_size)
		ft_putendl(map[i]);
	ft_freearray(map);
	ft_free_tetraminos_fin(tetramino);
	ft_memdel((void **)&map_op);
}
