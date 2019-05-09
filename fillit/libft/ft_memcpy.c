/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:20:46 by siolive           #+#    #+#             */
/*   Updated: 2019/04/15 10:45:21 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*new_dst;
	const char	*new_src;

	if (!dst && !src)
		return (NULL);
	new_dst = (char *)dst;
	new_src = (char *)src;
	while (n > 0)
	{
		*new_dst = *new_src;
		new_dst++;
		new_src++;
		n--;
	}
	return (dst);
}
