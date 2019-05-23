/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:58:59 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/25 12:43:27 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dest, const char *needle)
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
	while (temp[i])
	{
		j = 0;
		while (needle[j] && needle[j] == temp[i + j])
			j++;
		if (j == len)
			return (&temp[i]);
		i++;
	}
	return (NULL);
}
