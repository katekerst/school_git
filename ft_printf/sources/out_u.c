/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:28:13 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/20 18:45:26 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"
#include <stdio.h>

char	*play_with_u_flags(va_list args, t_option *opt)
{
	unsigned long long	res;
	char				*out;

	if (opt->m_ll == TRUE || opt->m_l == TRUE)
	{
		res = va_arg(args, unsigned long long);
		out = itoa_unsigned(res);
	}
	else
	{
		res = va_arg(args, unsigned int);
		if (opt->m_hh == TRUE || opt->m_h == TRUE)
		{
			if (opt->m_h == TRUE)
				res = (unsigned short)res;
			else
				res = (unsigned short)((unsigned char)res);
		}
		out = ft_itoa_base(res, 10);
	}
	return (out);
}

void	play_with_unsigned_int(va_list args, t_option *opt)
{
	char					*temp;

	temp = play_with_u_flags(args, opt);
	tsr(opt->out, temp);
	ft_strdel(&temp);
	if (opt->a_have_dot && opt->a_dec == 0 && opt->out[0] == '0')
		ft_bzero((opt->out), OUT_SIZE);
	if (opt->a_have_dot && opt->a_dec > 0)
		tslaf(opt->out, msos((opt->a_dec - ft_strlen(opt->out)), '0'));
	if (opt->w_zero_dec && !(opt->a_have_dot) && (opt->f_plus || opt->f_space))
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), '0'));
	else if (opt->w_zero_dec && !(opt->a_have_dot))
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), '0'));
	if (opt->f_minus)
		tsraf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), ' '));
	else if (!opt->w_zero_dec || (opt->a_have_dot))
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), ' '));
	opt->count += ft_strlen(opt->out);
	ft_putstr(opt->out);
}
