/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:02:40 by siolive           #+#    #+#             */
/*   Updated: 2019/07/02 12:57:24 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libprint.h"

char	*itoa_unsigned(unsigned long long value)
{
	char			*string;
	unsigned int	i;
	unsigned long long	tmp;

	i = 0;
	tmp = value;
	while (tmp > 0)
	{
		i++;
		tmp /= 10;
	}
    tmp = value;
	string = (char *)malloc(sizeof(char) * (i + 1));
	if (string == NULL)
	    return (NULL);
	string[i] = '\0';
	while (i--)
	{
		string[i] = (unsigned int)(tmp % 10) + 48;
		tmp /= 10;
	}
	return (string);
}

char	*ft_string(int sign, unsigned int i) // одна фукнция для обоих атоев
{
	char *string;

	string = (char *)malloc(sizeof(char) * (i + 1));
	if (string == NULL)
		return (NULL);
	string[i] = '\0';
	if (sign == -1)
		string[0] = '-';
	return (string);
}

unsigned int		ft_count_long(long long value, int base)
{
	int					i;
	unsigned long long	tmp;

	i = 0;
	if (value < 0 && base == 10)
		i++;
	tmp = (unsigned long long)value;
	if (base == 10 && value < 0)
	{
		value *= -1;
		tmp = (unsigned long long)value;
	}
	while (tmp > 0)
	{
		i++;
		tmp /= base;
	}
	return (i);
}

char	*itoa_base_long(long long value, int base)
{
	char			*string;
	int				sign;
	unsigned int	i;
	unsigned long long	tmp;

	sign = 0;
	i = ft_count_long(value, base);
	if (value < 0 && base == 10)
	{
		sign = -1;
		value *= -1;
		tmp = value;
	}
	else
		tmp = (unsigned long long)value;
	string = ft_string(sign, i);
	while (i-- + sign)
	{
		if (tmp % base < 10)
			string[i] = (unsigned int)(tmp % base) + '0';
		else
			string[i] = (unsigned int)(tmp % base) + 'a' - 10;
		tmp /= base;
	}
	return (string);
}



// int		main(void)
// {
// 	unsigned short int	i = 125;
// 	long				j;
// 	long long			k;
// 	unsigned long long 	l;
// 	char			*string;
// 	unsigned char		cha = 125;
// 	int				base;

// 	// i = -83;
// 	j = 1844674407370955161;
// 	k = 1844674407370955161;
// 	l = 1844674407370955161;
// 	base = 8;
// 	string = itoa_base_long(i, base);
// 	printf("itoa_b is %s\n", string);
// 	printf("printf is %hu\n", i);
// 	// string = itoa_base_long(j, base);
// 	// printf("itoa_b is %s\n", string);
// 	// printf("printf is %lo\n", j);
// 	// string = itoa_base_long(k, base);
// 	// printf("itoa_b is %s\n", string);
// 	// printf("printf is %llo\n", k);
// 	// string = itoa_base_long(l, base);
// 	// printf("itoa_b is %s\n", string);
// 	// printf("printf is %llu\n", l);
// 	return (0);
// }
