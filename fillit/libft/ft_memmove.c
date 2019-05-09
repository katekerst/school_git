/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:10:12 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 15:31:56 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*new_dst;
	char		*new_src;
	size_t		i;

	i = 1;
	if (!dst && !src)
		return (NULL);
	new_dst = (char *)dst;
	new_src = (char *)src;
	if (dst > src)
	{
		while (i <= len)
		{
			new_dst[len - i] = new_src[len - i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			*(new_dst++) = *(new_src++);
	}
	return (dst);
}
