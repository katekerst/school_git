/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:30:57 by siolive           #+#    #+#             */
/*   Updated: 2019/04/15 12:08:52 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *dst2;

	dst2 = dst;
	while (*src != '\0' && len > 0)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	while (len > 0)
	{
		*dst = '\0';
		dst++;
		len--;
	}
	return (dst2);
}
