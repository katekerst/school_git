/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:23:16 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/26 12:12:59 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	static	*ft_lets_go(const char *str)
{
	while (*str != '\0' && (ft_isspace(*str)))
		str++;
	return (str);
}

int					ft_atoi(const char *str)
{
	short int				sgn;
	unsigned long int		out;

	sgn = 1;
	out = 0;
	str = ft_lets_go(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sgn = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		out *= 10;
		out += *str - '0';
		str++;
	}
	return (sgn * out);
}
