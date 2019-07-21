/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_per_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:30:40 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/20 19:04:19 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	play_with_char(va_list args, t_option *opt)
{
	char	res;

	res = va_arg(args, int);
	if (res == 0)
	{
		if (opt->w_dec != 0)
			opt->count += opt->w_dec;
		else
			opt->count += 1;
		while (opt->w_dec-- > 1)
			ft_putchar(' ');
		ft_putchar(res);
		return ;
	}
	opt->out[0] = res;
	if (opt->f_minus)
		tsraf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	else
		tslaf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	opt->count += ft_strlen(opt->out);
	ft_putstr(opt->out);
}

void	play_with_promile(t_option *opt)
{
	tsr(opt->out, "%");
	if (opt->f_minus)
		tsraf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	else if (opt->w_zero_dec)
		tslaf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), '0'));
	else
		tslaf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	opt->count += ft_strlen(opt->out);
	ft_putstr(opt->out);
}
