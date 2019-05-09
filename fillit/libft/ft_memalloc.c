/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:56:57 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:18:23 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_mem;

	new_mem = malloc(size);
	if (new_mem == NULL)
		return (NULL);
	ft_bzero(new_mem, size);
	return (new_mem);
}
