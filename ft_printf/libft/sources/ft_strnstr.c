/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:14:20 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/27 15:12:17 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *needle, size_t n)
{
	char	*temp;
	size_t	len;
	size_t	i;
	size_t	j;

	temp = (char *)dest;
	len = ft_strlen(needle);
	if (!(len))
		return (temp);
	i = 0;
	while (temp[i] && i < n)
	{
		j = 0;
		while (needle[j] && needle[j] == temp[i + j] && len <= n - i)
			j++;
		if (j == len)
			return (&temp[i]);
		i++;
	}
	return (NULL);
}
