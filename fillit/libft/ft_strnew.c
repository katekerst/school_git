/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:08:16 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:31:05 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (size > 65534)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (new_str == NULL)
		return (NULL);
	while (i <= size)
	{
		new_str[i] = '\0';
		i++;
	}
	return (new_str);
}
