/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:50:34 by siolive           #+#    #+#             */
/*   Updated: 2019/04/09 16:06:24 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while (i < (n - 1) && new_s1[i] == new_s2[i])
		i++;
	return ((int)(new_s1[i] - new_s2[i]));
}
