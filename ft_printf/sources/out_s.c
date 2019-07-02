/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:29:24 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/02 14:44:30 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	play_with_string(va_list args, t_option *options)
{
	char	*res;
	char	*out;
	int		i;

	i = -1;
	res = va_arg(args, char*);
	out = res;
	if(options->a_dec || options->a_have_dot)
	{
		out = ft_strnew(options->a_dec);
		while (++i < options->a_dec)
			out[i] = res[i];
	}
	// if (options->f_plus || options->f_space || options->f_hash)
	// 		flag_ne_tot();
	if (options->f_minus)
		out = ft_strjoin(out, str_char_in(options->w_dec - ft_strlen(out), ' '));
	// else if(options->w_zero_dec)
	// 	flag_ne_tot();
	else
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), ' '), out);
	options->count += ft_strlen(out);
	ft_putstr(out);
}