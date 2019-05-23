/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:11:45 by siolive           #+#    #+#             */
/*   Updated: 2019/05/20 13:53:10 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		*ft_newfigure(t_tetra **figure, t_tetra *tetramino)
{
	t_tetra				*current;

	if (*figure == NULL)
	{
		*figure = (t_tetra*)malloc(sizeof(t_tetra));
		ft_memcpy(*figure, tetramino, sizeof(t_tetra));
	}
	else
	{
		current = *figure;
		while (current->next)
			current = current->next;
		current->next = (t_tetra*)malloc(sizeof(t_tetra));
		current = current->next;
		ft_memcpy(current, tetramino, sizeof(t_tetra));
		current->next = NULL;
	}
	return (*figure);
}

t_tetra		*ft_newtetra(char *buf, char let, t_tetra *tetramino)
{
	tetramino = (t_tetra *)malloc(sizeof(t_tetra));
	tetramino->letter = let;
	tetramino->num = (let - 65);
	tetramino->x[0] = 0;
	tetramino->y[0] = 0;
	tetramino = ft_create_tetra(tetramino, buf);
	return (tetramino);
}

int			ft_check_figure(char *buffer)
{
	int					i;
	int					count;

	i = 0;
	count = 0;
	while (i <= 19)
	{
		if (buffer[i] == '#')
		{
			if (buffer[i + 1] == '#' && (i + 1) <= 19)
				count++;
			if (buffer[i - 1] == '#' && (i - 1) >= 0)
				count++;
			if (buffer[i + 5] == '#' && (i + 5) <= 19)
				count++;
			if (buffer[i - 5] == '#' && (i - 5) >= 0)
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	finish();
	return (0);
}

int			ft_check_block(char *buffer, int ret)
{
	int					i;
	int					count;

	i = 0;
	count = 0;
	while (i <= 19 && buffer[i])
	{
		if ((buffer[i] == '#' || buffer[i] == '.') && i % 5 < 4)
		{
			if (buffer[i] == '#')
				count++;
			if (count > 4)
				finish();
			i++;
		}
		else if (buffer[i] == '\n')
			i++;
		else
			finish();
	}
	if ((ret > 20 && buffer[i] != '\n') || ret < 20)
		finish();
	if (!(ft_check_figure(buffer)))
		finish();
	return (1);
}

t_tetra		*ft_read_tetraminos(int fd, t_tetra *tetramino)
{
	static t_tetra		*figures;
	int					ret;
	char				letter;
	char				buffer[21];
	int					i;

	letter = 'A';
	figures = NULL;
	while ((ret = (read(fd, buffer, 21))) >= 20 && letter <= 'Z')
	{
		i = ret;
		if ((ft_check_block(buffer, ret)) &&
		(tetramino = ft_newtetra(buffer, letter, tetramino)))
		{
			figures = ft_newfigure(&figures, tetramino);
			free(tetramino);
		}
		else
			ft_free_tetraminos(figures);
		letter++;
	}
	if (figures == NULL || ret != 0 || i != 20 || letter > 'Z')
		finish();
	return (figures);
}
