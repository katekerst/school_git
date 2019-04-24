/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:35:53 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:09:13 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
	{
		if (s1 == s2)
			return (1);
		else
			return (0);
	}
	while (s1[i] && s2[i] && s1[i] == s2[i] && n > 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		i--;
	if ((unsigned char)s1[i] - (unsigned char)s2[i])
		return (0);
	else
		return (1);
}
