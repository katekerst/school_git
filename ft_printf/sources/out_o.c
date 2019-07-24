/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:27:13 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/22 14:06:50 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

char				*play_with_o_flags(va_list args, t_option *opt, char *out)
{
	unsigned int	res;

	if (opt->m_ll == TRUE || opt->m_l == TRUE)
		out = itoa_base_long(va_arg(args, long long int), 8);
	else
	{
		res = va_arg(args, unsigned int);
		if (opt->m_hh == TRUE || opt->m_h == TRUE)
		{
			if (opt->m_h == TRUE)
				res = (unsigned short)res;
			else
				res = (unsigned char)res;
		}
		out = ft_itoa_base(res, 8);
	}
	return (out);
}

void				play_with_oct(va_list args, t_option *opt)
{
	char			*temp;

	temp = NULL;
	tsraf(opt->out, play_with_o_flags(args, opt, temp));
	if (opt->out[0] == '0')
		opt->is_positive = FALSE;
	if (!(opt->is_positive) && opt->a_have_dot
			&& opt->a_dec == 0 && !(opt->f_hash))
		ft_bzero((opt->out), OUT_SIZE);
	if (opt->a_have_dot && opt->a_dec > 0)
	{
		tslaf(opt->out, msos((opt->a_dec - ft_strlen(opt->out)), '0'));
	}
	if (opt->f_hash && opt->is_positive && (ft_strlen(opt->out) > opt->a_dec))
		tsl(opt->out, "0");
	if (opt->f_minus)
		tsraf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), ' '));
	else if (opt->w_zero_dec && !(opt->a_have_dot))
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), '0'));
	else
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), ' '));
	opt->count += ft_strlen(opt->out);
	ft_putstr(opt->out);
}
