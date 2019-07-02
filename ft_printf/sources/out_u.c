/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:28:13 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/02 14:44:30 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	play_with_unsigned_int(va_list args, t_option *options)
{
	unsigned int	res;
	char			*out;

		res = va_arg(args, unsigned int);
	out = ft_itoa_base(res, 10);
	// if (options->f_plus)
	// 		flag_ne_tot();
	// if(options->f_space)
	// 		flag_ne_tot();
	if (options->f_minus)
		out = ft_strjoin(out, str_char_in(options->w_dec - ft_strlen(out), ' '));
	else if(options->w_zero_dec)
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), '0'), out);
	else
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), ' '), out);
	options->count += ft_strlen(out);
	ft_putstr(out);
}