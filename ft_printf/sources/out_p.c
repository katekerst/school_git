/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:31:52 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/21 13:30:38 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	play_with_pointer(va_list args, t_option *opt)
{
	long int	*res;
	long int	j;
	char		*r;

	res = va_arg(args, long int*);
	j = (long int)res;
	r = ft_itoa_base(j, 16);
	tsr(opt->out, r);
	ft_strdel(&r);
	if (opt->a_have_dot && opt->a_dec > 0)
		tslaf(opt->out, msos((opt->a_dec - ft_strlen(opt->out)), '0'));
	if (j == 0 && opt->a_have_dot && opt->a_dec == 0)
	{
		ft_bzero((opt->out), OUT_SIZE);
		tsr(opt->out, "0x");
	}
	else
		tsl(opt->out, "0x");
	if (opt->f_minus)
		tsraf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	else
		tslaf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	opt->count += ft_strlen(opt->out);
	ft_putstr(opt->out);
}
