/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:44:06 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:16:34 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	if (*alst && del)
	{
		current = *alst;
		while (current)
		{
			next = current->next;
			del(current->content, current->content_size);
			free(current);
			current = next;
		}
		*alst = NULL;
	}
}
