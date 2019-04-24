/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:35:16 by siolive           #+#    #+#             */
/*   Updated: 2019/04/15 10:46:05 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*new_dst;
	unsigned char		*new_src;
	size_t				i;

	i = 0;
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	while (i < n)
	{
		new_dst[i] = new_src[i];
		if (new_src[i] == (unsigned char)c)
			return ((void *)(dst + (i + 1)));
		i++;
	}
	return (NULL);
}
