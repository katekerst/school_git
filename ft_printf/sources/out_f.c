/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:32:41 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/02 14:33:09 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void    trans_float(char const *outp, t_option *options)
{
    char *out;

    out = ft_strsub(outp, 0, ft_strlen(outp));
	if (options->f_plus)
		if(out[0] != '-')
			out = ft_strjoin("+", out); //может  течь
	if (options->f_space)
		if(out[0] != '-')
			out = ft_strjoin(" ", out);
    if (options->f_hash && options->a_dec == 0)
        out = ft_strjoin(out, ".");
	if (options->f_minus)
		out = ft_strjoin(out, str_char_in(options->w_dec - ft_strlen(out), ' '));
    else if(options->w_zero_dec)
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), '0'), out);
    else
		out = ft_strjoin(str_char_in((options->w_dec - ft_strlen(out)), ' '), out);
    options->count += ft_strlen(out);
		ft_putstr(out);
		ft_memdel((void**)&out);
}