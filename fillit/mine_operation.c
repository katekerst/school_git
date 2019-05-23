/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mine_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:53:57 by gbellege          #+#    #+#             */
/*   Updated: 2019/05/16 11:51:35 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			**set_mine(short int *xy,
t_tetra *tetramino, char **map)
{
	short int	i;
	short int	xi;
	short int	yi;

	i = 0;
	while (i < 4)
	{
		xi = xy[0] + tetramino->x[i];
		yi = xy[1] + tetramino->y[i];
		i++;
		map[yi][xi] = tetramino->letter;
	}
	return (map);
}

static char			**mine_defuse(short int *xy,
t_tetra *tetramino, char **map)
{
	short int	i;
	short int	xi;
	short int	yi;

	i = 0;
	while (i < 4)
	{
		xi = xy[0] + tetramino->x[i];
		yi = xy[1] + tetramino->y[i];
		i++;
		map[yi][xi] = '.';
	}
	return (map);
}

static int			is_possible(short int *xy, char **map,
t_tetra *tetramino, t_map *map_option)
{
	short int	i;
	short int	xi;
	short int	yi;

	i = 0;
	while (i < 4)
	{
		xi = xy[0] + tetramino->x[i];
		yi = xy[1] + tetramino->y[i];
		i++;
		if (xi >= map_option->map_size || xi < 0 || yi >= map_option->map_size)
			return (0);
		if (map[yi][xi] != '.')
			return (0);
	}
	return (1);
}

char				**fillit(t_tetra *tetramino, t_map *map_op, char **map)
{
	char		**map_back_step;
	short int	xy[2];

	xy[1] = -1;
	while (++xy[1] < map_op->map_size)
	{
		xy[0] = -1;
		while (++xy[0] < map_op->map_size)
			if (is_possible(xy, map, tetramino, map_op))
			{
				map = set_mine(xy, tetramino, map);
				if (tetramino->next == NULL)
					return (map);
				else if ((map_back_step = fillit(tetramino->next, map_op, map)))
					return (map_back_step);
				else
					mine_defuse(xy, tetramino, map);
			}
	}
	return (0);
}
