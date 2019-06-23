/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:05:02 by siolive           #+#    #+#             */
/*   Updated: 2019/06/23 14:54:40 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*itoa_base(int value, int base);

void	ft_right_part(char **string, double n, int *i, int precision)
{
	int		j;
	int		temp;
	char	*copy;

	j = 0;
	n *= 10;
	copy = *string;
	copy[(*i)++] = '.';
	while (j++ < precision)
	{
		if ((int)n == 0)
		{
			copy[(*i)++] = '0';
			continue ;
		}
		temp = (int)n;
		copy[*i] = temp + 48;
		n = (n - temp) * 10;
		(*i)++;
	}
}

void	ft_left_part(char **string, double *n, int *i, double decs)
{
	char *copy;
	int temp;

	copy = *string;
	while ((int)(*n) != 0)
	{
		copy[(*i)++] = (char)((*n)/decs) + 48;
		temp = (int)(*n / decs) * decs;
		*n -= temp;
		decs /= 10;
	}
}

double		dec_count(double n, int *i)
{
	double decs;

	decs = 1;
	while ((int)(n/10) != 0)
	{
		decs *= 10;
		(*i)++;
		n /= 10;
	}
	return (decs);
}

void	ft_play_with_floats(double n, int precision)
{
	int		tmp;
	char	*string;
	int 	i;
	int 	sign;
	double	decs;
	
	i = 0;
	sign = 0;
	if (n < 0)
	{
		i++;
		sign = 1;
		n *= -1;
	}
	decs = dec_count(n, &i);
	if ((string = (char *)malloc(sizeof(char) * (i + precision + 1))) == NULL)
		return ;
	i = 0;
	if (sign == 1)
		string[i++] = '-';
	ft_left_part(&string, &n, &i, decs);
	ft_right_part(&string, n, &i, precision);
	printf ("string is %s\n", string);
}

int main (void)
{
	ft_play_with_floats(-123453.9244, 6);
	return (0);
}