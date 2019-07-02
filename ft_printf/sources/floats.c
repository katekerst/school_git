/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:05:02 by siolive           #+#    #+#             */
/*   Updated: 2019/07/02 14:44:27 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	ft_round(char **string, long double n, int *i)
{
	char	*copy;
	int		j;

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

void	ft_right_part(char **string, long double n, int *i, int precision)
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
		temp = (int)n;
		copy[*i] = temp + 48;
		n = (n - temp) * 10;
		(*i)++;
	}
	ft_round(&copy, n, i);
}

void	ft_left_part(char **string, long double *n, int *i, long double decs)
{
	char *copy;
	long double temp;

	copy = *string;
	while ((long long)decs != 0)
	{
        copy[(*i)++] = (char)((*n)/decs) + 48;
		temp = ((copy[*i - 1] - 48) * decs);
		*n -= temp;
		decs /= 10;
	}
}

long double    dec_count(long double n, int *i)
{
	long double decs;

	decs = 1;
	while ((int)n/10 != 0)
	{
        decs *= 10;
		(*i)++;
		n /= 10;
	}
	return (decs);
}

char		*play_with_floats(va_list args, t_option *options)
{
	char	*string;
	int 	i;
	int 	sign;
	long double 	decs;
    long double n;

    if (!options->a_have_dot && !options->a_star)
        options->a_dec = 6;
    n = va_arg(args, long double);
	i = 0;
	sign = 0;
	if (n < 0)
	{
		i++;
		sign = 1;
		n *= -1;
	}
	decs = dec_count(n, &i);
	if ((string = (char *)malloc(sizeof(char) * (i + options->a_dec + 1))) == NULL)
		return (NULL);
	i = 0;
	if (sign == 1)
		string[i++] = '-';
	ft_left_part(&string, &n, &i, decs);
	if (options->a_dec != 0)
		ft_right_part(&string, n, &i, options->a_dec);
	string[i] = '\0';
	return (string);
}

void	ft_print_nan(void)
{
	ft_putstr("NaN");
}

void	ft_print_inf(void)
{
	ft_putstr("INF");
}

int		ft_check_double(long double n)
{
	double NAN = 0.0/0.0;
	double POS_INF = 1.0 /0.0;
	double NEG_INF = -1.0/0.0;

	if (n == NAN)
	{
		ft_print_nan();
		return (1);
	}
	if (n == POS_INF || n == NEG_INF)
	{
		ft_print_inf();
		return (1);
	}
	return (0);

}
