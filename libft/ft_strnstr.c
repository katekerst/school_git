/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:24:32 by siolive           #+#    #+#             */
/*   Updated: 2019/04/15 10:42:19 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*n;
	char	*h;
	char	*h_begin;

	if (*needle == 0)
		return ((char *)haystack);
	h_begin = (char *)haystack;
	while (*haystack && (size_t)(haystack - h_begin) < len)
	{
		h = (char *)haystack;
		if (*h == *needle)
		{
			n = (char *)needle;
			while (((size_t)(h - h_begin) < len) && *h == *n)
			{
				h++;
				n++;
				if (*n == 0)
					return ((char *)haystack);
			}
		}
		haystack++;
	}
	return (NULL);
}
