/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_d_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:26:25 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/09 19:18:04 by gbellege         ###   ########.fr       */
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
    int				qt;

	// if (va_arg(args, long long int) == 0)
	// {
	// 	ft_putchar('0');
	// 	return ;
	// }

	qt = 0;
	out = play_with_d_flags(args, options, &out);

	if(options->a_have_dot && options->a_dec == 0 && out[0] == '0')
        {
            free(out);
            out = ft_strnew(1);
        }


    if(out[0] == '-')
	{
		out++;
		qt++;
	}

    if (options->a_have_dot && options->a_dec > 0)
    {
        out = ft_strjoin(str_char_in((options->a_dec - ft_strlen(out)), '0'), out);
    }



	if(options->w_zero_dec && !(options->a_have_dot) && (options->f_plus || options->f_space))
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out) - 1), '0'), out);
	else if (options->w_zero_dec && !(options->a_have_dot))
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out) - qt), '0'), out);


	if (options->f_plus)
	{
		if(qt == 0)
			out = ft_strjoin("+", out);
		else
			out = ft_strjoin("-", out);
	}
	else if (options->f_space)
	{
		if(qt == 0)
			out = ft_strjoin(" ", out);
		else
			out = ft_strjoin("-", out);
	}
	else if (qt)
		out = ft_strjoin("-", out);


	if (options->f_minus)
		out = ft_strjoin(out, str_char_in(options->w_dec - ft_strlen(out), ' '));
	else if(!options->w_zero_dec || (options->a_have_dot))
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), ' '), out);

	options->count += ft_strlen(out);
	ft_putstr(out);
}