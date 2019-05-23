/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:36:46 by gbellege          #+#    #+#             */
/*   Updated: 2019/05/15 13:02:19 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				finish(void)
{
	ft_putendl("error");
	exit(0);
}

void				check_open(int fd)
{
	if (fd == -1)
		finish();
}

void				check_close(int fd)
{
	if (close(fd) == -1)
		finish();
}

t_map				*ft_create_map_option(t_tetra **tetramino)
{
	t_tetra			*current;
	t_map			*map;
	short	int		i;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	current = *tetramino;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	map->tetra_qt = i;
	return (map);
}

t_tetra				*ft_create_tetra(t_tetra *tetramino, char *buffer)
{
	int				j;
	int				k;
	int				count;
	int				i;

	count = 0;
	j = 1;
	i = 0;
	while (buffer[i] != '#' && buffer[i])
		i++;
	if (!buffer[i])
		finish();
	k = i;
	while (++i <= 18)
	{
		if (buffer[i] == '#')
		{
			tetramino->x[j] = i - count - k;
			tetramino->y[j++] = i / 5 - k / 5;
		}
		if (buffer[i] == '\n')
			count += 5;
	}
	tetramino->next = NULL;
	return (tetramino);
}
