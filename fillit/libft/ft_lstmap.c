/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:36:12 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/28 13:26:18 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*temp;

	new_lst = NULL;
	if (lst && (*f))
	{
		temp = lst;
		new_lst = ft_lstnew(temp->content, temp->content_size);
		if (!(new_lst))
		{
			ft_destroy_list(&new_lst);
			return (NULL);
		}
		new_lst = f(new_lst);
		if (temp->next)
			new_lst->next = ft_lstmap(temp->next, f);
	}
	else
		return (NULL);
	return (new_lst);
}
