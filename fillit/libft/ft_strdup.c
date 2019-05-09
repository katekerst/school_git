/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:50:07 by siolive           #+#    #+#             */
/*   Updated: 2019/04/06 13:03:35 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		length;

	length = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
