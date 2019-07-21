/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_d_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:26:25 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/20 19:04:06 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"
#include <stdio.h>

char			*play_with_d_flags(va_list args, t_option *opt, char *out)
{
	int			res;

	if (opt->m_ll == TRUE || opt->m_l == TRUE)
		out = itoa_base_long(va_arg(args, long long int), 10);
	else
	{
		res = va_arg(args, int);
		if (opt->m_hh == TRUE || opt->m_h == TRUE)
		{
			if (opt->m_h == TRUE)
				res = (short)res;
			else
				res = (short)((signed char)res);
		}
		out = ft_itoa(res);
	}
	return (out);
}

char			*msos(int len, char sym)
{
	char		*str;
	int			i;

	if (len <= 0)
		return (NULL);
	str = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		str[i] = sym;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void			play_with_decemal_ftn(t_option *opt)
{
	if (opt->f_plus)
		if (opt->is_positive)
			tsl(opt->out, "+");
		else
			tsl(opt->out, "-");
	else if (opt->f_space)
		if (opt->is_positive)
			tsl(opt->out, " ");
		else
			tsl(opt->out, "-");
	else if (!(opt->is_positive))
		tsl(opt->out, "-");
	if (opt->f_minus)
		tsraf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	else if (!opt->w_zero_dec || (opt->a_have_dot))
		tslaf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	opt->count += ft_strlen(opt->out);
	ft_putstr(opt->out);
}

void			play_with_decemal(va_list args, t_option *opt)
{
	char		*temp;

	temp = NULL;
	temp = play_with_d_flags(args, opt, temp);
	tsr(opt->out, temp);
	ft_strdel(&temp);
	if (opt->a_have_dot && opt->a_dec == 0 && opt->out[0] == '0')
		ft_bzero((opt->out), OUT_SIZE);
	if (opt->out[0] == '-')
	{
		opt->is_positive = FALSE;
		ft_del_sim_in_str(opt->out, 1);
	}
	if (opt->a_have_dot && opt->a_dec > 0)
		tslaf(opt->out, msos((opt->a_dec - ft_strlen(opt->out)), '0'));
	if (opt->w_zero_dec && !(opt->a_have_dot) && (opt->f_plus || opt->f_space))
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out) - 1), '0'));
	else if (opt->w_zero_dec && !(opt->a_have_dot))
		tslaf(opt->out, msos((opt->w_dec - ft_strlen(opt->out)
			+ (opt->is_positive - 1)), '0'));
	play_with_decemal_ftn(opt);
}
