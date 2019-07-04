/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:28:13 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/03 13:38:01 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

char	*play_with_u_flags(va_list args, t_option *options, char **out)
{
	unsigned int	res;
	char			*copy;

	copy = *out;
	if (options->m_ll == TRUE || options->m_l == TRUE)
		copy = itoa_unsigned(va_arg(args, unsigned long long));
	else
	{
		res = va_arg(args, unsigned int);
		if (options->m_hh == TRUE || options->m_h == TRUE)
		{
			if (options->m_h == TRUE)
				res = (unsigned short)res;
			else
				res = (unsigned short)((unsigned char)res);
		}
		copy = ft_itoa_base(res, 10);
	}
	return (copy);
}

void	play_with_unsigned_int(va_list args, t_option *options)
{
	char					*out;
	
	out = play_with_u_flags(args, options, &out);
	if (options->f_minus)
		out = ft_strjoin(out, str_char_in(options->w_dec - ft_strlen(out), ' '));
	else if(options->w_zero_dec)
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), '0'), out);
	else
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), ' '), out);
	options->count += ft_strlen(out);
	ft_putstr(out);
}