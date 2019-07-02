/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:18:24 by siolive           #+#    #+#             */
/*   Updated: 2019/07/02 12:11:07 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libprint.h"

unsigned int		ft_count(int value, int base)
{
	int				i;
	unsigned int	tmp;

	i = 0;
	if (value < 0 && base == 10)
		i++;
	tmp = (unsigned int)value;
	if (base == 10 && value < 0)
	{
		value *= -1;
		tmp = value;
	}
	while (tmp > 0)
	{
		i++;
		tmp /= base;
	}
	return (i);
}

char	*itoa_base(int value, int base)
{
	char			*string;
	int				sign;
	unsigned int	i;
	unsigned int	tmp;

	sign = 0;
	i = ft_count(value, base);
	if (value < 0 && base == 10)
	{
		sign = -1;
		value *= -1;
		tmp = value;
	}
	else
		tmp = (unsigned int)value;
	string = ft_string(sign, i);
	while (i-- + sign)
	{
		if (tmp % base < 10)
			string[i] = tmp % base + '0';
		else
			string[i] = tmp % base + 'a' - 10;
		tmp /= base;
	}
	return (string);
}

// int		main(void)
// {
// 	int				i;
// 	char			*string;
// 	int				base;

// 	i = 812323;
// 	base = 8;
// 	string = itoa_base(i, base);
// 	printf("itoa_base is %s\n", string);
// 	printf("printf is %o\n", i);
// 	return (0);
// }