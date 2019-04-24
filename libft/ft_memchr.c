/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:27:45 by siolive           #+#    #+#             */
/*   Updated: 2019/04/09 16:01:49 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;

	new_s = (unsigned char *)s;
	while (n > 0)
	{
		if (*new_s == (unsigned char)c)
			return ((void *)(new_s));
		n--;
		new_s++;
	}
	return (NULL);
}
