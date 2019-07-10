/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:05:02 by siolive           #+#    #+#             */
/*   Updated: 2019/07/10 12:18:00 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void		ft_round(char **string, long double n, int *i)
{
	char		*copy;
	int			j;

	j = 0;
	copy = *string;
	if ((int)n >= 5)
	{
		if (copy[*i - 1] == '9')
		{
			(*i)--;
			while (copy[*i] == '9')
			{
				(*i)--;
				j++;
			}
			copy[*i] += 1;
			(*i)++;
			while (j-- > 0)
				copy[(*i)++] = '0';
		}
		else
			copy[*i - 1] += 1;
	}
}

void		ft_right_part(char **string, long double n, int *i, int precision)
{
	int			j;
	int			temp;
	char		*copy;

	j = 0;
	n *= 10;
	copy = *string;
	copy[(*i)++] = '.';
	while (j++ < precision)
	{
		temp = (int)n;
		copy[*i] = temp + 48;
		n = (n - temp) * 10;
		(*i)++;
	}
	ft_round(&copy, n, i);
	copy[*i] = '\0';
}

void		ft_left_part(char **str, long double *n, int *i, long double decs)
{
	char		*copy;
	long double temp;

	copy = *str;
	while ((long long)decs != 0)
	{
		copy[(*i)++] = (char)((*n) / decs) + 48;
		temp = ((copy[*i - 1] - 48) * decs);
		*n -= temp;
		decs /= 10;
	}
}

long double	dec_count(long double n, int *i)
{
	long double decs;

	decs = 1;
	while ((int)n / 10 != 0)
	{
        decs *= 10;
		(*i)++;
		n /= 10;
	}

	return (decs);
}

char		*play_with_floats(va_list args, t_option *options)
{
	char		*string;
	int			i;
	int			sign;
	long double	decs;
	long double	n;

	n = check_options(args, options);
	i = 0;
	sign = 0;
	if (n < 0)
	{
		i++;
		sign = 1;
		n *= -1;
	}

	decs = dec_count(n, &i);

	string = (char *)ft_memalloc(i + options->a_dec + 1);
	i = 0;
	if (sign == 1)
		string[i++] = '-';

	ft_left_part(&string, &n, &i, decs);

	if (options->a_dec != 0)
		ft_right_part(&string, n, &i, options->a_dec);
	return (string);
}
