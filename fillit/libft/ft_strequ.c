/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:31:04 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 13:08:23 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int result;

	if (!s1 || !s2)
	{
		if (s1 == s2)
			return (1);
		else
			return (0);
	}
	result = ft_strcmp(s1, s2);
	if (result == 0)
		return (1);
	else
		return (0);
}
