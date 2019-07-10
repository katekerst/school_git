/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_xX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:28:48 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/09 19:29:52 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

char	*play_with_h_flags(va_list args, t_option *options, char **out)
{
	unsigned int	res;
	char			*copy;

	copy = *out;
	if (options->m_ll == TRUE || options->m_l == TRUE)
		copy = itoa_base_long(va_arg(args, long long int), 16);
	else
	{
		res = va_arg(args, unsigned int);
		if (options->m_hh == TRUE || options->m_h == TRUE)
		{
			if (options->m_h == TRUE)
				res = (unsigned short)res;
			else
				res = (unsigned char)res;
		}
		copy = ft_itoa_base(res, 16);
	}
	return (copy);
}

char	*play_with_hex(va_list args, t_option *options)
{
	char 			*out;

	out = play_with_h_flags(args, options, &out);

    if(options->a_have_dot && options->a_dec == 0 && out[0] == '0')
        {
            free(out);
            out = ft_strnew(2);
        }
    if (options->a_have_dot && options->a_dec > 0)
    {
        out = ft_strjoin(str_char_in((options->a_dec - ft_strlen(out)), '0'), out);
    }
    // if(options->f_hash)
    // {
	// 	if((out[0] && out[0] != '0') || (out[0] && options->a_dec != 0)) //привет норма проверка нулевого символа аута это out[0] != '\0'
    //         out = ft_strjoin("0x", out);
    // }

    if (options->f_minus)
		out = ft_strjoin(out, str_char_in(options->w_dec - ft_strlen(out), ' '));
	else if(options->w_zero_dec && !(options->a_have_dot) )
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), '0'), out);
	else
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), ' '), out);

	options->count += ft_strlen(out);
	return (out);
}

void	play_with_hex_big(va_list args, t_option *options)
{
	ft_putstr(ft_str_toupper(play_with_hex(args, options)));
}