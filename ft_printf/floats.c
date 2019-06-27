/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:05:02 by siolive           #+#    #+#             */
/*   Updated: 2019/06/27 16:10:15 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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
	else 
		string[i] = '\0';
	return (string);
}

// double	ft_get_float(va_list args)
// {
// 	double	res;

// 	res = va_arg(args, double);
// 	return (res);
// }

char		*ft_inttobin(long mantissa)
{
	char	*mant;
	char	*reverse;
	int		i;
	int		k;

	if (!(mant = (char *)malloc(sizeof(char) * (53))))
		return (NULL);
	mant[52] = '\0';
	i = 51;
	while (i >= 0)
	{
		mant[i] = (mantissa % 2) + '0';
		mantissa /= 2;
		i--;
	}
	printf ("mantissa array is %s\n", mant);

	return (mant);
}

char		*ft_inttobin2(int exponent)
{
	char	*expon;
	int		i;

	if (!(expon = (char *)malloc(sizeof(char) * (33))))
		return (NULL);
	expon[32] = '\0';
	i = 0;
	while (i <= 31)
	{
		expon[i] = (exponent % 2) + '0';
		exponent /= 2;
		i++;
	}
	printf ("exponent array is %s\n", expon);
	return (expon);
}

// double power(double a, int b)
// {
// 	if (b > 0) 
// 		return (a*power(a, b-1));
// 	else 	
// 		return (1);
// }

double	ft_double_recovery(char *mantissa, int exponent)
{
	double result;
	int 		i;

	result = 0;
	i = 52;
	while (i >= 0)
	{
		result += ((mantissa[i] - 48) * pow(2, exponent));
		exponent--;
		i--;
	}
	return (result);
}


int	main (void)
{
	int		prec;
	int		width;
	char	*str;
	char	*string;
	char	*string2;
	char	*flag;
	double n = 2346.3463342342;
	long double result;
	int i;
	i = 0;

	int sign = *(uint64_t *)&n >> 63;
	int exponent = (*(uint64_t *)&n << 1 >> 53) - 1023;
	long mantissa = *(uint64_t *)&n << 12 >> 12;
	result = pow(-1, sign) * (1 + mantissa/pow(2, 52)) * pow(2, exponent);
	// flag = ft_check_flag(string);
	// prec = ft_check_precision(string);
	// width = ft_check_width(string);
	printf ("mantissa is %ld\n", mantissa);
	printf ("exponent is %d\n", exponent);
	string = ft_inttobin(mantissa);
	string2 = ft_inttobin2(exponent);
	printf ("printf is %f\n", n);
	result = ft_double_recovery(string, exponent);
	str = ft_play_with_floats(result, 6);
	printf ("myprin is %s\n", str);
	// if (flag == 'L')
	// 	new_arg = (long double)args;
	// ft_print_double(str, width);
	return (0);
}