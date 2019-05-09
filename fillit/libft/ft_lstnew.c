/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 10:50:39 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:15:59 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*copy;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	copy = (void *)content;
	if (copy == NULL)
	{
		new->content = NULL;
		content_size = 0;
	}
	else
	{
		new->content = (void *)malloc(sizeof(void) * content_size);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
