/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_d_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:26:25 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/02 14:44:30 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	play_with_decemal(va_list args, t_option *options) // transform in + - ' ' n 0n *
{
	int				res;
	char			*out;

	res = va_arg(args, int);
	out = ft_itoa(res);
	// if(options->f_hash)
	// 	flag_ne_tot();
	if (options->f_plus)
		if(out[0] != '-')
			out = ft_strjoin("+", out); //может  течь
	if (options->f_space)
		if(out[0] != '-')
			out = ft_strjoin(" ", out);
	if (options->f_minus)
		out = ft_strjoin(out, str_char_in(options->w_dec - ft_strlen(out), ' '));
	else if(options->w_zero_dec)
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), '0'), out);
	else
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), ' '), out);
	options->count += ft_strlen(out);
	ft_putstr(out);
}