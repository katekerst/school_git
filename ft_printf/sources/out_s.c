/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:29:24 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/21 19:01:15 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	play_with_string(va_list args, t_option *opt)
{
	char	*res;
	int		i;

	i = -1;
	res = va_arg(args, char*);
	if (res == NULL)
		res = "(null)";
	tsr(opt->out, res);
	if (opt->a_dec || opt->a_have_dot)
	{
		ft_bzero((opt->out), OUT_SIZE);
		while (++i < opt->a_dec)
			opt->out[i] = res[i];
	}
	if (opt->f_minus)
		tsraf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	else
		tslaf(opt->out, msos(opt->w_dec - ft_strlen(opt->out), ' '));
	opt->count += ft_strlen(opt->out);
	ft_putstr(opt->out);
}
