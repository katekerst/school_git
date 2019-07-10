/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:19:56 by siolive           #+#    #+#             */
/*   Updated: 2019/07/10 11:34:24 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

long double	check_options(va_list args, t_option *options)
{
	long double n;

	if (!options->a_have_dot && !options->a_star)
		options->a_dec = 6;
	if (options->m_L == TRUE)
		n = va_arg(args, long double);
	else
		n = va_arg(args, double);
	return (n);
}

void		ft_print_nan(void)
{
	ft_putstr("NaN");
}

void		ft_print_inf(void)
{
	ft_putstr("INF");
}

int			ft_check_double(long double n)
{
	double nan;
	double pos_inf;
	double neg_inf;

	nan = 0.0 / 0.0;
	pos_inf = 1.0 / 0.0;
	neg_inf = -1.0 / 0.0;
	if (n == nan)
	{
		ft_print_nan();
		return (1);
	}
	if (n == pos_inf || n == neg_inf)
	{
		ft_print_inf();
		return (1);
	}
	return (0);
}
