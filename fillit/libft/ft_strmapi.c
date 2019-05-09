/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:19:10 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:19:47 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	length;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	length = (unsigned int)ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	while (i < length)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
