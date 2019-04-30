/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 11:06:00 by siolive           #+#    #+#             */
/*   Updated: 2019/04/27 14:56:42 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list				*ft_getlist(t_list **file, int fd)
{
	t_list			*new;

	if (!file)
		return (NULL);
	new = *file;
	while (new != NULL)
	{
		if ((int)new->content_size == fd)
			return (new);
		new = new->next;
	}
	ft_lstadd(file, ft_lstnew("", fd));
	return (new);
}

int					ft_read(int fd, char **copy)
{
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	int				ret;

	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		temp = *copy;
		if (!(*copy = ft_strjoin(*copy, buffer)))
			return (-1);
		free(temp);
		if (ft_strchr(buffer, '\n') || ft_strchr(buffer, -1))
			break ;
	}
	return (ret);
}

int					ft_strccpy(char **line, char *text, char symb1, char symb2)
{
	int				i;
	int				j;
	char			*temp;
	char			*new;

	i = 0;
	j = 0;
	temp = *line;
	while (text[i] && text[i] != symb1 && text[i] != symb2)
		i++;
	if (!(new = ft_strnew(i)))
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
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	static t_list	*file;
	t_list			*node;
	char			*temp;

	if (!line || fd < 0 || fd > 10240 || BUFF_SIZE < 0 || read(fd, buffer, 0) < 0)
		return (-1);
	if ((node = ft_getlist(&file, fd)) == NULL)
		return (-1);
	temp = (char *)node->content;
	ret = ft_read(fd, &temp);
	node->content = temp;
	if (ret == 0 && *temp == 0)
		return (0);
	ret = ft_strccpy(line, (char *)node->content, '\n', -1);
	temp = (char *)node->content;
	if (temp[ret] == '\0')
		ft_strclr(node->content);
	else
		node->content = ft_strdup(&(node->content[ret + 1]));
	free(temp);
	return (1);
}
