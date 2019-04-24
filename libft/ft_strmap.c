/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:55:15 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:19:41 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		length;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	length = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	while (i < length)
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
