/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:28:48 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/20 18:45:13 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

char				*play_with_h_flags(va_list args, t_option *opt, char *out)
{
	unsigned int	res;

	if (opt->m_ll == TRUE || opt->m_l == TRUE)
		out = itoa_base_long(va_arg(args, long long int), 16);
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
		out = ft_itoa_base(res, 16);
	}
	return (out);
}

void				play_with_hex(va_list args, t_option *opt)
{
	char			*temp;

	temp = NULL;
	temp = play_with_h_flags(args, opt, temp);
	tsr(opt->out, temp);
	ft_strdel(&temp);
	if (opt->out[0] == '0')
		opt->f_hash = 0;
	if (opt->a_have_dot && opt->a_dec == 0 && opt->out[0] == '0')
		ft_bzero((opt->out), OUT_SIZE);
	if (opt->a_have_dot && opt->a_dec > 0)
		tslaf(opt->out, msos((opt->a_dec - ft_strlen(opt->out)), '0'));
	if (opt->w_zero_dec && opt->f_hash)
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out) - 2), '0'));
	else if (opt->w_zero_dec)
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), '0'));
	if (opt->f_hash)
		tsl(opt->out, "0x");
	if (opt->f_minus)
		tsraf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), ' '));
	else if (!(opt->w_zero_dec) || (opt->a_have_dot))
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), ' '));
	opt->count += ft_strlen(opt->out);
	ft_putstr(opt->out);
}

void				play_with_hex_big(va_list args, t_option *opt)
{
	char			*temp;

	temp = NULL;
	temp = play_with_h_flags(args, opt, temp);
	tsr(opt->out, temp);
	ft_strdel(&temp);
	if (opt->out[0] == '0')
		opt->f_hash = 0;
	if (opt->a_have_dot && opt->a_dec == 0 && opt->out[0] == '0')
		ft_bzero((opt->out), OUT_SIZE);
	if (opt->a_have_dot && opt->a_dec > 0)
		tslaf(opt->out, msos((opt->a_dec - ft_strlen(opt->out)), '0'));
	if (opt->w_zero_dec && opt->f_hash)
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out) - 2), '0'));
	else if (opt->w_zero_dec)
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), '0'));
	if (opt->f_hash)
		tsl(opt->out, "0x");
	if (opt->f_minus)
		tsraf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), ' '));
	else if (!(opt->w_zero_dec) || (opt->a_have_dot))
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)), ' '));
	opt->count += ft_strlen(opt->out);
	ft_putstr(ft_str_toupper(opt->out));
}
