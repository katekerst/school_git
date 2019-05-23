/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 13:30:45 by gbellege          #+#    #+#             */
/*   Updated: 2019/05/13 15:06:34 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

t_file		*new_file(int fd)
{
	t_file	*new;

	if ((new = (t_file *)ft_memalloc(sizeof(t_file))))
	{
		new->fd = fd;
		new->next = NULL;
		new->str = (char *)ft_memalloc(1 * sizeof(char));
	}
	return (new);
}

t_file		*look_file(int fd, t_file **top_f)
{
	t_file	*f;

	if (!(*top_f))
		return (*top_f = new_file(fd));
	f = *top_f;
	while (f->next && f->fd != fd)
	{
		f = f->next;
	}
	return ((f->fd == fd) ? f : (f->next = new_file(fd)));
}

int			out(char **str, char **line)
{
	char *new;
	char *difptr;

	if (!(*line = ft_strsubchr(*str, '\n')))
		return (-1);
	difptr = ft_strchrs(*str, '\n');
	difptr++;
	if (!ft_strlen(difptr))
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	new = ft_strdup(difptr);
	free(*str);
	*str = new;
	return ((new) ? 1 : -1);
}

int			get_next_line_ftn(const int fd, char **line, t_file *f, char *buf)
{
	int		size;
	char	*temp;

	while (!(ft_strchr(f->str, '\n')))
	{
		size = read(fd, buf, BUFF_SIZE);
		if (!(size))
		{
			*line = f->str;
			if (!(*line))
				return (0);
			f->str = NULL;
			return (1);
		}
		buf[size] = '\0';
		temp = f->str;
		f->str = ft_strjoin(f->str, buf);
		free(temp);
		if (!f->str)
			return (-1);
	}
	return (out(&(f->str), line));
}

int			get_next_line(const int fd, char **line)
{
	static t_file	*top_f = NULL;
	char			buf[BUFF_SIZE + 1];
	t_file			*f;

	if (!(f = look_file(fd, &top_f)) || (fd < 0)
			|| !line || read(fd, buf, 0) < 0)
		return (-1);
	return (get_next_line_ftn(fd, line, f, buf));
}
