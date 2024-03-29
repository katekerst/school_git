/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:13:24 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/24 12:18:50 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"
#include <stdio.h>

void	trans_float(char *outp, t_option *opt)
{
	tsr(opt->out, outp);
	if (opt->f_plus)
		if (opt->out[0] != '-')
			tsl(opt->out, "+");
	if (opt->f_space)
		if (opt->out[0] != '-')
			tsl(opt->out, " ");
	if (opt->f_hash && opt->a_dec == 0)
		tsr(opt->out, ".");
	if (opt->f_minus)
		tsraf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	else if (opt->w_zero_dec)
		tslaf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), '0'));
	else
		tslaf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	opt->count += ft_strlen(opt->out);
	ft_putstr(opt->out);
}
