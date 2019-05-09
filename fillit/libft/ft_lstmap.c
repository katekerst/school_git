/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:27:34 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:30:04 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*new;
	t_list	*begin_new;

	if (lst && f)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
			return (NULL);
		new = f(lst);
		begin_new = new;
		current = lst;
		while (current->next)
		{
			current = current->next;
			new->next = f(current);
			if (new->next == NULL)
				return (NULL);
			new = new->next;
		}
		return (begin_new);
	}
	return (NULL);
}
