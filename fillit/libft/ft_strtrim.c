/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:51:51 by siolive           #+#    #+#             */
/*   Updated: 2019/04/15 14:58:37 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		l;
	char	*str;
	char	*copy;
	int		i;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	str = (char *)s;
	l = (int)ft_strlen(str);
	while (str[l - 1] == ' ' || str[l - 1] == '\n' || str[l - 1] == '\t')
		l--;
	if (l <= 0)
		l = 0;
	if (!(copy = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (i < l)
	{
		copy[i++] = *str;
		str++;
	}
	copy[i] = 0;
	return (copy);
}
