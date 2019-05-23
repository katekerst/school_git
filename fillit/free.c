/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:53:56 by siolive           #+#    #+#             */
/*   Updated: 2019/05/16 13:00:25 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_free_tetraminos_fin(t_tetra *tetraminos)
{
	t_tetra		*current;

	while (tetraminos)
	{
		current = tetraminos->next;
		ft_memdel((void **)&tetraminos);
		tetraminos = current;
	}
}

void				ft_free_tetraminos(t_tetra *tetraminos)
{
	t_tetra		*current;

	while (tetraminos)
	{
		current = tetraminos->next;
		ft_memdel((void **)&tetraminos);
		tetraminos = current;
	}
	finish();
}

void				ft_freearray(char **array)
{
	int			i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
