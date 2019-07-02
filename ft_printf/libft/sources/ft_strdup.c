/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:08:09 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/25 12:39:57 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*temp;

	if ((temp = ft_strnew(ft_strlen(src))))
	{
		i = 0;
		while (src[i])
		{
			temp[i] = src[i];
			i++;
		}
		temp[i] = '\0';
	}
	return (temp);
}
