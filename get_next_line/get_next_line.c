/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 11:06:00 by siolive           #+#    #+#             */
/*   Updated: 2019/04/24 11:51:27 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*ft_getlist(t_list **file, int fd)
{
	t_list			*temp;

	temp = *file;
	while (temp != NULL)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("", fd);
	ft_lstadd(file, temp);
	return (temp);
}

size_t				ft_strccpy(char **line, char *text, char symbol)
{
	size_t			i;
	size_t			j;
	char			*temp;

	i = 0;
	j = 0;
	temp = *line;
	while (text[i] && text[i] != symbol)
		i++;
	if(!(*line = ft_strnew(i)))
		return (0);
	while (text[j] && j < i)
	{
		*line[j] = text[j];
		j++;
	}
	return (i);
}

size_t				ft_read(int	fd, char **copy)
{
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	size_t			ret;

	while ((ret = read(fd, buffer, BUFF_SIZE) > 0))
	{
		buffer[ret] = '\0';
		temp = *copy;
		if (!(*copy = ft_strjoin(*copy, buffer)))
			return (-1);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	size_t			ret;
	char			*copy;
	static t_list	*file;
	t_list			*node;

	if (!line || fd < 0 || BUFF_SIZE < 0 || read(fd, buffer, 0) < 0)
		return (-1);
	if (!(node = ft_getlist(&file, fd)))
		return (-1);
	copy = node->content;
	ret = ft_read(fd, &copy);
	node->content = copy;
	if (ret == 0 && !*copy)
		return (0);
	ret = ft_strccpy(line, node->content, '\n');
	copy = node->content;
	if (copy[ret])
	{
		node->content = ft_strdup(&((node->content)[ret + 1]));
		free(copy);
	}
	else
		ft_strclr(node->content);
	return (1);
}
