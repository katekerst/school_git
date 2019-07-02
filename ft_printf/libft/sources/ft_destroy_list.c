/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:09:35 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/27 15:38:10 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_destroy_list(t_list **alst)
{
	if ((*alst)->next)
		ft_destroy_list(&(*alst)->next);
	free(*alst);
	*alst = NULL;
}
