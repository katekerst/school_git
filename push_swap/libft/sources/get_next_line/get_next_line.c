/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 11:06:00 by siolive           #+#    #+#             */
/*   Updated: 2019/04/30 10:56:19 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list				*ft_getlist(t_list **file, int fd)
{
	t_list			*new;

	if (!file)
		return (NULL);
	new = *file;
	while (new)
	{
		if ((int)new->content_size == fd)
			return (new);
		new = new->next;
	}
	ft_lstadd(file, new = ft_lstnew("", fd));
	return (new);
}

int					ft_read(int fd, char **copy)
{
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	char			*temp;

	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		temp = *copy;
		if (!(*copy = ft_strjoin(temp, buffer)))
			return (-1);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ret);
}

int					ft_strccpy(char **line, char *text, char symb)
{
	int				i;
	int				j;
	char			*temp;
	char			*new;

	i = 0;
	j = 0;
	temp = *line;
	while (text[i] && text[i] != symb)
		i++;
	new = ft_strnew(i);
	if (!new)
		return (0);
	while (text[j] && j < i)
	{
		new[j] = text[j];
		j++;
	}
	*line = new;
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*file;
	t_list			*node;
	char			*temp;

	if (!line || fd < 0 || fd > 10240 ||
			read(fd, buf, 0) < 0 || !(node = ft_getlist(&file, fd)))
		return (-1);
	temp = (char *)node->content;
	if ((ret = ft_read(fd, &temp) == -1))
		return (-1);
	node->content = temp;
	if (!ret && !*temp)
		return (0);
	ret = ft_strccpy(line, (char *)node->content, '\n');
	temp = (char *)node->content;
	if (!temp[ret])
		ft_strclr(node->content);
	else
		node->content = ft_strdup(&temp[ret + 1]);
	free(temp);
	return (1);
}
