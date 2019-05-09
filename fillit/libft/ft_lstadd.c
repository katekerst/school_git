/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:03:07 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:16:47 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*begin;

	if (new)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			begin = *alst;
			new->next = begin;
			*alst = new;
		}
	}
}
