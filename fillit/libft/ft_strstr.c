/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:43:58 by siolive           #+#    #+#             */
/*   Updated: 2019/04/09 16:36:17 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;

	if (needle[0] == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		h = (char *)haystack;
		if (*h == *needle)
		{
			n = (char *)needle;
			while (*h == *n)
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
