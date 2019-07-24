/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:19:56 by siolive           #+#    #+#             */
/*   Updated: 2019/07/24 12:18:48 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"
#include <stdio.h>
#include <math.h>

long double		check_opt(va_list args, t_option *opt)
{
	long double n;
	int			a;

	if (!opt->a_have_dot && !opt->a_star)
		opt->a_dec = 6;
	if (opt->m_big_l == TRUE)
		n = va_arg(args, long double);
	else
		n = va_arg(args, double);
	return (n);
}

int				ft_check_double(long double n, char **string, t_option *opt)
{
	if (n == (1.0 / 0.0))
	{
		*string = "inf";
		opt->w_zero_dec = FALSE;
		opt->f_hash = FALSE;
		return (1);
	}
	if (n == (-1.0 / 0.0))
	{
		*string = "-inf";
		opt->w_zero_dec = FALSE;
		opt->f_hash = FALSE;
		return (1);
	}
	if (n != n)
	{
		*string = "nan";
		opt->w_zero_dec = FALSE;
		opt->f_plus = FALSE;
		opt->f_space = FALSE;
		return (1);
	}
	return (0);
}

long double		dec_count(long double n, int *i)
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

static void		play_with_floats_sec(t_option *opt,
	char **string, long double n, long double decs)
{
	int		i;

	i = 0;
	if (!(opt->is_positive))
		*string[i++] = '-';
	ft_left_part(string, &n, &i, decs);
	if (opt->a_dec != 0)
		ft_right_part(string, n, &i, opt->a_dec);
	else
		ft_round(string, (n * 10), &i);
	trans_float(*string, opt);
	ft_memdel((void **)string);
}

void			play_with_floats(va_list args, t_option *opt)
{
	char		*string;
	int			i;
	long double	decs;
	long double	n;

	n = check_opt(args, opt);
	if (ft_check_double(n, &string, opt))
	{
		trans_float(string, opt);
		return ;
	}
	i = 0;
	if (n < 0)
	{
		i++;
		opt->is_positive = FALSE;
		n *= -1;
	}
	decs = dec_count(n, &i);
	string = (char *)ft_memalloc(i + opt->a_dec + 2);
	play_with_floats_sec(opt, &string, n, decs);
}
