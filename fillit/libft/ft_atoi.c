/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 10:34:44 by siolive           #+#    #+#             */
/*   Updated: 2019/04/13 15:18:29 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (*str == ' ' || *str == '\r' || *str == '\f'
			|| *str == '\n' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = *str == '-' ? -1 : 1;
		str++;
	}
	while (str[i] != '\0')
	{
		if (str[i] > 57 || str[i] < 48)
			return (result * sign);
		result = result * 10 + (str[i++] - 48);
	}
	if (result > 9223372036854775807 || i > 19)
		return (sign == 1 ? -1 : 0);
	return (result * sign);
}
