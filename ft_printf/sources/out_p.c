/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:31:52 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/02 14:44:30 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libprint.h"

void	play_with_pointer(va_list args, t_option *options)
{
	char		*out;
	long int	*res;
	long int	j;

	res = va_arg(args, long int*);
	j = (long int)res;
	out = ft_strjoin("0x", ft_itoa_base(j, 16));
	// if (options->f_plus || options->w_zero_dec || options->f_hash)
	// 		flag_ne_tot();
	// if(options->f_space)
	// 		flag_ne_tot();
	// if(options->a_dec || options->a_star || options->a_have_dot)
	// 	flag_ne_tot();
	if (options->f_minus)
		out = ft_strjoin(out, str_char_in(options->w_dec - ft_strlen(out), ' '));
	else
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), ' '), out);
	options->count += ft_strlen(out);
	ft_putstr(out);
}
