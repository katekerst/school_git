/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:11:15 by siolive           #+#    #+#             */
/*   Updated: 2019/06/24 14:33:43 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

double	ft_calc_modulo(double nb, int *size)
{
	double	modulo;

	modulo = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		modulo *= 10;
	return (modulo);
}

void	ft_handle_integer(double *nb, char **str, int *i, double modulo)
{
	char *s;

	s = *str;
	while ((int)*nb != 0)
	{
		s[(*i)++] = (char)((*nb / modulo) + 48);
		*nb -= (int)(*nb / modulo) * modulo;
		modulo /= 10;
	}
}

void	ft_handle_decimals(char **str, int *i, double nb, int precision)
{
	int		j;
	int		tmp;
	char	*s;

	nb *= 10;
	j = 0;
	s = *str;
	s[(*i)++] = '.';
	while (j++ < precision)
	{
		if ((int)nb == 0)
		{
			s[(*i)++] = '0';
			continue ;
		}
		tmp = (int)nb;
		s[(*i)++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
}

int		ft_handle_inf(char **s)
{
	if (!(*s = malloc(sizeof(char) * 4)))
		return (0);
	*s = "inf";
	return (3);
}

int		ft_put_float_to_string(double nb, char **s, int precision)
{
	int		i;
	int		size;
	char	*str;
	int		neg;
	double	modulo;

	size = 1;
	neg = 0;
	if (nb < 0 && size++ && (neg = 1) == 1)
		nb = -nb;
	modulo = ft_calc_modulo(nb, &size);
	size += precision;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	if (neg)
		str[i++] = '-';
	ft_handle_integer(&nb, &str, &i, modulo);
	ft_handle_decimals(&str, &i, nb, precision);
	str[--i] = '\0';
	*s = str;
	return (size);
}

int main (void)
{
	int size;
	double a;
	unsigned char b;
	char *string;

	a = 31431.345;
	b = (unsigned char)a;
	size = ft_put_float_to_string(123453.9244, &string, 7);
	printf ("%s\n", string);
	printf("float is %u\n", b);
	return (0);
}