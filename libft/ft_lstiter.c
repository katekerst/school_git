/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:16:37 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:17:03 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *begin;

	if (lst && f)
	{
		begin = lst;
		while (lst)
		{
			f(lst);
			lst = lst->next;
		}
	}
}
