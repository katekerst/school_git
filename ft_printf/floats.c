/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:05:02 by siolive           #+#    #+#             */
/*   Updated: 2019/06/30 16:17:16 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char	*itoa_base(int value, int base);

void	ft_round(char **string, double n, int *i)
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
		temp = (int)n;
		copy[*i] = temp + 48;
		n = (n - temp) * 10;
		(*i)++;
	}
	ft_round(&copy, n, i);
	// j = 0;
	// // if ((int)n >= 5)
	// // {
	// // 	if (copy[*i - 1] == '9')
	// // 	{
	// // 		(*i)--;
	// // 		while (copy[*i] == '9')
	// // 		{
	// // 			(*i)--;
	// // 			j++;
	// // 		}
	// // 		copy[*i] += 1;
	// // 		(*i)++;
	// // 		while (j-- > 0)
	// // 			copy[(*i)++] = '0';
	// // 	}
	// // 	else
	// // 		copy[*i - 1] += 1;
	// // }
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

char		*ft_play_with_floats(double n, int precision)
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
		return (NULL);	
	i = 0;
	if (sign == 1)
		string[i++] = '-';
	ft_left_part(&string, &n, &i, decs);
	if (precision != 0)
		ft_right_part(&string, n, &i, precision);
	string[i] = '\0';
	return (string);
}

double	ft_pow(double n, int pow)
{
	if (pow)
		return (n * ft_pow(n, pow - 1));
	else
		return (1);
}

int	main (void)
{
	int		prec;
	int		width;
	char	*str;
	char	*string;
	char	*string2;
	char	*flag;
	double n = 2346.34633;
	long double n1 = 2346.34633;
	double result;

	int sign = *(uint64_t *)&n >> 63;
	int exponent = (*(uint64_t *)&n << 1 >> 53) - 1023;
	long mantissa = *(uint64_t *)&n << 12 >> 12;
	result = ft_pow(-1, sign) * (1 + mantissa/ft_pow(2, 52)) * ft_pow(2, exponent);
	str = ft_play_with_floats(result, 8);
	printf ("myprin is %s\n", str);
	printf ("result is %.8f\n", n);
	printf ("lonres is %.8Lf\n", n1);
	// if (flag == 'L')
	// 	new_arg = (long double)args;
	// ft_print_double(str, width);
	return (0);
}