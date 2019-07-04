/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_d_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:26:25 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/04 12:43:17 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

char	*play_with_d_flags(va_list args, t_option *options, char **out)
{
	int				res;
	char			*copy;

	copy = *out;
	if (options->m_ll == TRUE || options->m_l == TRUE)
		copy = itoa_base_long(va_arg(args, long long int), 10);
	else
	{
		res = va_arg(args, int);
		if (options->m_hh == TRUE || options->m_h == TRUE)
		{
			if (options->m_h == TRUE)
				res = (short)res;
			else
				res = (short)((signed char)res);
		}
		copy = ft_itoa(res);
	}
	return (copy);
}

void	play_with_decemal(va_list args, t_option *options) // transform in + - ' ' n 0n *
{
	char			*out;

	// if (va_arg(args, long long int) == 0)
	// {	
	// 	ft_putchar('0');
	// 	return ;
	// }
	out = play_with_d_flags(args, options, &out);
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